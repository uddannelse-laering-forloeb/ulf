<?php
/**
 * @file
 * ulf_footer.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function ulf_footer_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Footer block left';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_one';
  $fe_block_boxes->body = '<strong>Kontakt</strong></br>
ULF i Aarhus</br>
Tlf.: 41 85 66 67</br>
<a href="mailto:info@ulfiaarhus.dk"><span style="color: rgb(255, 255, 255);">info@ulfiaarhus.dk</span></a>';

  $export['footer_one'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Footer block right';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_three';
  $fe_block_boxes->body = '<table>
   <tr>
    <td><img src="http://placekitten.com/115/115"></td>
    <td><img src="http://placekitten.com/115/115"></td>
    <td><img src="http://placekitten.com/115/115"></td>
  </tr>
</table>';

  $export['footer_three'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Footer block middle';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_two';
  $fe_block_boxes->body = '<a href="#">Kontakt</a></br>
<a href="#">Nyheder</a></br>
<a href="#">Tilmeld nyhedsbrev</a></br>
<a href="#">Samarbejdspartnere</a>';

  $export['footer_two'] = $fe_block_boxes;

  return $export;
}
