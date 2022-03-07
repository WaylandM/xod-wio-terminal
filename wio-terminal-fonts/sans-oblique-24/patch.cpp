node {
    GFXfont font = FreeSansOblique24pt7b;
    void evaluate(Context ctx) {
        emitValue<output_Font>(ctx, &font);
    }
}
