#include "oxinai.h"

userspace_config_t userspace_config;

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

