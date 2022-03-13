
#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `TFT_eSPI tft` class instance
        auto barchart = getValue<input_BChart>(ctx);

        uint8_t labSize = getValue<input_Lsize>(ctx);
        uint8_t valSize = getValue<input_Vsize>(ctx);

        XColor TxtCol24 = getValue<input_TxtCol>(ctx);
        uint16_t TxtCol16 = ((TxtCol24.r & 0xF8) << 8) | ((TxtCol24.g & 0xFC) << 3) | (TxtCol24.b >> 3);

        XColor TxtBG24 = getValue<input_TxtBG>(ctx);
        uint16_t TxtBG16 = ((TxtBG24.r & 0xF8) << 8) | ((TxtBG24.g & 0xFC) << 3) | (TxtBG24.b >> 3);

        XColor BG24 = getValue<input_BG>(ctx);
        uint16_t BG16 = ((BG24.r & 0xF8) << 8) | ((BG24.g & 0xFC) << 3) | (BG24.b >> 3);

        barchart -> setTextSizeColourHistogram(labSize, valSize, TxtCol16, TxtBG16, BG16);

        emitValue<output_Done>(ctx, 1);
    }
}
