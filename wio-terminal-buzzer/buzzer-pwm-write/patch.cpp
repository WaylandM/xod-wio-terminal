#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    #ifdef PWMRANGE
    static constexpr Number pwmRange = PWMRANGE;
    #else
    static constexpr Number pwmRange = 255.0;
    #endif

    void evaluate(Context ctx) {
 
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto duty = getValue<input_DUTY>(ctx);
        duty = duty > 1 ? 1 : (duty < 0 ? 0 : duty);
        int val = (int)(duty * pwmRange);

        pinMode(WIO_BUZZER, OUTPUT);
        analogWrite(WIO_BUZZER, val);

        emitValue<output_DONE>(ctx, 1);
    }
}
