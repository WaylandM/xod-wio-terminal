#pragma XOD require "https://github.com/sparkfun/SparkFun_BQ27441_Arduino_Library"
#include <SparkFunBQ27441.h>

node {

    void evaluate(Context ctx) {

        if (isSettingUp()) {
            if (!lipo.begin()) {
                raiseError(ctx);
                return;
            }
            lipo.setCapacity(650);
        }

        if (isInputDirty<input_UPD>(ctx)) {
            unsigned int soc = lipo.soc();  // Read state-of-charge (%)
            unsigned int volts = lipo.voltage(); // Read battery voltage (mV)
            int current = lipo.current(AVG); // Read average current (mA)
            unsigned int fullCapacity = lipo.capacity(FULL); // Read full capacity (mAh)
            unsigned int capacity = lipo.capacity(REMAIN); // Read remaining capacity (mAh)
            int power = lipo.power(); // Read average power draw (mW)
            int health = lipo.soh(); // Read state-of-health (%)
 
            emitValue<output_SOC>(ctx, soc);
            emitValue<output_mV>(ctx, volts);
            emitValue<output_mA>(ctx, current);
            emitValue<output_mAh_F>(ctx, fullCapacity);
            emitValue<output_mAh_R>(ctx, capacity);
            emitValue<output_mW>(ctx, power);
            emitValue<output_SOH>(ctx, health);
            //emitValue<output_Done>(ctx, 1);
        }
    }
}
