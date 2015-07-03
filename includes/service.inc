<?php

/**
 * @file
 * Contains SearchApiSearchNodeService.
 */

/**
 * Indexes and searches items using search node.
 */
class SearchApiSearchNodeService extends SearchApiAbstractService {

  protected $connection;

  /**
   * {@inheritdoc}
   */
  public function __construct(SearchApiServer $server) {
    parent::__construct($server);

    // Get connection to the client.
    if (isset($this->options['host'])) {
      $this->connection = new SearchNodeClient($this->options['host'], $this->options['apikey']);
      /**
       * @TODO: Handle auth better.
       */
      $this->connection->authenticate();
    }
  }

  /**
   * {@inheritdoc}
   */
  public function configurationForm(array $form, array &$form_state) {
    $form['host'] = array(
      '#type' => 'textfield',
      '#title' => t('Host address'),
      '#description' => t('The location of the hosted search node to use.'),
      '#required' => TRUE,
      '#default_value' => isset($this->options['host']) ? $this->options['host'] : 'https://localhost',
    );

    $form['apikey'] = array(
      '#type' => 'textfield',
      '#title' => t('API key (write access)'),
      '#description' => t('API used to index data into search node. It has write access and limited to index data based on IP address.'),
      '#required' => TRUE,
      '#default_value' => isset($this->options['apikey']) ? $this->options['apikey'] : '',
    );

    $form['apikey_readonly'] = array(
      '#type' => 'textfield',
      '#title' => t('API key (read only)'),
      '#description' => t('This API key is used in the Javascript front-end and is limited to search only.'),
      '#required' => TRUE,
      '#default_value' => isset($this->options['apikey_readonly']) ? $this->options['apikey_readonly'] : '',
    );


    if (module_exists('search_api_autocomplete')) {
      /**
       * @TODO: Auto complete support.
       */
    }

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function supportsFeature($feature) {
    $supported = drupal_map_assoc(array(
      'search_api_service_extra',
    ));

    if (isset($supported[$feature])) {
      return TRUE;
    }

    return parent::supportsFeature($feature);
  }

  /**
   * {@inheritdoc}
   */
  public function getExtraInformation() {
    $info = array();

    // Test that authentication is working.
    $result = $this->connection->authenticate();
    if ($result['status'] != 200) {
      $info[] = array(
        'label' => t('Authentication status'),
        'info' => $result['message'],
        'status' => 'error',
      );
    }
    else {
      $info[] = array(
        'label' => t('Authentication status'),
        'info' => t('Connected'),
        'status' => 'ok',
      );
    }

    // Get available indexes for that API key.
    $indexes = $this->connection->getIndexes();
    if (empty($indexes)) {
      $info[] = array(
        'label' => t('Indexes'),
        'info' => t('No indexes found with that API key.'),
        'status' => 'error',
      );
    }
    else {
      foreach ($indexes as $index) {
        $info[] = array(
          'label' => t('Index: @name (%tag)', array('@name' => $index->name, '%tag' => $index->tag)),
          'info' => $index->index,
          'status' => 'ok',
        );
      }

    }

    return $info;
  }

  /**
   * {@inheritdoc}
   */
  public function indexItems(SearchApiIndex $index, array $items) {
    if (empty($this->options['indexes'][$index->machine_name])) {
      throw new SearchApiException(t('No field settings for index with id @id.', array('@id' => $index->machine_name)));
    }

    $indexed = array();

    $search_node_index = $index->options['search_node_indexes'];
    if (!empty($search_node_index)) {
      foreach ($items as $id => $item) {
        /**
         * @TODO: Maybe better handle encoding below.
         */
        if ($this->connection->add($search_node_index, $item['type']['value'], $id, json_encode($item))){
          $indexed[] = $id;
        }
        else {
          watchdog('search_api_db', check_plain('exception'), NULL, WATCHDOG_WARNING);
        }
      }
    }
    else {
      throw new SearchApiException('No search node index have been selected.');
    }

    return $indexed;
  }

  /**
   * {@inheritdoc}
   */
  public function deleteItems($ids = 'all', SearchApiIndex $index = NULL) {
    if ($index) {
      $search_node_index = $index->options['search_node_indexes'];
      if (!empty($search_node_index)) {
        $data = array();
        if ($ids == 'all') {
          $this->connection->flush($search_node_index);
        }
        else {
          foreach ($data as $id => $type) {
            /**
             * @TODO: Maybe better handle encoding below.
             */
            if (!$this->connection->remove($search_node_index, $type, $id)) {
              watchdog('search_api_db', check_plain('exception'), NULL, WATCHDOG_WARNING);

              throw new SearchApiException('Unable to delete item.');
            }
          }
        }
      }
      else {
        throw new SearchApiException('No search node index have been selected.');
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function search(SearchApiQueryInterface $query) {

  }
}
