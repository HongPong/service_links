<?php

/**
 * @file
 * Various examples to overwrite the theme settings.
 *
 * For a simply replacement of your link list, just put the string:
 * <?php print $service_links_rendered; ?>
 * in your file 'node.tpl.php' and disable the other visualization options 
 * under the configuration page.
 *
 * If you need other transformation add 'template.php' under your theme folder
 * either integrate the functions below in your 'template.php' replacing 'themename'
 * with the name of your theme, clean the cache if some changes are not well updated.
 *
 * More examples are available on the online help.
 */

/**
 * Example 1: Creating the variable '$service_links_rendered' 
 * for the template file 'page.tpl.php' containing all the
 * selected services.
 */
function themename_preprocess_page(&$vars) {
  if (\Drupal::moduleHandler()->moduleExists('service_links')) {
    // Works also for not-node pages
    if (\Drupal::currentUser()->hasPermission('access service links') && service_links_show($vars['node'])) {
      // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// $vars['service_links_rendered'] = theme('links', array('links' => service_links_render($vars['node'])));

    }
  }
}

/**
 * Example 2: Creating the variable '$twitter' for the template file
 * 'node.tpl.php' containing the services specified by their ids
 * (i.e. twitter).
 */
function themename_preprocess_node(&$vars) {
  if (\Drupal::moduleHandler()->moduleExists('service_links')) {
    if (\Drupal::currentUser()->hasPermission('access service links') && service_links_show($vars['node'])) {
      // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// $vars['twitter'] = theme('links', array('links' => service_links_render_some('twitter', $vars['node'])));

    }
  }  
}

/**
 * If something doesn't work well try this.
 */
function themename_preprocess(&$vars, $hook) {
  switch ($hook) {
    case 'node':
      if (\Drupal::moduleHandler()->moduleExists('service_links')) {
        if (\Drupal::currentUser()->hasPermission('access service links') && service_links_show($vars['node'])) {
          // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// $vars['twitter'] = theme('links', array('links' => service_links_render_some('twitter', $vars['node'])));

        }
      }
      break;
    case 'page':
      if (\Drupal::moduleHandler()->moduleExists('service_links')) {
        if (\Drupal::currentUser()->hasPermission('access service links') && service_links_show($vars['node'])) {
          // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// $vars['service_links'] = theme('links', array('links' => service_links_render($vars['node'])));

        }
      }
      break;
  }
}
