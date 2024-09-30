#ifndef X_GLOBAL_H
#define X_GLOBAL_H

namespace X
{
struct Global
{
    int screen_width;
    int screen_height;
    int FPS;
    const char* title;

    static Global create_global()
    {
        Global global;

        int mult = 4;

        global.screen_width  = 320 * mult;
        global.screen_height = 180 * mult;
        global.FPS           = 60;
        global.title         = "Global Window";

        return global;
    }
};
}

#endif
