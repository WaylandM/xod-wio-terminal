node {
    GFXfont font = FreeSerifBoldItalic9pt7b;
    void evaluate(Context ctx) {
        emitValue<output_Font>(ctx, &font);
    }
}
