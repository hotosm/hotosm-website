(function ($) {

  Drupal.behaviors.proj4js = {
    attach: function (context, settings) {
      for (var i in settings.proj4js) {
        Proj4js.defs[settings.proj4js[i][0]] = settings.proj4js[i][1];
      }
    }
  };

})(jQuery);
