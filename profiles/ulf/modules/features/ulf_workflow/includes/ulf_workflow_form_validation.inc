<?php

/**
 * Custom form validation for image set.
 *
 * @param $form
 *  The form element.
 * @param $form_state
 *  The state of the form.
 */
function _ulf_workflow_form_validate_image($form, &$form_state) {
  $clicked_id = $form_state['clicked_button']['#id'];
  if (empty($form_state['values']['field_image']['und']['0']['fid'])) {
    switch ($clicked_id) {
      case 'edit-publish-editor':
        form_set_error('field_image', 'To publish content an image must be set');
        break;
      case 'edit-send-to-revision':
        form_set_error('field_image', 'Before sending content to revision an image must be set');
        break;
      case 'edit-publish-course-provider':
        form_set_error('field_image', 'To publish content an image must be set');
        break;
      case 'edit-save-course-provider':
        // If saving published content while user has permission to publish own
        // content it remains published. We can use status field.
        if ($form_state['values']['status'] == '1' && _ulf_workflow_check_publish_permission()) {
          form_set_error('field_image', 'To publish content an image must be set');
        }
        break;
      case 'edit-save-editor':
        // If saving published content as editor the content remains published.
        if ($form_state['values']['status'] == '1') {
          form_set_error('field_image', 'To publish content an image must be set');
        }
        break;
    }
  }
}


/**
 * Custom form validation for publishing date set.
 * If a publishing date is set on content users should not be able to manually publish it.
 *
 * @param $form
 *  The form element.
 * @param $form_state
 *  The state of the form.
 */
function _ulf_workflow_form_validate_publishing_date($form, &$form_state) {
  /*
  $clicked_id = $form_state['clicked_button']['#id'];
  if (!empty($form_state['values']['publish_on'])) {
    switch ($clicked_id) {
      case 'edit-publish-editor':
        form_set_error('publish_on', 'A scheduled publishing date has been set. If you want to manually publish the content you should unset the scheduled publishing date.');
        break;
      case 'edit-publish-course-provider':
        form_set_error('publish_on', 'A scheduled publishing date has been set. If you want to manually publish the content you should unset the scheduled publishing date.');
        break;
    }
  }
  */
}