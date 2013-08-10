<?php

/**
 * @file
 * Classes implemented by the Variable API module.
 */

class Vars implements ArrayAccess {
  /**
   * The constants for the type of variable saved in the database.
   */
  const API_VERSION = '2.6';
  const VARS_DYNAMIC = 1;
  const VARS_NODE_TYPE = 3;

  protected $module;
  protected $sysVars = array();

  /**
   * Constructs a Vars object.
   *
   * @param $module
   *   The name of the module that implements the class.
   * @param $options
   *   An array of options. The currently defined option is 'sysVars', used to
   *   define the default values for variables defined from modules not using
   *   Variables API.
   */
  public function __construct($module = 'vars', array $options = array()) {
    $this->module = $module;

    if (!empty($options['sysVars'])) {
      $this->sysVars = $options['sysVars'];
    }

    $this->sysVars += array(
      'admin_theme' => NULL,
      'book_allowed_types' => array('book'),
      'book_child_type' => 'book',
      'cache' => 0,
      'cache_backends' => array(),
      'clean_url' => FALSE,
      'https' => FALSE,
      'install_profile' => 'default',
      'language_count' => 1,
      'language_default' => (object) array(
        'language' => 'en', 'name' => 'English', 'native' => 'English', 'direction' => 0,
        'enabled' => 1, 'plurals' => 0, 'formula' => '', 'domain' => '',
        'prefix' => '', 'weight' => 0, 'javascript' => ''
      ),
      'language_native_enabled' => TRUE,
      'lock_inc' => 'includes/lock.inc',
      'maintenance_mode' => 0,
      'menu_inc' => 'includes/menu.inc',
      'menu_masks' => array(),
      'menu_rebuild_needed' => FALSE,
      'node_admin_theme' => NULL,
      'page_cache_invoke_hooks' => TRUE,
      'page_cache_without_database' => FALSE,
      'path_inc' => 'includes/path.inc',
      'session_inc' => 'includes/session.inc',
      'site_frontpage' => 'node',
      'site_offline' => FALSE,
      'theme_default' => 'bartik',
    );
  }

