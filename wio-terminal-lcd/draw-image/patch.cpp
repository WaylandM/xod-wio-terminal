// Tell XOD where it can download the libraries:
#pragma XOD require "https://github.com/Seeed-Studio/Seeed_Arduino_FS"
#pragma XOD require "https://github.com/WaylandM/xod-wio-terminal"

#include <Seeed_FS.h>

#pragma once
#include<stdint.h>
#include<SD/Seeed_SD.h>
#include<RawImage.h>


node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `TFT_eSPI tft` class instance
        auto tft = getValue<input_DEV>(ctx);

        auto xString = getValue<input_File>(ctx);
        int N=length(xString) + 1;
        char cString[N];
        for(int i=0;i<N;i++)
            cString[i]=0;
        dump(xString, cString);

        if(getValue<input_16_bit>(ctx)) {
            drawImage<uint16_t>(cString, getValue<input_X>(ctx), getValue<input_Y>(ctx));
        } else {
            drawImage<uint8_t>(cString, getValue<input_X>(ctx), getValue<input_Y>(ctx));
        }

        emitValue<output_Done>(ctx, 1);
    }
}
