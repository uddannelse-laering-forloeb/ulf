<?php

/**
 * Override or insert variables into the html template.
 */
function ulf_preprocess_html(&$variables) {

}


/**
 * Override or insert variables into the page template.
 */
function ulf_preprocess_page(&$variables) {

  // Render facets specifically before search results .
  if (!empty($variables['page']['facets'])) {
    $variables['page']['content']['facets'] = $variables['page']['facets'];
    $mobile_search_facets_path = $GLOBALS['base_root'] . '/' . path_to_theme() .'/scripts/mobile-search-facets.js';
    drupal_add_js($mobile_search_facets_path, 'file');
  }

  if ($variables['user']->uid == '0') {
    $default_anonymous = array (
      'user',
      'user/password',
      'user/register',
    );

    if (arg(0) == 'user') {
      if(in_array(current_path(), $default_anonymous)) {
        $variables['theme_hook_suggestions'][] = 'page__user_anonymous';
      }
    }
  }
  $variables['main_menu_block'] = module_invoke('system', 'block_view', 'main-menu');
}


/**
 * Implements theme_menu_tree().
 */
function ulf_menu_tree__main_menu ($variables) {
  return $variables['tree'];
}

/**
 * Implements theme_menu_link().
 */
function ulf_menu_link__main_menu($variables){
  $element = $variables['element'];
  $sub_menu = '';

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
 * Override or insert variables into the node template.
 *
 * Adds a default teaser template.
 */
function ulf_preprocess_node(&$variables) {
  if ($variables['view_mode'] == 'teaser') {
    $variables['theme_hook_suggestions'][] = 'node__default_teaser';
  }

  $variables['group_type'] = 'course';
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

function ulf_preprocess_user_profile(&$variables) {
  $variables['content_by_user'] = views_embed_view('content_by_user', 'block_1');
}

/**
 * Override or insert variables into the field template.
 *
 * Adds field class.
 */
function ulf_preprocess_field(&$variables) {
  // Some fields need all their html stripped, and want only the field value shown. We add a template for that.
  $stripped_template = array(
    'field_duration',
    'field_duration_unit',
    'field_profile_postal_code',
    'field_profile_city'
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

  // Frontpage panes
  if ($variables['is_front'] && !empty($variables['pane']->panel)) {
    $variables['theme_hook_suggestions'][] = 'panels_pane__front__' . $variables['pane']->panel;
  }

  // We only want to use the class provided from the ui.
  $variables['provided_class'] = '';
  if(!empty($variables['pane']->css['css_class'])) {
    $variables['provided_class'] = $variables['pane']->css['css_class'];
  }

  if ($variables['display']->layout == 'onecol') {
    $variables['theme_hook_suggestions'][] = 'panels_pane__onecol';
  }

  // For some reason the "useful_info" pane does not register if it's empty. We look for a list item and if none exist send a variable to the template file
  $variables['content_is_empty'] = FALSE;
  if ($variables['pane']->subtype == 'ulf_useful_info-panel_pane_1') {
    if (!preg_match('/<li class="block--list-item">/', $variables['content'])) {
      $variables['content_is_empty'] = TRUE;
    }
  }

  if ($variables['pane']->type == 'entity_field') {
    if (!empty($variables['content'])) {
      $variables['theme_hook_suggestions'][] = 'panels_pane__' . $variables['content']['#bundle'] . '__' . $variables['content']['#field_name'];
    }
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
 * Implements theme_apachesolr_search_suggestions().
 */
function ulf_apachesolr_search_suggestions($variables) {
  $output = '<div class="search-module--spelling-suggestions">';
  $output .= '<div class="form-item"><span class="search-module--did-you-mean-text">' . t('Did you mean') . ': </span>';

  foreach ($variables['links'] as $link) {
    $output .= '<span>' . $link . '</span>';
  }

  $output .= '</div></div>';
  return $output;
}

/**
 * Implements template_preprocess_search_result().
 */
function ulf_preprocess_search_api_page_result(&$vars) {
  // Fetch the data wrapper for the search result.
  if($vars['index']->item_type == 'node') {
    $wrapper = entity_metadata_wrapper('node', $vars['item']);
  }

  // Fetch profile name from user.
  $vars['username'] = db_query("SELECT field_profile_name_value FROM {field_data_field_profile_name} WHERE entity_id=:uid AND entity_type='user'", array(':uid' => $vars['item']->uid))->fetchField();
  $vars['username'] = check_plain($vars['username']);
  // Use default username if no profile name is set.
  if (empty($vars['username'])) {
    $vars['username'] = $vars['item']->name;
  }

  // Fetch image from result
  if(!empty($wrapper->field_image)) {
    $image = $wrapper->field_image->value();
    if(!empty($image['0'])) {
      $vars['image'] = theme('image_style', array('path' => $image['0']['uri'], 'style_name' => 'ulf_list_display'));
    }
  }
  else {
    $vars['image'] = FALSE;
  }

  // Set the result text variable.
  $vars['result_text'] = FALSE;

  // Result description is used for teasertext on course_educators content type
  if(!empty($wrapper->field_full_description)) {
    $vars['result_description'] = $wrapper->field_full_description->value();
    if (is_array($vars['result_description'])) {
      $vars['result_description'] = $vars['result_description']['safe_value'];
    }
    $vars['result_text'] = truncate_utf8($vars['result_description'], '200', TRUE, TRUE);
  }

  // Purpose is used as teasertext on result_description content type
  if(!empty($wrapper->field_purpose)) {
    $vars['result_purpose'] = $wrapper->field_purpose->value();
    $vars['result_text'] = truncate_utf8($vars['result_purpose'], '200', TRUE, TRUE);
  }
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
