(function ($) {

/**
 * Attaches jQuery MultiSelect.
 */
Drupal.behaviors.mollomMultiSelect = {
  attach: function (context) {
    $(context).find('select[multiple]').chosen({
      width: '90%',
      // @see search-results.tpl.php
      no_results_text: Drupal.t('Your search yielded no results')
    });
  }
};

})(jQuery);
