<?php
/**
 * @file
 * Handling the PayPal IPN callbacks
 */

/**
 * IPN callback function().
 */
function paypal_donations__ipn_callback() {
  $paypal_host = variable_get('paypal_donations_service_url', 'www.sandbox.paypal.com');
  header("Content-type: text/html");
  header("Expires: Wed, 29 Jan 1975 04:15:00 GMT");
  header("Last-Modified: " . gmdate("D, d M Y H:i:s") . " GMT");
  header("Cache-Control: no-cache, must-revalidate");
  header("Pragma: no-cache");

  // Read the post from PayPal system and add 'cmd'.
  $req = 'cmd=_notify-validate';

  foreach ($_POST as $key => $value) {
    $value = urlencode(stripslashes($value));
    $req .= "&$key=$value";
  }

  $header = '';

  // Post back to PayPal system to validate.
  $header .= "POST /cgi-bin/webscr HTTP/1.0\r\n";
  $header .= "Host: " . $paypal_host . "\r\n";
  $header .= "Content-Type: application/x-www-form-urlencoded\r\n";
  $header .= "Content-Length: " . strlen($req) . "\r\n\r\n";

  $fp = fsockopen('ssl://' . $paypal_host, 443, $errno, $errstr, 30);

  if (!$fp) {
    watchdog('paypal', 'HTTP error');
  }
  else {
    fwrite($fp, $header . $req);
    watchdog('paypal', $header . $req);

    while (!feof($fp)) {
      $res = fgets($fp, 1024);
      if (strcmp($res, "VERIFIED") == 0) {
        global $user;

        if (!empty($_POST['txn_id'])) {

          if ($_POST['txn_type'] == 'web_accept') {
            $donation_type = 'single';
          }
          elseif ($_POST['txn_type'] == 'subscr_payment') {
            $donation_type = 'recurring';
          }

          $entity = new stdClass();
          $entity->field_paypal_transaction_id[LANGUAGE_NONE][0]['value'] = $_POST['txn_id'];
          $entity->field_paypal_donator_email[LANGUAGE_NONE][0]['value'] = $_POST['payer_email'];
          $entity->field_paypal_donations_amount[LANGUAGE_NONE][0]['value'] = $_POST['mc_gross'];
          $entity->field_paypal_donator_name[LANGUAGE_NONE][0]['value'] = $_POST['first_name'] . " " . $_POST['last_name'];
          $entity->field_paypal_donator_country[LANGUAGE_NONE][0]['value'] = $_POST['address_country'];
          $entity->field_paypal_donations_type[LANGUAGE_NONE][0]['value'] = $donation_type;
          $entity->created = time();

          entity_save('paypal_donations_item', $entity);

          module_invoke_all("paypal_donations_made", $entity, $_POST);
          watchdog('paypal', 'Paypal payment received with transaction id @txn_id.', array('@txn_id' => $_POST['txn_id']), WATCHDOG_NOTICE);

          drupal_mail('paypal_donations', 'payer_confirmation', $_POST['payer_email'], user_preferred_language($user), array(
            'first_name' => $_POST['first_name'],
            'amount' => $_POST['mc_gross'],
            'donation_type' => $donation_type,
          ));

          drupal_mail('paypal_donations', 'admin_confirmation', $_POST['receiver_email'], user_preferred_language($user), array(
            'name' => $_POST['first_name'] . " " . $_POST['last_name'],
            'amount' => $_POST['mc_gross'],
          ));
          }
        }
      }
    fclose ($fp);
  }

  die();
}
