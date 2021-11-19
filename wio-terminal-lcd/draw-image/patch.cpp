// Tell XOD where it can download the libraries:
#pragma XOD require "https://github.com/Seeed-Studio/Seeed_Arduino_FS"

#include <Seeed_FS.h>

#include<stdint.h>
#include<SD/Seeed_SD.h>

node {
    //meta {
        // Define our custom type as a pointer on the class instance.
        //using Type = TFT_eSPI*;
    //}

    void evaluate(Context ctx) {
        if(isSettingUp()){
            delay(2000);
            //Initialise SD card
            if (!SD.begin(SDCARD_SS_PIN, SDCARD_SPI)) {
                raiseError(ctx);
                return;
            }
        }
        
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

        File f = SD.open(cString, FILE_READ);
        if (!f){
            return;
        }
        int32_t size = f.size()-4;

        uint8_t header [4];
        f.read(header, 4);
/*
        if(getValue<input_16_bit>(ctx)) {
            //uint16_t mem [size/256];
            //drawImage<uint16_t>(cString, getValue<input_X>(ctx), getValue<input_Y>(ctx));
        } else {
            //uint8_t mem [size];
            //drawImage<uint8_t>(cString, getValue<input_X>(ctx), getValue<input_Y>(ctx));
        }
        */
        //uint8_t mem [size];
        //f.read(mem, size);
        f.close();


        //tft->setSwapBytes(false);
        //tft->pushImage(0,0,320,238,mem);

        int16_t w = ((header[1] << 8) | header[0]);
        int16_t h = ((header[3] << 8) | header[2]);
        
        emitValue<output_N>(ctx, size);
        
        emitValue<output_W>(ctx, w);
        emitValue<output_H>(ctx, h);
        
        
        emitValue<output_Done>(ctx, 1);
    }
}
