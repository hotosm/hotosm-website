(function ($) {
  
  Drupal.behaviors.addtoany = {
    attach: function(context, settings) {
    
      
      // Initial page setup
      
      var addtoany_icon = $('input[value="a2a_svg_32"]').next('label').find('img:first'),
        initial_icon_size_int = parseInt( $('input[name="addtoany_buttons_size"]:checked').val() );
      
      // Set the A2A icon's size to match selected Icon Size
      addtoany_icon.height(initial_icon_size_int).width(initial_icon_size_int);
      
      
      // Bring attention to large A2A icon option
      // because the universal button will likely be changed to match the other icons
      // (Drupal #states can't handle this)
      $('input[name="addtoany_buttons_size"]').change(function() {
      
      	var icon_size = $(this).val(),
      	  icon_size_int = parseInt(icon_size);
        
        // Expand Universal Button fieldset if collapsed
        if ( $('#edit-universal-button').is('.collapsed') )
          Drupal.toggleFieldset('#edit-universal-button');
        
        // Flash the A2A icon if not selected, because it should be selected to match the other icons
        if ( icon_size == '32' && ! $('input[value="a2a_svg_32"]').is(':checked') )
          addtoany_icon.fadeTo('fast', .2).fadeTo('fast', 1).fadeTo('fast', .2).fadeTo('fast', 1);
        
        // Set the A2A icon's size to match selected Icon Size
        addtoany_icon.height(icon_size_int).width(icon_size_int);
        
      });
      
      
    }
  };

}(jQuery));