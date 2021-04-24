#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        ::pinMode(WIO_KEY_A, INPUT_PULLUP);
        ::pinMode(WIO_KEY_B, INPUT_PULLUP);
        ::pinMode(WIO_KEY_C, INPUT_PULLUP);
        emitValue<output_A>(ctx, ::digitalRead(WIO_KEY_A));
        emitValue<output_B>(ctx, ::digitalRead(WIO_KEY_B));
        emitValue<output_C>(ctx, ::digitalRead(WIO_KEY_C));
        emitValue<output_DONE>(ctx, 1);
    }
}
