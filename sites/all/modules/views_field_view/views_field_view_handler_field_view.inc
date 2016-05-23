<?php

/**
 * @file
 * Views field view field handler class.
 */

class views_field_view_handler_field_view extends views_handler_field {
  /**
   * If query aggregation is used, all of the arguments for the child view.
   *
   * This is a multidimensional array containing field_aliases for the argument's
   * fields and containing a linear array of all of the results to be used as
   * arguments in various fields.
   */
  public $child_arguments = array();

  /**
   * If query aggregation is used, this attribute contains an array of the results
   * of the aggregated child views.
   */
  public $child_view_results = array();

  /**
   * If query aggregation is enabled, one instance of the child view to be reused.
   *
   * Note, it should never contain arguments or results because they will be
   * injected into it for rendering.
   */
  public $child_view = FALSE;

  /**
   * Stores a static cache of views. This will only cache views that contain no
   * arguments.
   *
   * @var array
   */
  protected $cached = array();

  /**
   * Disable this handler from being used as a 'group by'.
   */
  function use_group_by() {
    return FALSE;
  }

  /**
   * Disable this handler from being used as a 'group by' in style plugins.
   */
  function use_string_group_by() {
    return FALSE;
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['view'] = array('default' => '');
    $options['display'] = array('default' => 'default');
    $options['arguments'] = array('default' => '');
    $options['query_aggregation'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $view_options = views_get_views_as_options(TRUE, 'all', NULL, FALSE, TRUE);
    $form['views_field_view'] = array(
      '#type' => 'fieldset',
      '#title' => t("View settings"),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    $form['view'] = array(
      '#type' => 'select',
      '#title' => t('View'),
      '#description' => t('Select a view to embed.'),
      '#default_value' => $this->options['view'],
      '#options' => $view_options,
      '#ajax' => array(
        'path' => views_ui_build_form_url($form_state),
      ),
      '#submit' => array('views_ui_config_item_form_submit_temporary'),
      '#executes_submit_callback' => TRUE,
      '#fieldset' => 'views_field_view',
    );

    // If there is no view set, use the first one for now.
    if (count($view_options) && empty($this->options['view'])) {
      $keys = array_keys($view_options);
      $this->options['view'] = reset($keys);
    }

    if ($this->options['view']) {
      $view = views_get_view($this->options['view']);

      $display_options = array();
      foreach ($view->display as $name => $display) {
        // Allow to embed a different display as the current one.
        if ($this->options['view'] != $this->view->name || ($this->view->current_display != $name)) {
          $display_options[$name] = $display->display_title;
        }
      }

      $form['display'] = array(
        '#type' => 'select',
        '#title' => t('Display'),
        '#description' => t('Select a view display to use.'),
        '#default_value' => $this->options['display'],
        '#options' => $display_options,
        '#ajax' => array(
          'path' => views_ui_build_form_url($form_state),
        ),
        '#submit' => array('views_ui_config_item_form_submit_temporary'),
        '#executes_submit_callback' => TRUE,
        '#fieldset' => 'views_field_view',
      );

      // Provide a way to directly access the views edit link of the child view.
      // Don't show this link if the current view is the selected child view.
      if ($this->options['view'] && $this->options['display'] && ($this->view->name != $this->options['view'])) {
        // use t() here, and set HTML on #link options.
        $link_text = t('Edit "%view (@display)" view', array('%view' => $view_options[$this->options['view']], '@display' => $this->options['display']));
        $form['view_edit'] = array(
          '#type' => 'container',
          '#fieldset' => 'views_field_view',
        );
        $form['view_edit']['view_edit_link'] = array(
          '#theme' => 'link',
          '#text' => $link_text,
          '#path' => 'admin/structure/views/view/' . $this->options['view'] . '/edit/' . $this->options['display'],
          '#options' => array(
            'attributes' => array(
              'target' => '_blank',
              'class' => array('views-field-view-child-view-edit'),
            ),
            'html' => TRUE,
          ),
          '#attached' => array(
            'css' => array(
              drupal_get_path('module', 'views_field_view') . '/views_field_view.css',
            ),
          ),
          '#prefix' => '<span>[</span>',
          '#suffix' => '<span>]</span>',
        );
        $form['view_edit']['description'] = array(
          '#markup' => t('Use this link to open the current child view\'s edit page in a new window.'),
          '#prefix' => '<div class="description">',
          '#suffix' => '</div>',
        );
      }

      $form['arguments'] = array(
        '#title' => t('Contextual filters'),
        '#description' => t('Use a comma (,) or forwardslash (/) separated list of each contextual filter which should be forwared to the view. 
          See below list of available replacement tokens. Static values are also be passed to child views if they do not match a token format. 
          You could pass static ID\'s or taxonomy terms in this way. E.g. 123 or "my taxonomy term".'),
        '#type' => 'textfield',
        '#default_value' => $this->options['arguments'],
        '#fieldset' => 'views_field_view',
        '#maxlength' => '256',
      );
      $form['available_tokens'] = array(
        '#type' => 'fieldset',
        '#title' => t('Replacement patterns'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#value' => $this->get_token_info(),
        '#fieldset' => 'views_field_view',
      );

      // It doesn't make sense to allow aggregation unless it's a field handler.
      if (($this->handler_type == 'field')) {
        $form['query_aggregation'] = array(
          '#title' => t('Aggregate queries'),
          '#description' => t('Views Field View usually runs a separate query for each instance of this field on each row and that can mean a lot of queries.
            This option attempts to aggregate these queries into one query per instance of this field (regardless of how many rows are displayed).
            <strong>Currently child views must be configured to "Display all results for the specified field" if no contextual filter is present and
            query aggregation is enabled.</strong>. This may only work on simple views, please test thoroughly.'),
          '#type' => 'checkbox',
          '#default_value' => $this->options['query_aggregation'],
          '#fieldset' => 'views_field_view',
        );
      }

      // Ensure we're working with a SQL view.
      $views_data = views_fetch_data($view->base_table);
      if (isset($views_data['table']['base']['query class']) && $views_data['table']['base']['query class'] == 'views_query') {
        $form['query_aggregation']['#disabled'] = TRUE;
      }
    }

    $form['alter']['#access'] = FALSE;
  }

  function query() {
    $this->add_additional_fields();
  }

  /**
   * Run before any fields are rendered.
   *
   * This gives the handlers some time to set up before any handler has
   * been rendered.
   *
   * @param array $values
   *   An array of all objects returned from the query.
   */
  function pre_render(&$values) {
    // Only act if we are attempting to aggregate all of the field
    // instances into a single query.
    if ($this->options['view'] && $this->options['query_aggregation']) {
      // Note: Unlike render, pre_render will be run exactly once per
      // views_field_view field (not once for each row).
      $child_view_name = $this->options['view'];
      $child_view_display = $this->options['display'];

      // Add each argument token configured for this view_field.
      foreach ($this->split_tokens($this->options['arguments']) as $token) {
        // Remove the brackets around the token etc..
        $token_info = $this->get_token_argument($token);
        $argument = $token_info['arg'];
        $token_type = $token_info['type'];
        // Collect all of the values that we intend to use as arguments of our single query.
        // TODO: Get this to be handled by get_token_value() method too.
        if (isset($this->view->field[$argument])) {
          if (isset($this->view->field[$argument]->field_info)) {
            $field_alias = 'field_' . $this->view->field[$argument]->field;
            $field_key = key($this->view->field[$argument]->field_info['columns']);
          }
          elseif (isset($this->view->field[$argument]->field_alias)) {
            $field_alias = $this->view->field[$argument]->field_alias;
            $field_key = 'value';
          }

          foreach ($values as $value) {
            if (isset($value->$field_alias)) {
              $this->child_arguments[$field_alias]['argument_name'] = $field_alias;

              if (is_array($value->$field_alias)) {
                $field_values = array();

                foreach ($value->$field_alias as $field_item) {
                  switch ($token_type) {
                    case '%':
                      $field_values[] = $field_item['rendered']['#markup'];
                    break;
                    case '!':
                    default:
                      $field_values[] = $field_item['raw'][$field_key];
                  }
                }
                $field_value = (count($field_values) > 1) ? $field_values : reset($field_values);
                $this->child_arguments[$field_alias]['values'][] = $field_value;
              }
              else {
                $this->child_arguments[$field_alias]['values'][] = $value->$field_alias;
              }
            }
          }
        }
      }

      // If we don't have child arguments we should not try to do any of our magic.
      if (count($this->child_arguments)) {
        // Cache the child_view in this object to minize our calls to views_get_view.
        $this->child_view = views_get_view($child_view_name);
        $child_view = $this->child_view;
        // Set the appropriate display.
        $child_view->access($child_view_display);

        // Find the arguments on the child view that we're going to need if the
        // arguments have been overridden.
        foreach ($child_view->display['default']->display_options['arguments'] as $argument_name => $argument_value) {
          if (isset($child_view->display[$child_view_display]->display_options['arguments'][$argument_name])) {
            $configured_arguments[$argument_name] = $child_view->display[$child_view_display]->display_options['arguments'][$argument_name];
          }
          else {
            $configured_arguments[$argument_name] = $child_view->display['default']->display_options['arguments'][$argument_name];
          }
        }

        $argument_field_aliases = array();

        foreach ($this->child_arguments as $child_argument_name => $child_argument) {
          // Work with the arguments on the child view in the order they are
          // specified in our views_field_view field settings.
          $configured_argument = array_shift($configured_arguments);
          // To be able to later split up our results among the appropriate rows,
          // we need to add whatever argument fields we're using to the query.

          // Sadly the table and field from the argument does not always match
          // the corresponding field. One common usecase are fieldapi fields,
          // so let's special case them.
          $table_name = $configured_argument['table'];
          $table_field = $configured_argument['field'];
          $views_data = views_fetch_data($table_name);
          $argument_views_data = $views_data[$table_field];
          // This is the condition how we find out that we deal with a fieldapi
          // field.
          if (isset($argument_views_data['argument']['field_name'])) {
            $table_field = $argument_views_data['argument']['field_name'];
          }

          // We first the field, so we can ensure the table properly. Later we
          //
          $argument_field_id = $child_view->add_item($child_view_display, 'field', $table_name, $table_field, array('exclude' => TRUE));

          if (isset($child_view->pager['items_per_page'])) {
            $child_view->pager['items_per_page'] = 0;
          }

          $child_view->field[$argument_field_id]->definition['add fields to query'] = TRUE;

          $child_view->build();

          // Also add the field we want to use later to split the result up.
          $argument_field_aliases[$child_argument_name] = $child_view->query->add_field($configured_argument['table'], $configured_argument['field']);
          // Add the WHERE IN clause to this query.
          $child_view->query->add_where(0, $configured_argument['table'] . '.' . $configured_argument['field'], $child_argument['values']);
        }

        // Initialize the query object so that we have it to alter.
        // The child view may have been limited but our result set here should not be.
        $child_view->build_info['query'] = $child_view->query->query();
        $child_view->build_info['count_query'] = $child_view->query->query(TRUE);
        $child_view->build_info['query_args'] = $child_view->query->get_where_args();
        // Execute the query to retrieve the results.
        $child_view->execute();

        // Now that the query has run, we need to get the field alias for each argument field
        // so that it can be identified later.
        foreach ($argument_field_aliases as $child_argument_name => $argument_field_alias) {
          $child_alias = $argument_field_alias;

          $this->child_arguments[$child_argument_name]['child_view_field_alias'] = $child_alias;
        }
        $results = $child_view->result;

        // Finally: Cache the results so that they're easily accessible for the render function.
        // Loop through the results from the main view so that we can cache the results
        // relevant to each row.
        foreach ($values as $value) {
          // Add an element to the child_view_results array for each of the rows keyed by this view's base_field.
          $this->child_view_results[$value->{$this->view->base_field}] = array();
          $child_view_result_row =& $this->child_view_results[$value->{$this->view->base_field}];
          // Loop through the actual result set looking for matches to these arguments.
          foreach ($results as $result) {
            // Assume that we have a matching item until we know that we don't.
            $matching_item = TRUE;
            // Check each argument that we care about to ensure that it matches.
            foreach ($this->child_arguments as $child_argument_field_alias => $child_argument) {
              // If one of our arguments does not match the argument of this field,
              // do not add it to this row.
              if (isset($value->$child_argument_field_alias) && $value->$child_argument_field_alias != $result->{$child_argument['child_view_field_alias']}) {
                $matching_item = FALSE;
              }
            }
            if ($matching_item) {
              $child_view_result_row[] = $result;
            }
          }

          // Make a best effort attempt at paging.
          if (isset($this->child_view->pager['items_per_page'])) {
            $item_limit = $this->child_view->pager['items_per_page'];
            // If the item limit exists but is set to zero, do not split up the results.
            if ($item_limit != 0) {
              $results = array_chunk($results, $item_limit);
              $offset = (isset($this->child_view->pager['offset']) ? $this->child_view->pager['offset'] : 0);
              $results = $results[$offset];
            }
          }
          unset($child_view_result_row);
        }

        // We have essentially built and executed the child view member of this view.
        // Set it accordingly so that it is not rebuilt during the rendering of each row below.
        $this->child_view->built = TRUE;
        $this->child_view->executed = TRUE;
      }
    }
  }

  function render($values) {
    static $running = array();
    $output = NULL;

    // If it's not a field handler and there are no values
    // Get the first result row from the view and use that.
    if (($this->handler_type !== 'field') && empty($values) && isset($this->view->result)) {
      $values = reset($this->view->result);
    }

    if (empty($this->options['arguments']) && isset($this->cached[$this->options['view']][$this->options['display']])) {
      // If there are no arguments, and we already cached this view, then
      // our work here is done.
      $output = $this->cached[$this->options['view']][$this->options['display']];
    }
    // Protect against the evil / recursion. Set the variable for yourself, this
    // is not for the normal "user".
    elseif (empty($running[$this->options['view']][$this->options['display']]) || variable_get('views_field_view_evil', FALSE)) {
      if ($this->options['view'] && !$this->options['query_aggregation']) {
        $running[$this->options['view']][$this->options['display']] = TRUE;
        $args = array();

        // Only perform this loop if there are actually arguments present.
        if (!empty($this->options['arguments'])) {
          // Create array of tokens.
          foreach ($this->split_tokens($this->options['arguments']) as $token) {
            $args[] = $this->get_token_value($token, $values, $this->view);
          }
        }

        // get view etc… and execute.
        $view = views_get_view($this->options['view']);

        // Only execute and render the view if the user has access.
        if ($view->access($this->options['display'])) {
          $view->set_display($this->options['display']);

          if ($view->display_handler->use_pager()) {
            // Check whether the pager IDs should be rewritten.
            $view->init_query();
            // Find a proper start value for the ascening pager IDs.
            $start = 0;
            $pager = $view->display_handler->get_option('pager');
            if (isset($this->query->pager->options['id'])) {
              $start = (int) $this->query->pager->options['id'];
            }

            // Set the index at 1, as we will always want this to be atleast
            // 1 higher than the start ID.
            $index = 1;
            // Set the pager ID before initializing the pager, so
            // views_plugin_pager::set_current_page works as expected, which is
            // called from view::init_pager(). There wont always be a row_index
            // set so test for this.
            if (isset($this->view->row_index)) {
              $index += $this->view->row_index;
            }
            $pager['options']['id'] = $start + $index;
            $view->display_handler->set_option('pager', $pager);
            $view->init_pager();
          }

          $view->pre_execute($args);
          $view->execute();

          // If there are no results and hide_empty is set.
          if (empty($view->result) && $this->options['hide_empty']) {
            $output = '';
          }
          // Else just call render on the view object.
          else {
            $output = $view->render();
          }
        }

        $running[$this->options['view']][$this->options['display']] = FALSE;
      }
      // Verify we have a child view (if there were no arguments specified we
      // won't have one), and that query aggregation was enabled.
      elseif ($this->child_view && $this->options['view'] && $this->options['query_aggregation']) {
        $running[$this->options['view']][$this->options['display']] = TRUE;
        $child_view = $this->child_view;
        // Only execute and render the view if the user has access.
        if ($child_view->access($this->options['display'])) {
          $results =  $this->child_view_results[$values->{$this->view->base_field}];
          // If there are no results and hide_empty is set.
          if (empty($results) && $this->options['hide_empty']) {
            $output = '';
          }
          else {
            // Inject the appropriate result set before rendering the view.
            $child_view->result = $results;

            if (isset($child_view->style_plugin->rendered_fields)) {
              unset($child_view->style_plugin->rendered_fields);
            }

            $child_view->pre_execute();
            $output = $child_view->render();
          }

          $running[$this->options['view']][$this->options['display']] = FALSE;
        }
      }
    }
    else {
      $output = t('Recursion, stop!');
    }

    if (empty($this->options['arguments']) && !isset($this->cached[$this->options['view']][$this->options['display']])) {
      // If there are no arguments and no existing static cache then set a
      // static cache for this view.
      $this->cached[$this->options['view']][$this->options['display']] = $output;
    }

    // We only add the output to the $values object for field handlers. Area
    // handlers will not use this.
    if (($this->handler_type == 'field') && !empty($output)) {
      // Add the rendered output back to the $values object so it is available
      // in $view->result objects.
      $values->{'views_field_view_' . $this->options['id']} = $output;
    }

    return $output;
  }

  /**
   * Get field values from tokens.
   *
   * @param string $token
   *  token string. E.g. explode(',', $this->options['args']);
   * @param View $view
   *  Full view object to get token values from.
   *
   * @return array
   *  An array of raw argument values, returned in the same order as the token
   *  were passed in.
   */
  function get_token_value($token, $values, $view) {
    $token_info = $this->get_token_argument($token);
    $arg = $token_info['arg'];
    $token_type = $token_info['type'];

    // Collect all of the values that we intend to use as arguments of our single query.
    if (isset($view->field[$arg])) {
      switch ($token_type) {
        case '%':
          $value = $view->field[$arg]->last_render;
        break;
        case '!':
        default:
          $value = $view->field[$arg]->get_value($values);
        break;
      }
    }
    elseif (isset($view->args[$arg - 1])) {
      switch ($token_type) {
        case '%':
          // Get an array of argument keys. So we can use the index as an
          // identifier.
          $keys = array_keys($view->argument);
          $value = $view->argument[$keys[$arg - 1]]->get_title();
        break;
        case '!':
        default:
          $value = $view->args[$arg - 1];
        break;
      }
    }
    else {
      $value = check_plain(trim($token, '\'"'));
    }

    return $value;
  }

  /**
   * Return the argument type and raw argument from a token.
   * E.g. [!test_token] will return "array('type' => '!', 'arg' => test_token)".
   *
   * @param string $token
   *  A single token string.
   *
   * @return array
   *  An array containing type and arg (As described above).
   */
  function get_token_argument($token) {
    // Trim whitespace and remove the brackets around the token.
    $argument = trim(trim($token), '[]');
    $diff = ltrim($argument, '!..%');
    $token_type = '';

    if ($argument != $diff) {
      $token_type = $argument[0];
      // Make the new argument the diff (without token type character).
      $argument = $diff;
    }

    return array(
      'type' => $token_type,
      'arg' => $argument,
    );
  }

  /**
   * Returns array of tokens/values to be used in child views.
   * String containing tokens is split on either "," or "/" characters.
   *
   * @param string $token_string
   *   The string of tokens to split.
   *
   * @return array
   *   An array of split token strings.
   */
  function split_tokens($token_string) {
    return preg_split('/,|\//', $token_string);
  }

  /**
   * Get available field tokens, code/logic stolen from views_handler_field.inc.
   *
   * @return string
   *   A full HTML string, containing a list of available tokens.
   */
  public function get_token_info() {
    // Get a list of the available fields and arguments for token replacement.
    $options = array();

    foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
      $options[t('Fields')]["[!$field]"] = $handler->ui_name() . ' (' . t('raw') . ')';
      $options[t('Fields')]["[%$field]"] = $handler->ui_name() . ' (' . t('rendered') . ')';
      // We only use fields up to (and including) this one.
      if ($field == $this->options['id']) {
        break;
      }
    }

    // This lets us prepare the key as we want it printed.
    $count = 0;

    foreach ($this->view->display_handler->get_handlers('argument') as $arg => $handler) {
      $options[t('Arguments')]['%' . ++$count] = t('@argument title', array('@argument' => $handler->ui_name()));
      $options[t('Arguments')]['!' . $count] = t('@argument input', array('@argument' => $handler->ui_name()));
    }

    // Add replacements for query string parameters.
    foreach ($_GET as $param => $val) {
      if (is_array($val)) {
        $val = implode(', ', $val);
      }
      $options[t('Query string')]["[%$param]"] = strip_tags(decode_entities($val));
    }

    $this->document_self_tokens($options[t('Fields')]);

    // Default text.
    $output = '<p>' . t('You must add some additional fields to this display before using this field.
      These fields may be marked as <em>Exclude from display</em> if you prefer. Note that due to rendering order,
      you cannot use fields that come after this field; if you need a field not listed here, rearrange your fields.') . '</p>';

    // We have some options, so make a list.
    if (!empty($options)) {
      $output = '<p>' . t('The following tokens are available for this field. Note that due to rendering order,
        you cannot use fields that come after this field; if you need a field that is not listed here, re-arrange your fields.') . '</p>';

      foreach (array_keys($options) as $type) {
        if (!empty($options[$type])) {
          $items = array();
          foreach ($options[$type] as $key => $value) {
            $items[] = $key . ' == ' . $value;
          }
          $output .= theme('item_list',
            array(
              'items' => $items,
              'type' => $type
            ));
        }
      }
    }

    $output .= '<p><em>' . t('Using rendered (%) tokens can cause unexpected behaviour, as this will use the last output of the field.
      This could be re written output also. If no prefix is used in the token pattern, "!" will be used as a default.') . '</em></p>';

    return $output;
  }

} // views_field_view_handler_field_view.
