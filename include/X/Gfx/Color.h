#ifndef X_GFX_COLOR_H
#define X_GFX_COLOR_H


namespace X::Gfx
{

struct Color
{
    Color();
    Color(float r, float g, float b);
    Color(float r, float g, float b, float a);

    float r;
    float g;
    float b;
    float a;
};

}

#endif // X_GFX_COLOR_H
