#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
         if (!isInputDirty<input_UPD>(ctx))
            return;

        ::pinMode(WIO_LIGHT, INPUT);
        emitValue<output_VAL>(ctx, ::analogRead(WIO_LIGHT) / 1023.);
        emitValue<output_DONE>(ctx, 1);
    }
}
