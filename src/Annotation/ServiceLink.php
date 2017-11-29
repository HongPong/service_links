<?php

/**
 * @file
 * Contains \Drupal\service_links\Annotation\ServiceLink.
 */

namespace Drupal\service_links\Annotation;

use Drupal\Component\Annotation\Plugin;

/**
 * Defines a Service link item annotation object.
 *
 * @see \Drupal\service_links\Plugin\ServiceLinkManager
 * @see plugin_api
 *
 * @Annotation
 */
class ServiceLink extends Plugin {

  /**
   * The plugin ID.
   *
   * @var string
   */
  public $id;

  /**
   * The label of the plugin.
   *
   * @var \Drupal\Core\Annotation\Translation
   *
   * @ingroup plugin_translatable
   */
  public $label;

}
