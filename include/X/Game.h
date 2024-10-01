#ifndef X_GAME_H
#define X_GAME_H

namespace X
{
    class Renderer;

    struct Game
    {
        X::Renderer* renderer;
        double deltaTime;
        double tick;
    };
}


#endif // !X_GAME_H
