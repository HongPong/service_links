<?php

/**
 * @file
 * A handler to provide a service links field for a particular node.
 *
 * @ingroup views_field_handlers
 */
class service_links_handler_field_service_links extends views_handler_field {
  function construct() {
    parent::construct();
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function option_definition() {
    $options = parent::option_definition();

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Remove the alteration stuff
    unset($form['alter']);
  }

  function render($values) {
    if (isset($values->_field_data['nid']['entity'])) {
      $node = $values->_field_data['nid']['entity'];
    }
    else {
      $node = NULL;
    }

    // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// return theme('links', array('links' => service_links_render($node, TRUE)));

  }
}
