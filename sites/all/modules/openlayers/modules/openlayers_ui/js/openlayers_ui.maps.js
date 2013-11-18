
/**
 * @file
 * This file holds the javascript functions for the map UI
 *
 * @ingroup openlayers
 */

/**
 * Test whether function exists,
 * even if it is the child of another object
 * @param head the function name as a string,
 *  optionally with dots for invoking children
 * @return bool true or false for existence
 */
function function_exists(head) {
  return _function_exists(head.split('.'), window);
}

function _function_exists(head, f) {
  if (head.length == 0) {
    return true;
  }
  h = head.shift();
  if (typeof f[h] !== 'undefined') {
    return _function_exists(head, f[h]);
  }
  else {
    return false;
  }
}

(function ($) {
/**
 * Drupal behaviors for OpenLayers UI form.
 */
Drupal.behaviors.openlayers_ui = {
  'attach': function(context, settings) {

    // mark openlayers dependencies as valid or invalid
    $('.openlayers-dependency-flag').each(function() {
      if (!function_exists($(this).find('.openlayers-dependency-value').text())) {
        $(this).find('.openlayers-dependency-broken').show();
      }
    });

    // Since CTools dependency is not working
    $('#edit-behaviors:not(.openlayers-behaviors-checks-processed)').each(function () {
      $('#edit-behaviors').addClass('openlayers-behaviors-checks-processed');
      $('#edit-behaviors table tbody tr td > div.form-type-checkbox').each(function () {
        var $thisBehavior = $(this);
        var $thisCheck = $('input[type=checkbox]', $thisBehavior);

        if ($thisCheck.attr('checked')) {
          $thisBehavior.siblings().show();
        }
        else {
          $thisBehavior.siblings().hide();
        }

        $thisCheck.click(function() {
          if ($thisCheck.attr('checked')) {
            $thisBehavior.siblings().show();
          }
          else {
            $thisBehavior.siblings().hide();
          }
        });

      });
    });
  }
};

})(jQuery);
