#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `TFT_eSPI tft` class instance
        auto tft = getValue<input_DEV>(ctx);

        tft -> setRotation(getValue<input_Rotate>(ctx));

        emitValue<output_Done>(ctx, 1);
    }
}
