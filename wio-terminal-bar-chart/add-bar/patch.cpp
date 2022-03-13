
#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `TFT_eSPI tft` class instance
        auto barchart = getValue<input_BChart>(ctx);

        auto xString = getValue<input_Label>(ctx);
        int N=length(xString) + 1;
        char cString[N];
        for(int i=0;i<N;i++)
            cString[i]=0;
        dump(xString, cString);

        uint8_t idx = getValue<input_Index>(ctx);
        float value = getValue<input_Value>(ctx);
        uint32_t width = getValue<input_Width>(ctx);

        XColor color24 = getValue<input_Color>(ctx);
        uint16_t color16 = ((color24.r & 0xF8) << 8) | ((color24.g & 0xFC) << 3) | (color24.b >> 3);

        barchart -> formHistogram(cString, idx, value, width, color16);

        emitValue<output_Done>(ctx, 1);
    }
}
