#ifndef X_GFX_COLOR_H
#define X_GFX_COLOR_H


namespace X::Gfx
{

struct Color
{
    Color() : r(1), g(0), b(1), a(1) {}
    Color(float r, float g, float b) : r(r), g(g), b(b), a(1) {}
    Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}

    float r;
    float g;
    float b;
    float a;
};

}

#endif // X_GFX_COLOR_H
