
#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `TFT_eSPI tft` class instance
        auto barchart = getValue<input_BChart>(ctx);

        uint16_t x = getValue<input_X>(ctx);
        uint16_t y = getValue<input_Y>(ctx);
        uint8_t scaleFactor = getVAlue<input_Scale>(ctx);

        barchart -> shrinkShowHistogram(x, y, scaleFactor);

        emitValue<output_Done>(ctx, 1);
    }
}
