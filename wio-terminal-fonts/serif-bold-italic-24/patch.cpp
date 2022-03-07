node {
    GFXfont font = FreeSerifBoldItalic24pt7b;
    void evaluate(Context ctx) {
        emitValue<output_Font>(ctx, &font);
    }
}
