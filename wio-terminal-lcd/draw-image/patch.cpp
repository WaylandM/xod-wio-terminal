// Tell XOD where it can download the libraries:
#pragma XOD require "https://github.com/Seeed-Studio/Seeed_Arduino_FS"

#include <Seeed_FS.h>

#pragma once
#include<stdint.h>
#include<SD/Seeed_SD.h>

extern TFT_eSPI tft;

template<class type>
struct RawImage{
    type * ptr(){
        return (type *)(this + 1);
    }
    type get(int16_t x, int16_t y){
        return this->ptr()[y * width() + x];
    }
    void draw(size_t x = 0, size_t y = 0){
        tft.pushImage(x, y, width(), height(), ptr());
    }
    void release(){
        delete [] this;
    }
    int16_t width(){ return _width; }
    int16_t height(){ return _height; }
private:
    int16_t  _width;
    int16_t  _height;
};

typedef RawImage<uint8_t>  Raw8;
typedef RawImage<uint16_t> Raw16;

template<class type>
RawImage<type> * newImage(const char * path){
    typedef RawImage<type> raw;
    File f = SD.open(path, FILE_READ);
    if (!f){
        return nullptr;
    }
    int32_t size = f.size();
    raw   * mem = (raw *)new uint8_t[size];
    if (mem == nullptr){
        return nullptr;
    }
    f.read(mem, size);
    f.close();
    return mem;
}

template<class type>
void drawImage(const char * path, size_t x = 0, size_t y = 0){
    auto img = newImage<type>(path);
    img->draw(x, y);
    img->release();
}


node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `TFT_eSPI tft` class instance
        auto tft = getValue<input_DEV>(ctx);

        auto xString = getValue<input_File>(ctx);
        int N=length(xString) + 1;
        char cString[N];
        for(int i=0;i<N;i++)
            cString[i]=0;
        dump(xString, cString);

        if(getValue<input_16_bit>(ctx)) {
            drawImage<uint16_t>(cString, getValue<input_X>(ctx), getValue<input_Y>(ctx));
        } else {
            drawImage<uint8_t>(cString, getValue<input_X>(ctx), getValue<input_Y>(ctx));
        }

        emitValue<output_Done>(ctx, 1);
    }
}
