#ifndef X_GAME_H
#define X_GAME_H

namespace X
{
    class Renderer;

    struct Game
    {
        Renderer* renderer;
        double deltaTime;
    };
}


#endif // !X_GAME_H
