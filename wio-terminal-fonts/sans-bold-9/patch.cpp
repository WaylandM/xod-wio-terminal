node {
    GFXfont font = FreeSansBold9pt7b;
    void evaluate(Context ctx) {
        emitValue<output_Font>(ctx, &font);
    }
}
