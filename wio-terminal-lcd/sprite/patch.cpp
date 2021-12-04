//Include C++ libraries
#include"TFT_eSPI.h"


node {

    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = TFT_eSprite*;
    }

    uint8_t mem[sizeof(TFT_eSprite)];

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        auto tft = getValue<input_DEV>(ctx);

        Type spr = new (mem) TFT_eSprite(tft);

        emitValue<output_DEV>(ctx, &spr);
    }
}

