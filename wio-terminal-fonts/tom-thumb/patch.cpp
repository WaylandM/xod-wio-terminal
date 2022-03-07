node {
    GFXfont font = TomThumb;
    void evaluate(Context ctx) {
        emitValue<output_Font>(ctx, &font);
    }
}
