<?php
/**
 * @file
 * Client to communicate with the search node.
 *
 * @TODO: Make the client non-drupal dependent.
 * @TODO: Store token in session to speed up things.
 */

class SearchNodeClient {

  /**
   * The host where search node is located.
   *
   * @var string
   */
  protected $host = 'https://127.0.0.1';

  /**
   * API key to authenticate with search node.
   *
   * @var string
   */
  protected $apikey;

  /**
   * Authentication token.
   *
   * @var string
   */
  protected $token;

  public function __construct($host, $apikey) {
    $this->host = $host;
    $this->apikey = $apikey;
  }

  public function authenticate() {
    $request = drupal_http_request($this->host . '/authenticate', array(
      'method' => 'POST',
      'headers' => array(
        'Content-Type' => 'application/json',
      ),
      'data' => json_encode(
        array(
          'apikey' => $this->apikey,
        )
      )
    ));

    if ($request->code == 200) {
      $this->token = json_decode($request->data)->token;
    }

    return array(
      'status' => $request->code,
      'message' => $request->status_message . ' - ' . $request->data,
    );
  }

  public function getIndexes() {
    $indexes = array();

    $request = drupal_http_request($this->host . '/api/indexes', array(
      'method' => 'GET',
      'headers' => array(
        'Content-Type' => 'application/json',
        'Authorization' => 'Bearer ' . $this->token
      ),
    ));

    if ($request->code == 200) {
      $indexes = json_decode($request->data);
    }

    return $indexes;
  }

  public function add() {

  }

  public function remove() {

  }

}