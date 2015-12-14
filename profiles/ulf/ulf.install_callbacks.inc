<?php
/**
 * @file
 * Batch job callbacks used in the installation profile.
 */

/**
 * Enables an module.
 *
 * @param string $module
 *   The modules machine name.
 * @param string $module_name
 *   The modules human name.
 * @param array $context
 *   The context of the batch job.
 */
function _ulf_enable_module($module, $module_name, &$context) {
  module_enable(array($module), FALSE);
  $context['message'] = st('Installed %module module.', array('%module' => $module_name));
}


/**
 * Import translation into the database.
 *
 * @param string $type
 *   Type of translation.
 * @param string $translation_file
 *   File with translation.
 * @param array $context
 *   The context of the batch job.
 */
function _ulf_insert_translation($type, $translation_file, &$context) {
  $file = new stdClass();
  $file->uri = DRUPAL_ROOT . $translation_file;
  $file->filename = basename($file->uri);
  _locale_import_po($file, 'da', LOCALE_IMPORT_OVERWRITE, $type);
  $context['message'] = st('Installed %type translation.', array('%type' => $type));
}


/**
 * Import default terms into the database. (Topic taxonomy).
 */
function _ulf_import_tax_topic(&$context) {
  $name = 'topic';
  $taxonomy_terms = array(
    'Film, musik, teater og dans',
    'Hytter og lejrskoler',
    'Idræt og bevægelse',
    'Kulturhistorie og tro',
    'Kunst, arkitektur og design',
    'Natur og friluftsliv',
    'Naturvidenskab',
    'Sundheds- og seksualundervisning',
    'Tværfaglige tilbud',
  );
  _ulf_create_taxonomy_terms($name, $taxonomy_terms);
  $context['message'] = st('Added topic terms.');
}


/**
 * Import default terms into the database. (Target group taxonomy).
 */
function _ulf_import_tax_target_group(&$context) {
  $name = 'target_group';
  $taxonomy_terms = array(
    'Dagtilbud',
    'Grundskole',
    'Ungdomsuddannelse',
  );
  _ulf_create_taxonomy_terms($name, $taxonomy_terms);
  $context['message'] = st('Added target group terms.');
}


/**
 * Import default terms into the database. (Target group sub taxonomy).
 */
function _ulf_import_tax_target_group_sub(&$context) {
  $name = 'target_group_sub';
  $taxonomy_terms = array(
    '0 år',
    '1 år',
    '2 år',
    '3 år',
    '4 år',
    '5 år',
    '6 år',
    '0. klasse',
    '1. klasse',
    '2. klasse',
    '3. klasse',
    '4. klasse',
    '5. klasse',
    '6. klasse',
    '7. klasse',
    '8. klasse',
    '9. klasse',
    '10. klasse',
    'STX',
    'HTX',
    'HHX',
    'HF',
  );
  _ulf_create_taxonomy_terms($name, $taxonomy_terms);
  $context['message'] = st('Added target group sub terms.');
}


/**
 * Import default terms into the database. (Primary school taxonomy).
 */
function _ulf_import_tax_subjects_primary_school(&$context) {
  $name = 'subjects_primary_school';
  $taxonomy_terms = array(
    'Billedkunst',
    'Biologi',
    'Dansk',
    'Drama',
    'Engelsk',
    'Filmkundskab',
    'Fotolære',
    'Fransk',
    'Fysik/kemi',
    'Geografi',
    'Historie',
    'Håndværk og design',
    'Idræt',
    'IT',
    'Kristendom',
    'Madkundskab',
    'Matematik',
    'Musik',
    'Natur/teknologi',
    'Samfundsfag',
    'Tysk',
  );
  _ulf_create_taxonomy_terms($name, $taxonomy_terms);
  $context['message'] = st('Added primary school terms.');
}


/**
 * Import default terms into the database. (Youth subjects taxonomy).
 * Divided into two steps to avoid timeout. (Step one)
 */
function _ulf_import_tax_subjects_youth_one(&$context) {
  $name = 'subjects_youth';
  $taxonomy_terms = array(
    'Afsætning',
    'Almen sprogforståelse',
    'Almen studieforberedelse',
    'Andre sprog',
    'Arabisk',
    'Astronomi',
    'Billedkunst',
    'Biologi',
    'Bioteknologi (forsøg)',
    'Dans',
    'Dansk',
    'Dansk som andetsprog (forsøg)',
    'Datalogi',
    'Design',
    'Dramatik',
    'Engelsk',
    'Erhvervsret',
    'Erhvervsøkonomi',
    'Filosofi',
    'Finansiering',
    'Fransk',
    'Fysik',
    'Geografi',
    'Græsk',
    'Historie',
    'Idehistorie',
    'Idræt',
    'Informationsteknologi',
    'Innovation',
    'International teknologi og kultur',
    'International økonomi',
  );
  _ulf_create_taxonomy_terms($name, $taxonomy_terms);
  $context['message'] = st('Added youth education terms step one.');
}


/**
 * Import default terms into the database. (Youth subjects taxonomy).
 * Divided into two steps to avoid timeout. (Step two)
 */
