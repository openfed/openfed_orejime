<?php

/**
 * @file
 * Menu callbacks for admin pages.
 */

/**
 * Admin settings page.
 */
function openfed_orejime_admin_settings($form, &$form_state) {
  $dir = 'public://openfed_orejime';
  $languages = language_list();

  if (!empty($languages)) {
    foreach ($languages as $lancode => $language) {
      $privacy_policy = variable_get('privacy_policy_' . $lancode, '');
      $form['privacy_policy_' . $lancode] = array(
        '#type' => 'textfield',
        '#title' => t('Privacy policy url') . ' (' . $lancode . ')',
        '#default_value' => $privacy_policy,
      );
    }
  }

  $form['orejime_config_file'] = array(
    '#type' => 'managed_file',
    '#title' => t('Orejime configuration file'),
    '#upload_location' => $dir,
    '#upload_validators' => array(
      'file_validate_extensions' => array('js'),
    ),
    '#default_value' => variable_get('orejime_config_file', 0),
  );

  $form['#submit'][] = 'openfed_orejime_process_submission_form_submit';

  return system_settings_form($form);
}

/**
 * Submit handler for openfed_orejime_admin_settings().
 */
function openfed_orejime_process_submission_form_submit($form, &$form_state) {
  $current_file_set = variable_get('orejime_config_file', 0);
  $file_to_upload = $form_state['values']['orejime_config_file'];

  if ($file_to_upload) {
    if ($current_file_set) {
      // Skip if no modifications have been made to the uploaded file.
      if ($file_to_upload === $current_file_set) {
        return;
      }
      // Remove existing file before adding.
      openfed_orejime_settings_remove_managed_file($current_file_set);
    }
    try {
      // Save the file and move to the correct directory.
      global $user;
      $dir = 'public://openfed_orejime';
      $filename = 'orejime-config.js';
      $file = file_load($file_to_upload);
      $file->filename = $filename;
      $file->status = FILE_STATUS_PERMANENT;
      if (!file_move($file, $dir . '/' . $filename, FILE_EXISTS_REPLACE)) {
        throw new Exception('Failed to move file to ' . $dir);
      }
      file_usage_add($file, 'openfed_orejime', 'user', $user->uid);
    } catch (Exception $e) {
      drupal_set_message($e->getMessage(), 'error');
    }

  }
  // Remove the file if we don't have any upload attached.
  elseif ($current_file_set) {
    openfed_orejime_settings_remove_managed_file($current_file_set);
  }
}

/**
 * Helper function to remove the managed file process by
 * openfed_orejime_process_submission_form_submit().
 *
 * @param $fid
 */
function openfed_orejime_settings_remove_managed_file($fid) {
  variable_del('orejime_config_file');
  if ($file_to_delete = file_load($fid)) {
    file_usage_delete($file_to_delete, 'openfed_orejime');
    file_delete($file_to_delete);
  }
}
