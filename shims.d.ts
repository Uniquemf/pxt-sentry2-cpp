// Auto-generated. Do not edit.
declare namespace Sentry {

    /**
     * Initialize Sentry.
     */
    //% blockId=begin block="initialize%id|port%port" shim=Sentry::begin
    function begin(id: SentryId, port: sentry_mode_e): void;

    /**
     * Reset Sentry.
     */
    //% blockId=SensorSetDefault block="%id|restore default settings" shim=Sentry::setDefault
    function setDefault(id: SentryId): void;
}

// Auto-generated. Do not edit. Really.