  /**
   * Verifies the current API version is included between two values passed as
   * arguments.
   *
   * @param $minimum
   *   The minimum API version required.
   * @param $maximum
   *   The maximum version required. This argument is optional; the current API
   *   will be checked against this value only if it is passed to the function.
   * @return
   *   TRUE, if the current API version is included between the passed values.
   */
  static public function api($minimum, $maximum = NULL) {
    if (version_compare(self::API_VERSION, $minimum, '<')) {
      return FALSE;
    }

    if (isset($maximum) && version_compare(self::API_VERSION, $maximum, '>')) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Returns the default values for the variable passed as argument.
   *
   * Returns the default values for the variable passed as argument. It is used
   * to get the default value for variables defined in a module that doesn't
   * use the Variables API module.
   *
   * @param $name
   *   The name of the variable.
   * @return
   *   The default value for the variable, or NULL if it is not found.
   */
  protected function defaultValue($name) {
    return isset($this->sysVars[$name]) ? $this->sysVars[$name] : NULL;
  }

  /**
   * Deletes the specified persistent variables.
   *
   * Deletes the specified persistent variables from memory, and from the
   * database.
   *
   * @param $names
   *   An array of persistent variable names.
   *
   * @see Vars::renameVariables()
   */
  public static function deleteVariables(array $names) {
    global $conf;
    $count = 0;

    foreach ($names as $name) {
      unset($conf[$name]);
      $count++;
    }

    if ($count) {
      db_delete('variable')
        ->condition('name', $names, 'IN')
        ->execute();
      cache_clear_all('variables', 'cache_bootstrap');
    }
  }

  /**
   * Forces the menu rebuilding.
   */
  public function forceMenuRebuild() {
    if (!$this->offsetGet('menu_rebuild_needed')) {
      $this->offsetSet('menu_rebuild_needed', TRUE);
    }
  }

  /**
   * Returns the default value for the variables used by the module.
   *
   * A module using Variables API should normally implement a class derived
   * from Vars, and overwrite this method.
   *
   * @return
   *   An array containing information about the implemented persistent
   *   variables.
   *
   * @see Vars::saveDefaults()
   */
  protected function getDefaults() {
    return array();
  }

  /**
   * Returns the list of the directories where library files are looked in.
   *
   * @param $library
   *   The library to look for. This parameter will be used as directory name.
   * @param $options
   *   An array of extra options.
   * @return
   *   An array of directories where the library can be found.
   */
  public function getLibraryPath($library, array $options = array()) {
    $config = conf_path();
    $id = preg_replace('/[^a-z0-9_]/i', '_', $library);
    $path = &self::staticValue("vars_library_path_$id", array());

    if ($path) {
      return $path;
    }

    $dirs = array(
      'profiles/' . drupal_get_profile() . "/libraries/$library",
      "sites/all/libraries/$library",
      "$config/libraries",
    );

    // Allow third-party modules to alter the list of directories where
    // Variables API looks for the directory $library.
    $context = array('library' => $library);

    if (!empty($options['files'])) {
      $context['files'] = (is_array($options['files']) ? $options['files'] : array($options['files']));
    }
    else {
      $context['files'] = array();
    }

    drupal_alter(
      array('vars_library_search_directories', "vars_library_{$id}_search_directories"), $dirs, $context
    );

    foreach ($dirs as $dir) {
      $function = (preg_match('#^https?://#i', $dir) ? '_vars_check_remote_directory' : '_var_check_locale_directory');
      if ($function($dir, $context['files'])) {
        $path[] = $dir;
      }
    }

    return $path;
  }

  /**
   * Loads the default value for all the variables respecting some conditions.
   *
   * This function is used to load the default value for all the variables
   * respecting some conditions. The function should not be called from
   * modules; it's thought to be used only from the Variables API module.
   *
   * @param $cid
   *   The cache ID of the data to retrieve.
   * @param $conditions
   *   A DatabaseCondition object for the conditions the persistent variables
   *   must respect.
   * @return
   *   An array containing information about the default value for the
   *   persistent variables.
   *
   * @see vars_node_type()
   */
  public static function loadDefaults($cid, DatabaseCondition $conditions = NULL) {
    if ($cache = cache_get($cid, 'cache_vars')) {
      return $cache->data;
    }

    if ($cid == 'node_type') {
      $conditions = db_and()->condition('vd.flags', Vars::VARS_NODE_TYPE);
    }

    $defaults = array();
    $query = db_select('variable_default', 'vd')->fields('vd', array('name', 'value', 'flags'));

    if (isset($conditions)) {
      $query->condition($conditions);
    }

    foreach ($query->execute() as $var) {
      $index = $var->flags ? 'dynamic' : 'static';
      $defaults[$index][$var->name] = unserialize($var->value);
    }

    drupal_alter('vars_default_values', $defaults, $cid);
    cache_set($cid, $defaults, 'cache_vars');

    return $defaults;
  }

  /**
   * Implements ArrayAccess::offsetExists().
   */
  public function offsetExists($offset) {
    $value = $this->offsetGet($offset);

    return isset($value);
  }

  /**
   * Implements ArrayAccess::offsetGet().
   */
  public function offsetGet($offset) {
    global $conf;

    if (isset($conf[$offset])) {
      return $conf[$offset];
    }

    $value = $this->defaultValue($offset);
    if (isset($value)) {
      return $value;
    }

    $defaults = &$this->staticValue('vars_default_values', array());
    if (isset($defaults['static'][$offset])) {
      return $defaults['static'][$offset];
    }

    if (!empty($defaults['dynamic'])) {
      foreach ($defaults['dynamic'] as $var => $value) {
        if (strpos($offset, $var . '_') === 0) {
          $defaults['static'][$offset] = $value;
          return $value;
        }
      }
    }

    $module = db_query_range(
      "SELECT module FROM {variable_default} WHERE (name = :name OR (:offset LIKE CONCAT(name, '\_%')) AND flags > 0)",
      0, 1,
      array(':name' => $offset, ':offset' => $offset))
      ->fetchField();
    if (!$module) {
      return NULL;
    }

    $vars = self::loadDefaults(
      "module:$module",
      db_and()->condition('vd.module', $module)
    );
    if (!empty($vars)) {
      $defaults['static'] = array_merge(empty($defaults['static']) ? array() : $defaults['static'], empty($vars['static']) ? array() : $vars['static']);
      $defaults['dynamic'] = array_merge(empty($defaults['dynamic']) ? array() : $defaults['dynamic'], empty($vars['dynamic']) ? array() : $vars['dynamic']);
      if (isset($defaults['static'][$offset])) {
        return $defaults['static'][$offset];
      }

      if (!empty($defaults['dynamic'])) {
        foreach ($defaults['dynamic'] as $var => $value) {
          if (strpos($offset, $var) === 0) {
            $defaults['static'][$offset] = $value;
            return $value;
          }
        }
      }
    }
  }

  /**
   * Implements ArrayAccess::offsetSet().
   */
  public function offsetSet($offset, $value) {
    if (!empty($offset)) {
      variable_set($offset, $value);
    }
  }

  /**
   * Implements ArrayAccess::offsetUnset().
   */
  public function offsetUnset($offset) {
    $this->deleteVariables(array($offset));
  }

  /**
   * Removes the default values contained in the table variable_default.
   *
   * Remove the default values that are contained in the database table
   * created by the Variables API module. The function should be called from
   * the implementations of hook_uninstall(), or hook_update_N().
   *
   * This method is deprecated. Variable API will automatically remove the default
   * values from its database table, once the modules are uninstalled.
   *
   * @param $set
   *   An optional array of variables to remove. If the parameter is not
   *   passed, the function will remove all the variables defined from the
   *   module.
   *   The variables are also removed from memory, and from the table of
   *   persistent variables used by Drupal core.
   *
   * @see Vars::saveDefaults()
   */
  public function removeDefaults(array $set = array()) {}

  /**
   * Renames persistent variables.
   *
   * Renames the persistent variables whose name matched the passed argument.
   * The variables are renamed in memory, and in the database table used by
   * Drupal core code.
   *
   * @param $names
   *   A array whose keys are the names of the variables to rename, and the
   *   values are the new names to give to the persistent variables.
   *
   * @see Vars::deleteVariables()
   */
  public static function renameVariables(array $names) {
    global $conf;
    $count = 0;

    foreach ($names as $old_name => $new_name) {
      if (isset($conf[$old_name])) {
        $conf[$new_name] = $conf[$old_name];

        db_merge('variable')
          ->key(array('name' => $new_name))
          ->fields(array('value' => serialize($conf[$old_name])))
          ->execute();
        unset($conf[$old_name]);
        $count++;
      }
    }

    if ($count) {
      db_delete('variable')
        ->condition('name', array_keys($names), 'IN')
        ->execute();
      cache_clear_all('variables', 'cache_bootstrap');
    }
  }

  /**
   * Saves the default value for the variables defined from the module.
   *
   * Saves the default values for the variables defined from the module
   * implementing a subclass of Vars.
   * The function should be called from the implementations of hook_install(),
   * or hook_update_N().
   */
  public function saveDefaults() {
    $vars = $this->getDefaults();
    if (!empty($vars) && is_array($vars)) {
      foreach ($vars as $name => $info) {
        if (!is_array($info)) {
          $info = array('value' => $info);
        }
        $info += array('value' => '', 'flags' => 0);

        try {
          db_merge('variable_default')
            ->key(array(
              'module' => $this->module,
              'name' => $name
            ))
            ->fields(array(
              'value' => serialize($info['value']),
              'flags' => $info['flags'],
            ))
            ->execute();
        }
        catch (Exception $e) {}

        $clear_cache = TRUE;
      }

      if (isset($clear_cache)) {
        cache_clear_all('variables', 'cache_bootstrap');
        cache_clear_all('module:' . $this->module, 'cache_vars');
        $this->staticReset('vars_default_values');
      }
    }
  }

  /**
   * Checks if the site is offline.
   *
   * @return
   * TRUE if the site is offline.
   */
  function siteIsOffline() {
    return (boolean) $this->offsetGet('maintenance_mode');
  }

  /**
   * Resets one or all centrally stored static variable(s).
   *
   * This static method is provided for compatibility with code using Drupal 6;
   * code for Drupal 7 should use the function provided by Drupal.
   *
   * @param $name
   *   Name of the static variable to reset. Omit to reset all variables.
   */
  public static function staticReset($name = NULL) {
    drupal_static($name, NULL, TRUE);
  }

  /**
   * Central static variable storage.
   *
   * This static method is provided for compatibility with code using Drupal 6;
   * code for Drupal 7 should use the function provided by Drupal.
   *
   * @param $name
   *   Globally unique name for the variable. For a function with only one
   *   static variable, the function name (e.g. via the PHP magic
   *   __FUNCTION__ constant) is recommended. For a function with multiple
   *   static variables add a distinguishing suffix to the function name for
   *   each one.
   * @param $default_value
   *   Optional default value.
   * @param $reset
   *   TRUE to reset a specific named variable, or all variables if $name is
   *   NULL.
   *   Resetting every variable should only be used, for example, for running
   *   unit tests with a clean environment. Should be used only though via
   *   function vars_static_reset() and the return value should not be used in
   *   this case.
   * @return
   *   Returns a variable by reference.
   */
  public static function &staticValue($name, $default_value = NULL, $reset = FALSE) {
    return drupal_static($name, $default_value, $reset);
  }
}

