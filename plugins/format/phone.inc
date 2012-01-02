<?php

/**
 * @file
 * The default format for adresses.
 */

$plugin = array(
  'title' => t('Phone number and extension'),
  'format callback' => 'addressfield_format_phone_generate',
  'type' => 'phone',
  'weight' => -99,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_phone_generate(&$format, $address, $context = array()) {
  if ($context['mode'] == 'form') {
    $format['phone_block'] = array(
      '#type' => 'addressfield_container',
      '#attributes' => array('class' => array('custom-block')),
      '#weight' => 200,
    );
    $format['phone_block']['phone_number'] = array(
      '#title' => t('Contact Phone'),
      '#size' => 15,
      '#attributes' => array('class' => array('phone-number')),
      '#type' => 'textfield',
      '#tag' => 'span',
      '#default_value' => isset($address['phone_number']) ? $address['phone_number'] : '',
      
    );
    $format['phone_block']['phone_number_extension'] = array(
      '#title' => t('Phone Extension'),
      '#size' => 10,
      '#attributes' => array('class' => array('phone-extension')),
      '#type' => 'textfield',
      '#tag' => 'span',
      '#default_value' => isset($address['phone_number_extension']) ? $address['phone_number_extension'] : '',
    );
    $format['phone_block']['fax_number'] = array(
      '#title' => t('Fax Number'),
      '#size' => 15,
      '#attributes' => array('class' => array('phone-number')),
      '#type' => 'textfield',
      '#tag' => 'div',
      '#default_value' => isset($address['fax_number']) ? $address['fax_number'] : '',
    );
  }
  else {
    // Add our own render callback for the format view
    $format['#pre_render'][] = '_addressfield_phone_render_address';
  }
}