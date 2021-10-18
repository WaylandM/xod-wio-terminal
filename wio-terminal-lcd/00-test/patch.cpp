
node {


    void evaluate(Context ctx) {
        auto xString = getValue<input_IN>(ctx);

        auto it = xString.iterate();
        emitValue<output_OUT>(ctx, *it);
    }
}
