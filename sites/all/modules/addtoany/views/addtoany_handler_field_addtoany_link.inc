<?php

/**
 * @file
 * Views field handler for the AddToAny link field
 */

/**
 * Field handler to present AddToAny links.
 */
class addtoany_handler_field_addtoany_link extends views_handler_field_node_link {
  function render($values) {
    if (($entity = $this->get_value($values)) && node_access('view', $entity)) {
      return _addtoany_create_button($entity);
    }
  }
}
