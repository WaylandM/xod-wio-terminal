node {
    GFXfont font = FreeMonoOblique12pt7b;
    void evaluate(Context ctx) {
        emitValue<output_Font>(ctx, &font);
    }
}
