
node {

    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = TFT_eSprite*;
    }

    uint8_t mem[sizeof(TFT_eSprite)];

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        auto tft = getValue<input_DEV>(ctx);

        Type spr = new (mem) TFT_eSprite(tft);

        // initialize sprite
        spr -> setColorDepth(16);
        spr -> createSprite(getValue<input_Width>(ctx), getValue<input_Height>(ctx));

        emitValue<output_Sprite>(ctx, spr);
    }
}
