(function ($) {
  $(document).ready(function() {

    //Only number allowed
    $(".other").keyup(function(){
      parent_form = $(this).closest("FORM");
      $(this).val($(this).val().replace(/[^0-9]/g,""));
      if($(this).val() != ''){
        $('.donation-amount-selection label.checked').removeClass('checked');
        //Refresh amount value
        $('INPUT[type=hidden]',$(this).closest('.column')).val($(this).val());
      }
      //Refresh amount value
      else{
        $('.amount-holder',parent_form).val($(this).val());
      }
    })

    $('#recurring').click(function() {
      if($('#recurring').attr('checked')) {
        $('#form-cmd').val('_xclick-subscriptions');
      }
      else {
        $('#form-cmd').val('_donations');    
      }
    });

    //radio checking
    $('.donation-amount-selection label').click(function() {
      parent_form = $(this).closest("FORM");
      // Toggle class for current selection
      $('.donation-amount-selection label.checked').removeClass('checked');
      $(this).addClass('checked');
      // Fill
      $('.other',parent_form).val('');
      // Fill amount into holder
      $('.amount-holder',parent_form).val($('.donation-amount-selection label.checked input').val());
    });

    //When user click Donate now
    $(".donation-submit-button").click(function(){
      var post_form = false;

      //TODO
      //If any checkbox is checked set true
      if($('INPUT:radio:checked',$(this).closest('.donation-form')).length > 0)
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
