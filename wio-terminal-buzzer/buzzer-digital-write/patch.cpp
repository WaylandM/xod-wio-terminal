#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {

        if (!isInputDirty<input_UPD>(ctx))
            return;

        ::pinMode(WIO_BUZZER, OUTPUT);
        const bool val = getValue<input_SIG>(ctx);
        ::digitalWrite(WIO_BUZZER, val);
        emitValue<output_DONE>(ctx, 1);
    }
}
