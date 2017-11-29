<?php
/**
 * Created by PhpStorm.
 * User: sharique
 * Date: 12/21/15
 * Time: 11:18 PM
 */

namespace Drupal\service_links\ServiceLink;

use Drupal\service_links\ServiceLinkBase;

/**
 * Class Twitter
 * @ServiceLink(
 *   id = "twitter"
 * )
 */
class Twitter extends ServiceLinkBase {

  /**
   * {@inheritdoc}
   */
  public function getDetails() {
    return array(
      'name' => 'Twitter',
      'description' => t('Share this on Twitter'),
      'link' => 'http://twitter.com/share?url=<raw-encoded-short-url>&text=<raw-encoded-title>',
    );
  }
}