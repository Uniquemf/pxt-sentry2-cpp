#include "pxt.h"
#include "Sentry/Sentry.h"

Sentry2* pSentry[4]={nullptr};

enum SentryId {
    //% block="Sentry00"
    Sentry00=0,
    //% block="Sentry01"
    Sentry01,
    //% block="Sentry10"
    Sentry10,
    //% block="Sentry11"
    Sentry11
};

enum SentryStatus {
    //% block="enable"
    Enable=1,
    //% block="disable"
    Eisable=0
};



namespace Sentry {
    /**
     * Initialize Sentry.
     */
    void begin(SentryId id, sentry_mode_e port) {
        if (!pSentry[id]) {
            pSentry[id] = new Sentry2(0x60+id);
        }
        if (port == kSerialMode) {
            pSentry[id]->begin(&uBit.serial);
        } else if (port == kI2CMode) {
            pSentry[id]->begin(&uBit.i2c);
        }
    }

    /**
     * Reset Sentry.
     */
    void setDefault(SentryId id){
        while(pSentry[id]->SensorSetDefault()!=SENTRY_OK);
    }
}