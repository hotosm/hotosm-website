(function ($) {

  Drupal.behaviors.addtoany = {
    attach: function(context, settings) {


      // Initial page setup

      var addtoany_icon = $('input[value="a2a_svg_32"]').next('label').find('img:first'),
        initial_icon_size_int = parseInt( $('input[name="addtoany_buttons_size"]').val() );

      // Set the A2A icon's size to match selected Icon Size
      addtoany_icon.height(initial_icon_size_int).width(initial_icon_size_int);


      // Bring attention to large A2A icon option
      // because the universal button will likely be changed to match the other icons
      // (Drupal #states can't handle this)
      $('input[name="addtoany_buttons_size"]').change(function() {

      	var icon_size = $(this).val(),
      	  icon_size_int = parseInt(icon_size);

        // If icon size is the classic 16 pixels, and the modern A2A icon is not checked
        if ( icon_size != '16' && ! $('input[value="a2a_svg_32"]').is(':checked') ) {

          // Expand Universal Button fieldset if collapsed
          if ( $('#edit-universal-button').is('.collapsed') )
            Drupal.toggleFieldset('#edit-universal-button');

          // Flash the A2A icon if not selected, because it should be selected to match the other icons
          addtoany_icon.fadeTo('fast', .2).fadeTo('fast', 1).fadeTo('fast', .2).fadeTo('fast', 1);

          // Set the A2A icon's size to match selected Icon Size
          addtoany_icon.height(icon_size_int).width(icon_size_int);

        }

      });


    }
  };

}(jQuery));