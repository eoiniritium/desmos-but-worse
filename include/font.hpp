#pragma once

// To add safety to font, so that font data is not left on the gpu after program exit

#include "raylib.h"
class Font_s
{   public:
    Font_s(const char* file)
    {
        this->font = LoadFont(file);
    }

    ~Font_s()
    {
        UnloadFont(this->font);
    }

    Font getfont()
    {
        return this->font;
    }

    private:
    Font font;
};