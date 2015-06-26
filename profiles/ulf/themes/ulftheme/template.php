<?php

/**
 * Implements hook_preprocess_page().
 *
 * Override or insert variables into the page template.
 */
function ulf_preprocess_page(&$variables) {
  // Provide main menu as block for all pages.
  $variables['main_menu_block'] = module_invoke('system', 'block_view', 'main-menu');
}


/**
 * Implements theme_menu_tree().
 */
function ulf_menu_tree__main_menu ($variables) {
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
    case 'Daycare':
      $element['#localized_options']['attributes']['class'][] = 'is-daycare';
      break;
    case 'School':
      $element['#localized_options']['attributes']['class'][] = 'is-school';
      break;
    case 'Youth':
      $element['#localized_options']['attributes']['class'][] = 'is-youth';
      break;
    case 'Courses':
      $element['#localized_options']['attributes']['class'][] = 'is-course';
      break;
  }

  // Sub item exist (Element is parent).
  if (!empty($variables['element']['#below'])) {
    $element['#attributes']['class'] = 'nav--list-dropdown-item';
    $sub_menu = '<div class="nav--dropdown-item">' . drupal_render($element['#below']) . '</div>';
    $element['#localized_options']['attributes']['class'][] = 'nav--list-dropdown-link';
    if ($element['#href'] == '<front>') {
      $element['#localized_options']['external'] = TRUE;
      $element['#href'] = '#';
    }
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  }

  // Element has parent.
  elseif ($element['#original_link']['plid'] > 0) {
    $element['#localized_options']['attributes']['class'][] = 'nav--dropdown-link';
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
    return $output;
  }

  // Default main menu link, not parent and not child.
  else {
    $element['#attributes']['class'] = 'nav--list-item';
    $element['#localized_options']['attributes']['class'][] = 'nav--list-link';
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  }
  return "<li" . drupal_attributes($element['#attributes']) . ">" . $output . $sub_menu . "</li>\n";
}


/**
 * Implements hook_preprocess_node().
 *
 * Adds a default teaser template.
 */
function ulf_preprocess_node(&$variables) {
  // Set default node teaser template.
  if ($variables['view_mode'] == 'teaser') {
    $variables['theme_hook_suggestions'][] = 'node__default_teaser';
  }

  // Set default group type.
  $variables['group_type'] = 'course';

  // Add target group variable to template.
  if($variables['type'] == 'course') {
    if (!empty($variables['field_target_group'])) {
      // Get term id from target group field.
      $term = $variables['field_target_group']['0']['taxonomy_term'];
      if ($term) {
        $term_wrapper = entity_metadata_wrapper('taxonomy_term', $term);
        $variables['group_type'] = strtolower($term_wrapper->name->value());
      }
    }
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
  $variables['content_by_user'] = views_embed_view('content_by_user', 'block_1');
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
 * Implements theme_username().
 */
function ulf_username($variables) {
  if(!empty($variables['uid'])) {
    $user = user_load($variables['uid']);
    $data = field_get_items('user', $user, 'field_profile_name');
    $profile_name = field_view_value('user', $user, 'field_profile_name', $data['0']);
    if (!empty($data)) {
      return '<a href="/user/' . $variables['uid'] . '"> '. $profile_name['#markup']  .'</a>';
    }
    else {
      return '<a href="/user/' . $variables['uid'] . '"> '. $variables['name']  .'</a>';
    }
  }
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
 * Implements theme_links_mobile().
 */
function ulf_links__system_main_menu_mobile($variables) {
  $html = '';

  foreach ($variables['links'] as $link) {
    // The \n after the <li> tag is important when using display: inline-block.
    $html .= '<li class="nav--mobile-link">' . l($link['title'], $link['href'], $link) . '</li>' . "\n";
  }

  return $html;
}


/**
 * Implements template_item_list().
 */
function ulf_item_list($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];

  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  $output = '<div class="item-list">';
  if (isset($title) && $title !== '') {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    // We break in and take control of the default item list rendering.
    if(!empty($variables['attributes'])) {
      if (!empty($variables['attributes']['id'])) {
        if (strpos($variables['attributes']['id'], 'facetapi') !== FALSE) {
          $attributes['class'][] = 'search-module--facet-selection';
          $list_item_class = 'search-facets--item';
        }
      }
    }
    $output .= '<' . $type . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $children = array();
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }
      if (!empty($list_item_class)) {
        $attributes['class'][] = $list_item_class;
      }

      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= '</' . $type . '>';
  }
  $output .= '</div>';
  return $output;
}
