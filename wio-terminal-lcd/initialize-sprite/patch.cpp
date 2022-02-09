#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `TFT_eSprite sprite` class instance
        auto spr = getValue<input_Sprite>(ctx);

        // initialize sprite
        spr -> createSprite(getValue<input_Width>(ctx), getValue<input_Height>(ctx));

        emitValue<output_Done>(ctx, 1);
    }
}
