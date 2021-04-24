#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        ::pinMode(WIO_5S_UP, INPUT_PULLUP);
        ::pinMode(WIO_5S_DOWN, INPUT_PULLUP);
        ::pinMode(WIO_5S_LEFT, INPUT_PULLUP);
        ::pinMode(WIO_5S_RIGHT, INPUT_PULLUP);
        ::pinMode(WIO_5S_PRESS, INPUT_PULLUP);
        emitValue<output_UP>(ctx, ::digitalRead(WIO_5S_UP));
        emitValue<output_DOWN>(ctx, ::digitalRead(WIO_5S_DOWN));
        emitValue<output_LEFT>(ctx, ::digitalRead(WIO_5S_LEFT));
        emitValue<output_RIGHT>(ctx, ::digitalRead(WIO_5S_RIGHT));
        emitValue<output_PRESS>(ctx, ::digitalRead(WIO_5S_PRESS));
        emitValue<output_DONE>(ctx, 1);
    }
}
