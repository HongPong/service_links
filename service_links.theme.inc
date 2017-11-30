<?php

/**
 * @file
 * Theme function used by Service Links.
 */

/**
 * Build a single link following the style rules.
 */
function theme_service_links_build_link($variables) {
  $text = $variables['text'];
  $url = $variables['url'];
  $image = $variables['image'];
  $nodelink = $variables['nodelink'];
  $style = $variables['style'];
  $attributes = $variables['attributes'];

  if ($nodelink) {
    $query = isset($url[1]) ? $url[1] : NULL;
 
    switch ($style) {
      case SERVICE_LINKS_STYLE_TEXT:
        $link = array(
          'title' => $text,
          'href' => $url[0],
          'query' => $query,
          'attributes' => $attributes,
        );
        break;
      case SERVICE_LINKS_STYLE_IMAGE:
        $alt_text = t('!name logo', array('!name' => $text));
        // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// $link = array(
//           'title' => theme('image', array('path' => service_links_expand_path($image), 'alt' => $alt_text)),
//           'href' => $url[0],
//           'query' => $query,
//           'attributes' => $attributes,
//           'html' => TRUE,
//         );

        break;
      case SERVICE_LINKS_STYLE_IMAGE_AND_TEXT:
        $alt_text = t('!name logo', array('!name' => $text));
        // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// $link = array(
//           'title' => theme('image', array('path' => service_links_expand_path($image), 'alt' => $alt_text)) .' '. $text,
//           'href' => $url[0],
//           'query' => $query,
//           'attributes' => $attributes,
//           'html' => TRUE,
//         );

        break;
      case SERVICE_LINKS_STYLE_EMPTY:
        $link = array(
          'title' => '<span class="element-invisible">' . $text . '</span>',
          'href' => $url[0],
          'query' => $query,
          'attributes' => $attributes,
          'html' => TRUE,
        );
        break;
      default:
        // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// $link = theme($style, $variables);

    }
  }
  else {
    $attributes = array('attributes' => $attributes);
    if (isset($url[1])) {
      $attributes['query'] = $url[1];
    }

    switch ($style) {
      case SERVICE_LINKS_STYLE_TEXT:
        // @FIXME
// l() expects a Url object, created from a route name or external URI.
// $link = l($text, $url[0], $attributes);

        break;
      case SERVICE_LINKS_STYLE_IMAGE:
        $attributes['html'] = TRUE;
        $alt_text = t('!name logo', array('!name' => $text));
        // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// $link = l(theme('image', array('path' => service_links_expand_path($image), 'alt' => $alt_text)), $url[0], $attributes);

        break;
      case SERVICE_LINKS_STYLE_IMAGE_AND_TEXT:
        $attributes['html'] = TRUE;
        $alt_text = t('!name logo', array('!name' => $text));
        // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// $link = l(theme('image', array('path' => service_links_expand_path($image), 'alt' => $alt_text)) .' '. $text, $url[0], $attributes);

        break;
      case SERVICE_LINKS_STYLE_EMPTY:
        $attributes['html'] = TRUE;
        // @FIXME
// l() expects a Url object, created from a route name or external URI.
// $link = l('<span class="element-invisible">' . $text . '</span>', $url[0], $attributes);

        break;
      case SERVICE_LINKS_STYLE_FISHEYE:
        $attributes['attributes']['class'] = isset($attributes['attributes']['class']) ? array_merge($attributes['attributes']['class'], array('fisheyeItem')) : array('fisheyeItem');
        $attributes['html'] = TRUE;
        // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// $link = l(theme('image', array('path' => service_links_expand_path($image, 'fisheye'), 'alt' => $text, 'getsize' => FALSE)) .'<span>'. $text .'</span>', $url[0], $attributes);

        break;
      default:
        // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// $link = theme($style, $variables);

    }
  }

  return $link;
}

/**
 * Format the items shown in the node.
 */
function theme_service_links_node_format($variables) {
  $links = $variables['links'];
  $label = $variables['label'];
  $view_mode = $variables['view_mode'];
  $node_type = $variables['node_type'];

  if ($view_mode == 'rss') {
    $result = array();
    foreach($links as $l) {
      // @FIXME
// l() expects a Url object, created from a route name or external URI.
// $result[] = l($l['title'], $l['href'], $l);

    }

    return '<div class="service-links">' . implode(' ', $result) . '</div>';
  }
  
  if (isset($label) && !empty($label)) {
    // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// return '<div class="service-links"><div class="service-label">'. t('@label', array('@label' => $label)) .' </div>'. theme('links', array('links' => $links)) .'</div>';

  }
  else {
    // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// return '<div class="service-links">'. theme('links', array('links' => $links)) .'</div>';

  }
}

/**
 * Format the items shown in one of the provided blocks.
 */
function theme_service_links_block_format($variables) {
  $items = $variables['items'];
  $style = $variables['style'];

  if (empty($items)) {
    return;
  }

  switch ($style) {
    case SERVICE_LINKS_STYLE_IMAGE:
      $output = implode(' ', $items);
      break;
    default:
      // @FIXME
// theme() has been renamed to _theme() and should NEVER be called directly.
// Calling _theme() directly can alter the expected output and potentially
// introduce security issues (see https://www.drupal.org/node/2195739). You
// should use renderable arrays instead.
// 
// 
// @see https://www.drupal.org/node/2195739
// $output = theme('item_list', array('items' => array_values($items)));

      break;
  }

  return '<div class="service-links">' . $output . '</div>';
}

/**
 * Format the items shown in the Fisheye block.
 */
function theme_service_links_fisheye_format($variables) {
  $items = $variables['items'];

  // @FIXME
// The Assets API has totally changed. CSS, JavaScript, and libraries are now
// attached directly to render arrays using the #attached property.
// 
// 
// @see https://www.drupal.org/node/2169605
// @see https://www.drupal.org/node/2408597
// drupal_add_js(service_links_expand_path('interface.js', 'javascript'), array('weight' => 90));

  // @FIXME
// The Assets API has totally changed. CSS, JavaScript, and libraries are now
// attached directly to render arrays using the #attached property.
// 
// 
// @see https://www.drupal.org/node/2169605
// @see https://www.drupal.org/node/2408597
// drupal_add_js(service_links_expand_path('service_links_fisheye.js', 'javascript'), array('weight' => 90));

  // @FIXME
// The Assets API has totally changed. CSS, JavaScript, and libraries are now
// attached directly to render arrays using the #attached property.
// 
// 
// @see https://www.drupal.org/node/2169605
// @see https://www.drupal.org/node/2408597
// drupal_add_css(service_links_expand_path('service_links_fisheye.css', 'css'));


  return "<div class=\"fisheye\"><div class=\"fisheyeContainer\">\r\n". implode("\r\n", $items) ."\r\n</div></div>";
}
