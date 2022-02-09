
node {
    void evaluate(Context ctx) {
        if (isInputDirty<input_IN>(ctx))
            emitValue<output_OUT>(ctx, 1);
    }
}
