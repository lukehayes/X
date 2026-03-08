#ifndef X_GFX_COLOR_H
#define X_GFX_COLOR_H

#include "X/Types.h"

namespace X::Gfx
{

struct Color : public Vec3
{
    Color();
    Color(f32 r, f32 g, f32 b);
    Color(f32 r, f32 g, f32 b, f32 a);

    f32 r;
    f32 g;
    f32 b;
    f32 a;
};

}

#endif // X_GFX_COLOR_H
