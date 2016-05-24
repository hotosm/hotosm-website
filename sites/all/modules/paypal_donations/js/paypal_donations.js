(function ($) {
  $(document).ready(function() {

    //Only number allowed
    $(".other").keyup(function(){
      parent_form = $(this).closest("FORM");
      $(this).val($(this).val().replace(/[^0-9]/g,""));
      if($(this).val() != ''){
        $('.donation-amount',$(this).closest('.column')).filter(':checked').removeAttr('checked');
        //Refresh amount value
        $('INPUT[type=hidden]',$(this).closest('.column')).val($(this).val());
      }
      //Refresh amount value
      else{
        $('.amount-holder',parent_form).val($(this).val());
      }
    })

    //Checkbox checking
    $('.donation-amount').click(function() {
      parent_form = $(this).closest("FORM");
      $('.donation-amount',$(this).closest('.column')).filter(':checked').not(this).removeAttr('checked');
      $('INPUT[type=text]',$(this).closest('.column')).val('');
      //Refresh amount value
      if($('INPUT:checkbox:checked',$(this).closest('.column')).length > 0){
        $('.amount-holder',parent_form).val($(this).val());
      }
      else{
        $('.amount-holder',parent_form).val('');
      }
    });

    //When user click Donate now
    $(".donation-submit-button").click(function(){
      var post_form = false;
      //If any checkbox is checked set true
      if($('INPUT:checkbox:checked',$(this).closest('.donation-form')).length > 0)
        post_form = true;
        
      //If Other has value set true
      if($('INPUT:text',$(this).closest('.donation-form')).val() != '')
        post_form = true;
      
      if(post_form){
        $(this).closest('.donation-form').submit();
      }
      else{
        alert(Drupal.t('Please enter your donation amount'));
      }
    })
  })
})(jQuery);
