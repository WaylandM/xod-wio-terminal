// Tell XOD where it can download the libraries:
#pragma XOD require "https://github.com/Seeed-Studio/Seeed_Arduino_LCD"

//Include C++ libraries
#include"TFT_eSPI.h"


node {

    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = TFT_eSPI*;
    }

    // Create an object of class TFT_eSPI tft
    TFT_eSPI tft = TFT_eSPI();

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        // Try to initialize sensor
        tft.begin();
        tft.setRotation(3);

        emitValue<output_DEV>(ctx, &tft);
    }
}

