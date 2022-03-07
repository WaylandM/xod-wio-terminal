node {
    GFXfont font = FreeSerifBoldItalic18pt7b;
    void evaluate(Context ctx) {
        emitValue<output_Font>(ctx, &font);
    }
}