function _ulf_import_tax_subjects_youth_two(&$context) {
  $name = 'subjects_youth';
  $taxonomy_terms = array(
    'It',
    'Italiensk',
    'Japansk',
    'Kemi',
    'Kinesisk',
    'Kommunikation/it',
    'Kultur- og samfundsfaggruppen',
    'Kulturforståelse',
    'Latin',
    'Markedskommunikation',
    'Matematik',
    'Materialeteknologi',
    'Mediefag (film og tv)',
    'Multimedier',
    'Musik',
    'Naturgeografi',
    'Naturvidenskabelig faggruppe',
    'Naturvidenskabeligt grundforløb',
    'Oldtidskundskab',
    'Organisation',
    'Programmering',
    'Psykologi',
    'Religion',
    'Retorik',
    'Russisk',
    'Samfundsfag',
    'Samtidshistorie',
    'Spansk',
    'Statik og styrkelære',
    'Statistik',
    'Studieområdet',
    'Studieretningsprojektet',
    'Teknikfag',
    'Teknologi',
    'Teknologihistorie',
    'Tyrkisk',
    'Tysk',
    'Virksomhedsøkonomi',
  );
  _ulf_create_taxonomy_terms($name, $taxonomy_terms);
  $context['message'] = st('Added youth education terms step two.');
}


/**
 * Import default terms into the database. (Offer type taxonomy).
 */
function _ulf_import_tax_offer_type(&$context) {
  $name = 'offer_type';
  $taxonomy_terms = array(
    'Forløb med formidler',
    'Besøg på egen hånd',
    'Koncert/forestilling',
  );
  _ulf_create_taxonomy_terms($name, $taxonomy_terms);
  $context['message'] = st('Added offer type terms.');
}


/**
 * Import default terms into the database. (Educator relevance taxonomy).
 */
function _ulf_import_tax_course_relevancy_educators(&$context) {
  $name = 'course_relevancy_educators';
  $taxonomy_terms = array(
    'Vuggestue',
    'Børnehave',
    'SFO',
    'Klub',
    'Ungdomsskole',
    'Indskoling',
    'Mellemtrin',
    'Udskoling',
    'Ungdomsuddannelse',
  );
  _ulf_create_taxonomy_terms($name, $taxonomy_terms);
  $context['message'] = st('Added course relevancy terms.');
}

/**
 * Import default terms into the database. (Educational goals taxonomy).
 */
function _ulf_import_tax_educational_goals(&$context) {
  $name = 'educational_goals';
  $taxonomy_terms = array(
    'Alsidig personlig udvikling',
    'Krop og bevægelse',
    'Kulturelle udtryksformer og værdier',
    'Natur og naturfænomener',
    'Sociale kompetencer',
    'Sproglig udvikling',
  );
  _ulf_create_taxonomy_terms($name, $taxonomy_terms);
  $context['message'] = st('Added educational goal terms.');
}


/**
 * Create a taxonomy term and return the tid.
 * @param
 *  $name - String
 *  $terms - Array
 *
 */
function _ulf_create_taxonomy_terms($name, $terms) {
  $taxonomy_obj = taxonomy_vocabulary_machine_name_load($name);
  $vid = $taxonomy_obj->vid;
  foreach ($terms as $term_name) {
    $new_term = new stdClass();
    $new_term->name = $term_name;
    $new_term->vid = $vid;
    taxonomy_term_save($new_term);
  }
}


/**
 * Create a basic page node.
 */
function _ulf_create_basic_pages(&$context) {
  $node_definitions = array(
    'om-os' => array(
      'type' => 'static_page',
      'title' => 'Om os',
      'path' => 'om-os',
      'content' => 'Lorem ipsum',
      'menu' => 'main-menu'
    ),
    'kontakt' => array(
      'type' => 'static_page',
      'title' => 'Kontakt',
      'path' => 'kontakt',
      'content' => 'Lorem ipsum',
      'menu' => 'menu-about-ulf'
    ),
  );

  foreach($node_definitions as $node_arr) {
    // Create a node.
    _ulf_create_node($node_arr);

    // Get latest created nid (The one above.)
    $last_node = node_get_recent(1);
    $nid = key($last_node);
    // Create a menu link.
    _ulf_create_menu_link($nid, $node_arr['menu'], $last_node[$nid]->title);
  }

  $context['message'] = st('Added basis page content.');
}


/**
 * Create menu link.
 */
function _ulf_create_menu_link($id, $menu_name, $title) {
  $item = array(
    'link_path' => 'node/' . $id,
    'link_title' => $title,
    'menu_name' => $menu_name,
    'module' => 'ulf',
    'weight' => 10,
    'expanded' => 1,
    'customized' => 1,
  );
  menu_link_save($item);
}

/**
 * Create a node.
 */
function _ulf_create_node($attributes) {
  $node = new stdClass();
  $node->type = $attributes['type'];
  $node->language = LANGUAGE_NONE;
  node_object_prepare($node);

  // Settings.
  $node->title = $attributes['title'];
  $node->status = 1;
  $node->promote = 1;
  $node->sticky = 0;
  $node->comment = 0;
  $node->uid = 1;
  $node->date = 'basic_page_post_date';
  $node->created = strtotime('basic_page_post_date');

  // Path.
  $path = $attributes['path'];
  $node->path = array('alias' => $path);

  if ($attributes['type'] == 'static_page' ) {
    // Fields.
    $node->field_content[LANGUAGE_NONE][0]['value'] = $attributes['content'];
    $node->field_content[LANGUAGE_NONE][0]['format'] = 'editor';
  }

  // Save the node.
  node_save($node);
}