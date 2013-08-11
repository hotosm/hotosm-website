<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * Ohm theme.
 */

/**
 * Check if a block is a menu block or not.
 *
 * @param $block
 *  A block object.
 * @return bool
 *  Given block is a menu block.
 */
function _ohm_is_menu_block($block) {
  return in_array($block->module, array('menu', 'menu_block')) || ($block->module == 'system' && !in_array($block->delta, array('help', 'powered-by', 'main')));
}
