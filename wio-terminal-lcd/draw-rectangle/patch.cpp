
node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `TFT_eSPI tft` class instance
        auto tft = getValue<input_DEV>(ctx);

        XColor color24 = getValue<input_Color>(ctx);
        uint16_t color16 = ((color24.r & 0xF8) << 8) | ((color24.g & 0xFC) << 3) | (color24.b >> 3);

        if (getValue<input_Fill>(ctx)) {
            tft -> fillRect(getValue<input_X>(ctx),  getValue<input_Y>(ctx), getValue<input_W>(ctx), getValue<input_H>(ctx), color16);
        } else {
            tft -> drawRect(getValue<input_X>(ctx),  getValue<input_Y>(ctx), getValue<input_W>(ctx), getValue<input_H>(ctx), color16);
        }

        emitValue<output_Done>(ctx, 1);
    }
}
