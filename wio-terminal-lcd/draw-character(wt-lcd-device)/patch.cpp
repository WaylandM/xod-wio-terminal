#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `TFT_eSPI tft` class instance
        auto tft = getValue<input_DEV>(ctx);

        auto xString = getValue<input_Char>(ctx);
        auto it = xString.iterate();

        XColor color24 = getValue<input_Color>(ctx);
        uint16_t color16 = ((color24.r & 0xF8) << 8) | ((color24.g & 0xFC) << 3) | (color24.b >> 3);

        XColor bg24 = getValue<input_BG>(ctx);
        uint16_t bg16 = ((bg24.r & 0xF8) << 8) | ((bg24.g & 0xFC) << 3) | (bg24.b >> 3);

        tft -> setFreeFont(nullptr);

        tft -> drawChar(getValue<input_X>(ctx),
                        getValue<input_Y>(ctx),
                        *it,
                        color16,
                        bg16,
                        getValue<input_Size>(ctx));

        emitValue<output_Done>(ctx, 1);
    }
}
