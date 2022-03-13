#pragma XOD require "https://github.com/Seeed-Studio/Seeed_Arduino_Histogram"

//#include <SPI.h>
#include"Histogram.h"

node {
    meta {
        using Type = TFT_Histogram*;
    }

    TFT_Histogram histogram = TFT_Histogram();
    
    void evaluate(Context ctx) {
        if (!isSettingUp())
            return;

        auto tft = getValue<input_DEV>(ctx);
        histogram.initHistogram(tft);

        emitValue<output_Histo>(ctc, &histogram);
    }
}
