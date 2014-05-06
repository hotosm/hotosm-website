(function ($) {
Drupal.behaviors.lang_dropdown = {
  attach: function (context, settings) {
    var settings = settings || Drupal.settings;

    if (settings.lang_dropdown) {
      var flags, msddSettings;
      for (key in settings.lang_dropdown) {
        msddSettings = settings.lang_dropdown[key].jsWidget;
        flags = msddSettings.languageicons;
        if (flags) {
          $.each(flags, function(index, value) {
            if (msddSettings.widget == "msdropdown") {
              $('select#lang-dropdown-select-' + key + ' option[value="' + index + '"]').attr('data-image', value);
            }
            else if (msddSettings.widget == "ddslick" && Boolean(msddSettings.showSelectedHTML)) {
              $('select#lang-dropdown-select-' + key + ' option[value="' + index + '"]').attr('data-imagesrc', value);
            }
          });
        }

        if (msddSettings.widget == "msdropdown") {
          try {
            $('select#lang-dropdown-select-' + key).msDropDown({
              visibleRows: msddSettings.visibleRows,
              roundedCorner: Boolean(msddSettings.roundedCorner),
              animStyle: msddSettings.animStyle,
              event: msddSettings.event,
              mainCSS: msddSettings.mainCSS
            });
          }
          catch (e) {
            if (console) { console.log(e); }
          }
        }
        else if (msddSettings.widget == "chosen") {
          $('select#lang-dropdown-select-' + key).chosen({
            disable_search: msddSettings.disable_search,
            no_results_text: msddSettings.no_results_text
          });
        }
        else if (msddSettings.widget == "ddslick") {
          $.data(document.body, 'ddslick'+key+'flag', 0);
          $('select#lang-dropdown-select-' + key).ddslick({
            width: msddSettings.width,
            height: (msddSettings.height == 0) ? null : msddSettings.height,
            showSelectedHTML: Boolean(msddSettings.showSelectedHTML),
            imagePosition: msddSettings.imagePosition,
            onSelected: function(data) {
              var i = $.data(document.body, 'ddslick'+key+'flag');
              if (i) {
                $.data(document.body, 'ddslick'+key+'flag', 0);
                var lang = data.selectedData.value;
                var href = $('#lang-dropdown-select-'+key).parents('form').find('input[name="' + lang + '"]').val();
                window.location.href = href;
              }
              $.data(document.body, 'ddslick'+key+'flag', 1);
            }
          });
        }
      }
    }

    $('select.lang-dropdown-select-element').change(function() {
      var lang = this.options[this.selectedIndex].value;
      var href = $(this).parents('form').find('input[name="' + lang + '"]').val();
      window.location.href = href;
    });

    $('form.lang-dropdown-form').after('<div style="clear:both;"></div>');
  }
};
})(jQuery);
