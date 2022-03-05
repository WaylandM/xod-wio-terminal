#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `TFT_eSprite sprite` class instance
        auto spr = getValue<input_Sprite>(ctx);

        auto xString = getValue<input_String>(ctx);
        int N=length(xString) + 1;
        char cString[N];
        for(int i=0;i<N;i++)
            cString[i]=0;
        dump(xString, cString);

        XColor color24 = getValue<input_Color>(ctx);
        uint16_t color16 = ((color24.r & 0xF8) << 8) | ((color24.g & 0xFC) << 3) | (color24.b >> 3);

        spr -> setTextColor(color16);
        spr -> setTextSize(getValue<input_Size>(ctx));
        spr -> drawString(cString,
                        getValue<input_X>(ctx),
                        getValue<input_Y>(ctx));

        emitValue<output_Done>(ctx, 1);
    }
}
