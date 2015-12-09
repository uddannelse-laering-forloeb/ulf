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
 * Import default terms into the database.
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


function _ulf_import_tax_subjects_youth(&$context) {
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
  $context['message'] = st('Added youth education terms.');
}


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


function _ulf_create_basic_content(&$context) {
  _ulf_create_basic_page();
  $context['message'] = st('Added base content.');
}

/**
 * Create a taxonomy term and return the tid.
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
function _ulf_create_basic_page() {
  $node = new stdClass();
  $node->type = 'static_page';
  $node->language = LANGUAGE_NONE;
  node_object_prepare($node);

  // Settings.
  $node->title = 'Om ud og lær Silkeborg';
  $node->status = 1;
  $node->promote = 1;
  $node->sticky = 0;
  $node->comment = 0;
  $node->uid = 1;
  $node->date = 'basic_page_post_date';
  $node->created = strtotime('basic_page_post_date');

  // Path.
  $path = 'om-ud-og-laer-silkeborg';
  $node->path = array('alias' => $path);

  // Fields.
  $node->field_content[LANGUAGE_NONE][0]['value'] = 'Lorem ipsum om Ud og Lær Silkeborg';
  $node->field_content[LANGUAGE_NONE][0]['format'] = 'full_html';

  // Save the node.
  node_save($node);
}