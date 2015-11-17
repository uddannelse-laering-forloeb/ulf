<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div class="layout-node">
  <?php if ($display_workflow_actions) : ?>
    <div class="block--workflow">
      <div class="block--workflow-inner">
        <h3><?php print t('Workflow');?></h3>
        <div class="block--workflow-description">
          <?php print t('Would you like to publish this draft?');?>
        </div>
        <?php print $publish_link; ?>
      </div>
    </div>
  <?php endif; ?>
  <div class="layout-element-alpha">
    <div class="layout-element-alpha-inner">
      <?php if ($display_submitted): ?>
        <div class="submitted">
          <?php print $submitted; ?>
        </div>
      <?php endif; ?>
      <div class="content is-<?php print $group_type; ?>">
        <div class="content--image">
          <div class="field--title is-<?php print $group_type; ?>"><?php print render($title); ?></div>
          <?php print render($content['field_image']); ?>
        </div>
        <div class="content--main">
          <?php print render($content['field_full_description']); ?>
          <?php print render($content['field_purpose']); ?>
          <?php print render($content['field_video']); ?>
          <?php if ($field_activities || $field_background_knowledge || $field_post_work || $field_material_suggestions) : ?>
            <div class="field--collection-wrapper">
              <div class="field--collection-label"><?php print t('Yderligere information');?></div>
              <div class="field--collection-content">
                <div class="field--collection-item">
                  <?php print render($content['field_activities']); ?>
                  <?php print render($content['field_background_knowledge']); ?>
                  <?php print render($content['field_post_work']); ?>
                  <?php print render($content['field_material_suggestions']); ?>
                </div>
              </div>
            </div>
          <?php endif; ?>
          <?php print render($content['field_educational_material']); ?>
          <?php print render($content['field_inspirational_material']); ?>
          <div class="block--pdf">
            <a class="block--pdf-link" target="_blank" href="/printpdf/<?php print $node->nid; ?>"><?php print t('Save this offer as pdf'); ?></a>
          </div>
        </div>
        <div class="content--meta">
          <div class="block--light">
            <h2 class="block--header">
              <?php print t('Practical information'); ?>
            </h2>
            <div class="block--content">
              <div class="block--field-wrapper is-inline">
                <div class="block--field-label"><?php print t('Contact');?></div>
                <a href="/user/<?php print $uid; ?>"><?php print $profile_name; ?></a>
              </div>
              <div class="block--field-wrapper is-inline">
                <?php print render($content['field_offer_type']); ?>
                <?php print render($content['field_target_group_sub']); ?>
                <?php print render($content['field_count']); ?>
              </div>
              <?php if (!empty($content['field_special_needs']) && $content['field_special_needs']['#items']['0']['value'] == 1 ) : ?>
                <div class="block--field-wrapper">
                  <div class="block--field-label"><?php print t('This course supports children and youth with special needs.');?></div>
                </div>
              <?php endif; ?>
              <?php /* If any of the fields in this wrapper contain data */ ?>
              <?php if ($field_duration || $field_period_full_year['0']['value'] == 0 || $field_collection_price || $field_free['0']['value'] == 1 || $field_price_description || $field_duration_description) : ?>
                <div class="block--field-wrapper">
                  <?php if ($field_period_full_year['0']['value'] == 0 ) : ?>
                    <?php print render($content['field_period']); ?>
                  <?php else : ?>
                    <div class="block--field-label"><?php print t('Periode');?></div>
                    <div class="block--field-text"><?php print t('All year');?></div>
                  <?php endif;?>
                  <?php print render($content['field_period_info']); ?>
                  <?php if ($field_duration || $field_duration_description) : ?>
                    <div class="block--field-label"><?php print t('Duration');?></div>
                    <?php if ($field_duration) : ?>
                      <div class="block--field-text"><?php print $stripped_duration; ?><?php print render($content['field_duration_unit']); ?></div>
                    <?php endif; ?>
                    <?php if ($field_duration_description) : ?>
                      <div class="block--field-text"><?php print render($content['field_duration_description']); ?></div>
                    <?php endif; ?>
                  <?php endif;?>
                  <?php if ($field_free['0']['value'] == 0 ) : ?>
                    <div class="block--field-label"><?php print t('Price');?></div>
                    <?php print render($content['field_collection_price']); ?>
                  <?php else : ?>
                    <div class="block--field-label"><?php print t('This course is free.');?></div>
                  <?php endif;?>
                  <?php if ($field_price_description) : ?>
                    <div class="block--field-text"><?php print render($content['field_price_description']); ?></div>
                  <?php endif; ?>
                </div>
              <?php endif;?>
              <?php /* If any of the fields in this wrapper contain data */ ?>
              <?php if ($field_subject) : ?>
                <div class="block--field-wrapper">
                  <?php print render($content['field_subject']); ?>
                </div>
              <?php endif;?>
              <?php if ($field_educational_goals || $field_subjects_primary_school || $field_subjects_youth) : ?>
                <div class="block--field-wrapper">
                  <?php print render($content['field_educational_goals']); ?>
                  <?php print render($content['field_subjects_primary_school']); ?>
                  <?php print render($content['field_subjects_youth']); ?>
                </div>
              <?php endif; ?>
              <?php if ($field_facilities || $field_facilities_info) : ?>
                <div class="block--field-wrapper">
                  <?php print render($content['field_facilities']); ?>
                  <?php print render($content['field_facilities_info']); ?>
                </div>
              <?php endif; ?>
            </div>
          </div>
          <div class="block--dark">
            <h2 class="block--header">
              <?php print t('Contact organizer');?>
            </h2>
            <div class="block--content">
              <div class="block--field-label"><?php print $profile_name; ?></div>
              <div class="block--field-text"><?php print $profile_address; ?></div>
              <div class="block--field-text"><?php print $profile_postal_code; ?> <?php print $profile_city; ?></div>
              </br>
              <?php if (isset($profile_phone)) : ?>
                <div class="block--field-text"><?php print t('Phone')?> <?php print $profile_phone; ?></div>
              <?php endif; ?>
              </br>
              <a href="/user/<?php print $uid ?>"><?php print t('View organizer profile'); ?></a>
            </div>
          </div>
        </div>
      </div>
      <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['field_special_needs']);
      hide($content['field_duration']);
      hide($content['field_period']);
      hide($content['field_collection_price']);
      hide($content['field_free']);
      hide($content['field_period_full_year']);
      hide($content['field_target_group']);
      hide($content['comments']);
      hide($content['links']); ?>
      <div style=""><?php print render($content); ?></div>
    </div>
  </div>
</div>
