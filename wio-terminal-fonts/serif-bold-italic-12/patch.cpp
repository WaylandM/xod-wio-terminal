node {
    GFXfont font = FreeSerifBoldItalic12pt7b;
    void evaluate(Context ctx) {
        emitValue<output_Font>(ctx, &font);
    }
}
