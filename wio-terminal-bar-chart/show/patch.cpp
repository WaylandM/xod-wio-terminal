

#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `TFT_eSPI tft` class instance
        auto barchart = getValue<input_BChart>(ctx);

        barchart -> showHistogram();

        emitValue<output_Done>(ctx, 1);
    }
}
