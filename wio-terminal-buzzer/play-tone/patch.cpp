#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {

        if (!isInputDirty<input_UPD>(ctx))
            return;

        ::pinMode(WIO_BUZZER, OUTPUT);

        int tone = getValue<input_TONE>(ctx);
        int duration = getValue<input_T>(ctx);
        
        for (long i = 0; i < duration * 1000L; i += tone * 2) {
            ::digitalWrite(WIO_BUZZER, HIGH);
            delayMicroseconds(tone);
            ::digitalWrite(WIO_BUZZER, LOW);
            delayMicroseconds(tone);
        }
        
        emitValue<output_DONE>(ctx, 1);
    }
}
