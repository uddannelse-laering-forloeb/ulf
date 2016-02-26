<?php
/**
 * @file
 * ulf_frontpage.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function ulf_frontpage_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'group_course';
  $content->admin_title = 'Group - course';
  $content->admin_description = 'Link to course offers';
  $content->category = 'Target group link';
  $content->settings = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<div class="teaser--group is-course">
<a class="teaser--group-inner" href="/kurser">
<div class="teaser--group-field">
<img src="/profiles/ulf/themes/[site:current-user:theme]/images/frontpage-course.jpg" alt="Kursus">
</div>
<div class="teaser--group-text is-course">
<div class="teaser--group-text-inner">Kurser</div>
</div>
</a>
</div>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $export['group_course'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'group_daycare';
  $content->admin_title = 'Group - daycare';
  $content->admin_description = 'Link to daycare offers';
  $content->category = 'Target group link';
  $content->settings = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<div class="teaser--group">
<a class="teaser--group-inner" href="/dagtilbud">
<div class="teaser--group-field">
<img src="/profiles/ulf/themes/[site:current-user:theme]/images/frontpage-dagtilbud.jpg" alt="Dagtilbud">
</div>
<div class="teaser--group-text is-dagtilbud">
<div class="teaser--group-text-inner">Dagtilbud</div>
</div>
</a>
</div>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $export['group_daycare'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'group_school';
  $content->admin_title = 'Group - school';
  $content->admin_description = 'Link to daycare offers';
  $content->category = 'Target group link';
  $content->settings = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<div class="teaser--group">
<a class="teaser--group-inner" href="/grundskole">
<div class="teaser--group-field">
<img src="/profiles/ulf/themes/[site:current-user:theme]/images/frontpage-grundskole.jpg" alt="Grundskole">
</div>
<div class="teaser--group-text is-grundskole">
<div class="teaser--group-text-inner">Grundskolen</div>
</div>
</a>
</div>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $export['group_school'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'group_youth';
  $content->admin_title = 'Group - youth';
  $content->admin_description = 'Link to youth offers';
  $content->category = 'Target group link';
  $content->settings = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<div class="teaser--group">
<a class="teaser--group-inner" href="/ungdomsuddannelse">
<div class="teaser--group-field">
<img src="/profiles/ulf/themes/[site:current-user:theme]/images/frontpage-ungdomsudd.jpg" alt="Ungdomsuddannelse">
</div>
<div class="teaser--group-text is-ungdomsuddannelse">
<div class="teaser--group-text-inner">Ungdomsuddannelser</div>
</div>
</a>
</div>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $export['group_youth'] = $content;

  return $export;
}
