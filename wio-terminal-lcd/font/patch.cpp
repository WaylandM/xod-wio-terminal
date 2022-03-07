#pragma XOD require "https://github.com/WaylandM/wio-terminal"

//Include C++ libraries
#include "Free_Fonts.h"

node {
    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = GFXfont*;
    }


    //GFXfont font = FreeSerif24pt7b;
    //GFXfont font = 0;

    void evaluate(Context ctx) {
        //emitValue<output_Font>(ctx, &font);
        emitValue<output_Font>(ctx, nullptr);
    }
}

