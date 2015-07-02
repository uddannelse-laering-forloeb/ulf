<?php

/**
 * Implements hook_preprocess_page().
 */
function ulf_preprocess_page(&$variables) {
  // Provide main menu as block for all pages.
  $variables['main_menu_block'] = module_invoke('system', 'block_view', 'main-menu');
}


/**
 * Implements hook_preprocess_layout().
 */
function ulf_preprocess_front_page(&$variables) {
  // Provide newsletter block for front page.
  $variables['newsletter_block'] = module_invoke('mailchimp_signup', 'block_view', 'signup_to_newsletter');
}


/**
 * Implements theme_menu_tree().
 */
function ulf_menu_tree__main_menu ($variables) {
  // Strip default main menu tree of wrappers.
  return $variables['tree'];
}

/**
 * Implements theme_menu_tree().
 */
function ulf_menu_tree__menu_about_ulf ($variables) {
  // Strip default main menu tree of wrappers.
  return $variables['tree'];
}



/**
 * Implements theme_menu_link().
 */
function ulf_menu_link__main_menu($variables){
  $element = $variables['element'];
  $sub_menu = '';

  // Set type of link based on title of link.
  switch ($element['#title']) {
    case 'Dagtilbud':
      $element['#localized_options']['attributes']['class'][] = 'is-daycare';
      break;
    case 'Grundskole':
      $element['#localized_options']['attributes']['class'][] = 'is-school';
      break;
    case 'Ungdomsuddannelse':
      $element['#localized_options']['attributes']['class'][] = 'is-youth';
      break;
    case 'Kurser':
      $element['#localized_options']['attributes']['class'][] = 'is-course';
      break;
    case 'Om ULF':
      $menu_array = module_invoke('menu', 'block_view', 'menu-about-ulf');
      $element['#attributes']['class'][] = 'js-toggle-about';
      $sub_menu = '<div class="nav--sub js-about-menu is-hidden"><ul class="nav--static-pages is-menu">' . render($menu_array['content']) . '</ul></div>';
      break;
  }

  $element['#attributes']['class'][] = 'nav--list-item';
  $element['#localized_options']['attributes']['class'][] = 'nav--list-link';
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  return "<li" . drupal_attributes($element['#attributes']) . ">" . $output . $sub_menu . "</li>" ;
}


/**
 * Implements hook_preprocess_node().
 */
function ulf_preprocess_node(&$variables) {
  // Set default node teaser template.
  if ($variables['view_mode'] == 'teaser') {
    $variables['theme_hook_suggestions'][] = 'node__default_teaser';
  }

  // Set default group type.
  $variables['group_type'] = 'course';

  // Provide variables for use in the different templates.
  switch ($variables['type']) { // Switch on content type.
    case 'course':
      if (!empty($variables['field_target_group'])) {
        // Get term id from target group field.
        $term = $variables['field_target_group']['0']['taxonomy_term'];
        if ($term) {
          $term_wrapper = entity_metadata_wrapper('taxonomy_term', $term);
          $variables['group_type'] = strtolower($term_wrapper->name->value());
        }
      }
      break;
    case 'static_page':
      // Provide menu block for static page nodes.
      $variables['static_page_menu'] = module_invoke('menu', 'block_view', 'menu-about-ulf');

      // Provide newsletter block for static pages.
      $variables['newsletter_block'] = module_invoke('mailchimp_signup', 'block_view', 'signup_to_newsletter');
      break;
    case 'news':
      // Provide newsletter block for static pages.
      $variables['newsletter_block'] = module_invoke('mailchimp_signup', 'block_view', 'signup_to_newsletter');
      $variables['group_type'] = 'news';
      break;
  }


  // Display author meta data on courses.
  if (($variables['type'] == 'course'|| $variables['type'] == 'course_educators') && $variables['view_mode'] == 'full') {
    // Fetch author.
    $variables['author'] = user_load($variables['uid']);
    $author_wrapper = entity_metadata_wrapper('user', $variables['author']);
    $variables['profile_name'] = $author_wrapper->field_profile_name->value();
    $variables['profile_address'] = $author_wrapper->field_profile_address->value();
    $variables['profile_postal_code'] = $author_wrapper->field_profile_postal_code->value();
    $variables['profile_city'] = $author_wrapper->field_profile_city->value();
    $variables['profile_phone'] = $author_wrapper->field_profile_phone->value();
  }
}


/**
 * Implements hook_preprocess_user_profile().
 */
function ulf_preprocess_user_profile(&$variables) {
  // Enable a view for user profile templates.
  $variables['content_by_user'] = views_embed_view('ulf_content_by_user', 'block_1');
}


/**
 * Override or insert variables into the field template.
 */
function ulf_preprocess_field(&$variables) {
  // Some fields need all their html stripped, and want only the field value shown. We add a template for that.
  $stripped_template = array(
    'field_duration',
    'field_duration_unit',
    'field_profile_postal_code',
    'field_profile_city',
    'field_unit_price',
  );

  if (in_array($variables['element']['#field_name'], $stripped_template)) {
    $variables['theme_hook_suggestions'][] = 'field__stripped';
  }
}


/**
 * Override or insert variables into the panel pane template.
 *
 */
function ulf_preprocess_panels_pane(&$variables) {
  // Suggestions based on sub-type.
  $variables['theme_hook_suggestions'][] = 'panels_pane__' . str_replace('-', '__', $variables['pane']->subtype);
  $variables['theme_hook_suggestions'][] = 'panels_pane__'  . $variables['pane']->panel . '__' . str_replace('-', '__', $variables['pane']->subtype);

  // Frontpage panes.
  if ($variables['is_front'] && !empty($variables['pane']->panel)) {
    $variables['theme_hook_suggestions'][] = 'panels_pane__front';
  }

  // We only want to use the class provided from the ui.
  $variables['provided_class'] = '';
  if(!empty($variables['pane']->css['css_class'])) {
    $variables['provided_class'] = $variables['pane']->css['css_class'];
  }
}


/**
 * Implements theme_panels_default_style_render_region().
 *
 * Remove the panel separator from the default rendering method.
 */
function ulf_panels_default_style_render_region($variables) {
  $output = '';
  $output .= implode('', $variables['panes']);
  return $output;
}


/**
 * Implements theme_links().
 */
function ulf_links__system_main_menu($variables) {
  $html = '';

  foreach ($variables['links'] as $link) {
    // The \n after the <li> tag is important when using display: inline-block.
    $html .= '<li class="nav--list-item">' . l($link['title'], $link['href'], $link) . '</li>' . "\n";
  }

  return $html;
}

/**
 * Implements theme_links().
 */
function ulf_menu_link__menu_about_ulf($variables) {
  $element = $variables ['element'];
  $sub_menu = '';
  $element['#attributes']['class'] = 'nav--static-pages-item';

  if ($element ['#below']) {
    $sub_menu = drupal_render($element ['#below']);
  }
  $output = l($element ['#title'], $element ['#href'], $element ['#localized_options']);
  return '<li' . drupal_attributes($element ['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
