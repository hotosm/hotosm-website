<?php
/**
 * @file
 * Provide the HTML output for the CAPTCHA image display.
 *
 * Available variables:
 * - $captcha_url:  The CAPTCHA image to present based
 * - $audio_enabled: boolean indicates if audio CAPTCHAs are enabled
 *   for this site.
 */

$switch_verify = $audio_enabled ? t('Switch to audio verification') : '';
$instructions = t("Type the characters you see in the picture; if you can't read them, submit the form and a new image will be generated. Not case sensitive.");
$image_alt_text = t('Type the characters you see in this picture.');
?>

<?php
  $captcha_output = theme('image', array('path' => $captcha_url, 'alt' => $image_alt_text, 'getsize' => FALSE));
?>
<span class="mollom-captcha-content mollom-image-captcha"><?php print $captcha_output; ?></span>
<div class="mollom-image-captcha-instructions"><?php print $instructions; ?><?php if ($audio_enabled) { ?>&nbsp;&nbsp;<a href="#" class="mollom-switch-captcha mollom-audio-captcha"><?php print $switch_verify; ?></a>.<?php } ?></div>
