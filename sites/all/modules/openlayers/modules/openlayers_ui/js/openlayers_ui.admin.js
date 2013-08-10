/**
 * @file
 * Javascript for OL UI Admin
 *
 * @ingroup openlayers
 */

// Namespace jQuery
(function ($) {

/**
 * Drupal behaviors for OpenLayers UI form.
 */
Drupal.behaviors.openlayers_ui_admin = {
  'attach': function(context, settings) {
    $('.openlayers-ui-version-check-message').once('openlayers-ui-version-check-message', function() {
      // Determine version
      var version = '0';
      var $thisContainer = $(this);

      if (typeof OpenLayers != 'undefined' && OpenLayers.hasOwnProperty('VERSION_NUMBER')) {
        version = OpenLayers.VERSION_NUMBER;
      }

      // Mark as loading, then do AJAX request
      $thisContainer.addClass('throbbing');
      var url = settings.basePath + '?q=admin/structure/openlayers/callbacks/version_check/' + version;
      $.ajax({
        url: url,
        success: function(data) {
          $thisContainer.removeClass('throbbing');
          $thisContainer.html(data.response);
          if (data.status == 'valid') {
            $thisContainer.parent()
              .removeClass('warning')
              .addClass('status');
          }
          else {
            $thisContainer.parent()
              .removeClass('status')
              .addClass('warning');
          }
        },
        error: function(data) {
          $thisContainer.removeClass('throbbing');
          $thisContainer.html(Drupal.t('Error making request to server.'));
        }
      });
    });
  }
};

})(jQuery);
