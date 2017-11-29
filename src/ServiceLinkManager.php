<?php

/**
 * @file
 * Contains \Drupal\service_links\Plugin\ServiceLinkManager.
 */

namespace Drupal\service_links;

use Drupal\Core\Plugin\DefaultPluginManager;
use Drupal\Core\Cache\CacheBackendInterface;
use Drupal\Core\Extension\ModuleHandlerInterface;

/**
 * Provides the Service link plugin manager.
 */
class ServiceLinkManager extends DefaultPluginManager {

  /**
   * Constructor for ServiceLinkManager objects.
   *
   * @param \Traversable $namespaces
   *   An object that implements \Traversable which contains the root paths
   *   keyed by the corresponding namespace to look for plugin implementations.
   * @param \Drupal\Core\Cache\CacheBackendInterface $cache_backend
   *   Cache backend instance to use.
   * @param \Drupal\Core\Extension\ModuleHandlerInterface $module_handler
   *   The module handler to invoke the alter hook with.
   */
  public function __construct(\Traversable $namespaces, CacheBackendInterface $cache_backend, ModuleHandlerInterface $module_handler) {
    parent::__construct('Plugin/ServiceLink', $namespaces, $module_handler, 'Drupal\service_links\Plugin\ServiceLinkInterface', 'Drupal\service_links\Annotation\ServiceLink');

    $this->alterInfo('service_links_service_link_info');
    $this->setCacheBackend($cache_backend, 'service_links_service_link_plugins');
  }

}
