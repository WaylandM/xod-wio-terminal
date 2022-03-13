#pragma XOD require "https://github.com/sparkfun/SparkFun_BQ27441_Arduino_Library"
#include <SparkFunBQ27441.h>

node {
    meta {
        using Type = BQ27441*;
    }
    uint8_t mem[sizeof(BQ27441)];

    void evaluate(Context ctx) {

        if (isSettingUp()) {
            Type sensor = new (mem) BQ27441();
            if (!sensor->begin()) {
                raiseError(ctx);
                return;
            }
            sensor->setCapacity(650);
        }

        if (isInputDirty<input_UPD>(ctx)) {
            auto sensor = reinterpret_cast<BQ27441*>(mem);
            emitValue<output_SOC>(ctx, sensor->soc());
            emitValue<output_mV>(ctx, sensor->voltage());
            emitValue<output_mA>(ctx, sensor->current(AVG));
            emitValue<output_mAh_F>(ctx, sensor->capacity(FULL));
            emitValue<output_mAh_R>(ctx, sensor->capacity(REMAIN));
            emitValue<output_mW>(ctx, sensor->power());
            emitValue<output_SOH>(ctx, sensor->soh());
            //emitValue<output_Done>(ctx, 1);
        }
    }
}
