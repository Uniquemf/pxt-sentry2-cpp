
namespace Sentry {
    /**
     * Initialize Sentry.
     */
    //% blockId=begin advanced=true shim=Sentry::begin
    function begin(id: SentryId, port: sentry_mode_e): number{ return 0};

    /**
     * Reset Sentry.
     */
    //% advanced=true shim=Sentry::setDefault
    function setDefault(id: SentryId): number{ return 0};
}
