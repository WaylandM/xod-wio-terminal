
node {

    void evaluate(Context ctx) {
        auto red = getValue<input_R>(ctx);
        auto green = getValue<input_G>(ctx);
        auto blue = getValue<input_B>(ctx);

        
        emitValue<output_OUT>(ctx, inValue);
    }
}
