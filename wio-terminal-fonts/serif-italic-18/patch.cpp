node {
    GFXfont font = FreeSerifItalic18pt7b;
    void evaluate(Context ctx) {
        emitValue<output_Font>(ctx, &font);
    }
}
