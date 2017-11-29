<?php

/**
 * @file
 * Contains Service links block.
 */

use Drupal\Core\Block\BlockBase;
use Drupal\service_links\ServiceLinkBase;

/**
 * Provides Service Links Block.
 *
 * @Block(
 *   id = "service_links_block",
 *   admin_label = @Translation("Service links block")
 * )
 */
class ServiceLinksBlock extends BlockBase {

  /**
   * {@inheritdoc}
   */
  public function build() {

    $type = \Drupal::service('plugin.manager.service_link');

    /**
     * ServiceLinkBase derived object.
     */
    $plugin = $type->createInstance('twitter');
    $links = $plugin->getDetails();

    $markup = '<a href="' . $links['link'] . '" >' . $links['name'] . '</a>';

    return array(
      '#markup' => $markup,
    );
  }
}