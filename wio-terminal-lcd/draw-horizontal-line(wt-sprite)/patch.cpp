#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `TFT_eSprite sprite` class instance
        auto spr = getValue<input_Sprite>(ctx);

        XColor color24 = getValue<input_Color>(ctx);
        uint16_t color16 = ((color24.r & 0xF8) << 8) | ((color24.g & 0xFC) << 3) | (color24.b >> 3);

        spr -> drawFastHLine(getValue<input_X>(ctx),  getValue<input_Y>(ctx), getValue<input_W>(ctx), color16);

        emitValue<output_Done>(ctx, 1);
    }
}
