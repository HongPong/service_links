<?php

/**
 * @file
 * Contains \Drupal\service_links\Plugin\ServiceLinkBase.
 */

namespace Drupal\service_links;

use Drupal\Component\Plugin\PluginBase;

/**
 * Base class for Service link plugins.
 */
abstract class ServiceLinkBase extends PluginBase implements ServiceLinkInterface {

  /**
   * The plugin ID.
   *
   * @var string
   */
  public $id;

  /**
   * The name of the form plugin.
   *
   * @var \Drupal\Core\Annotation\Translation
   *
   * @ingroup plugin_translatable
   */
  public $name;

  public function __construct(array $configuration, $plugin_id, $plugin_definition) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
  }

  public function getId() {
    return $this->id;
  }

  public function getName() {
    return $this->name;
  }

  /**
   * Provide details of the service.
   *
   * @return array
   */
  public function getDetails() {
    return array(
      'name' => 'Twitter',
      'description' => t('Share this on Twitter'),
      'link' => 'http://twitter.com/share?url=<raw-encoded-short-url>&text=<raw-encoded-title>',
    );
  }
}
