
node {
    void evaluate(Context ctx) {

        // Get a pointer to the `TFT_eSprite sprite` class instance
        auto spr = getValue<input_Sprite>(ctx);

        XColor color24 = getValue<input_Color>(ctx);
        uint16_t color16 = ((color24.r & 0xF8) << 8) | ((color24.g & 0xFC) << 3) | (color24.b >> 3);

        if (getValue<input_Fill>(ctx)) {
            spr -> fillCircle(getValue<input_X>(ctx), getValue<input_Y>(ctx), getValue<input_R>(ctx), color16);
        } else {
            spr -> drawCircle(getValue<input_X>(ctx),  getValue<input_Y>(ctx), getValue<input_R>(ctx), color16);
        }

        emitValue<output_SpriteU0027>(ctx, spr);
    }
}
