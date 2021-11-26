#include "hw_sentry_i2c.h"
#include "../debug/debug_tool.h"
#include "../sentry_type.h"

HwSentryI2C::HwSentryI2C(hw_i2c_t* i2c_port, uint32_t address)
    : i2c_port_(i2c_port), sentry_address_(address) {
}

HwSentryI2C::~HwSentryI2C() {}

uint32_t HwSentryI2C::I2CRead(uint8_t reg_address, uint8_t* temp) {
  uint8_t ret = SENTRY_OK;
  //Debug Output
#if SENTRY_DEBUG_ENABLE && LOG_OUTPUT
  printf("[R:%02x,", reg_address);
#endif

#if !MICROBIT_CODAL
  if (i2c_port_->write(sentry_address_<<1, (const char *)&reg_address, 1) != MICROBIT_OK)
      return SENTRY_FAIL;
#else
  if (i2c_port_->write(sentry_address_<<1, (uint8_t *)&reg_address, 1) != MICROBIT_OK)
      return SENTRY_FAIL;
#endif  // MICROBIT_CODAL

  //Debug Output
#if SENTRY_DEBUG_ENABLE && LOG_OUTPUT
  printf("%02x],", *temp);
#endif

#if !MICROBIT_CODAL
  if (i2c_port_->read(sentry_address_<<1, (char *)temp, 1) != MICROBIT_OK)
      return SENTRY_FAIL;
#else
  if (i2c_port_->read(sentry_address_<<1, (uint8_t *)temp, 1) != MICROBIT_OK)
      return SENTRY_FAIL;
#endif  // MICROBIT_CODAL

  return SENTRY_OK;
}

uint32_t HwSentryI2C::I2CWrite(uint8_t reg_address, uint8_t value) {
  uint8_t ret = i2c_port_->writeRegister(sentry_address_<<1,reg_address,value);

  //Debug Output
#if SENTRY_DEBUG_ENABLE && LOG_OUTPUT
  printf("[W:%02x,%02x],",reg_address,value);
#endif
  return ret;
}
