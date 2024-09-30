#include "raylib.h"

#include "X/Global.h"
#include "X/GameObject.h"
#include "X/Sprite.h"
#include "X/Renderer.h"
#include "X/Game.h"
#include <vector>
#include <memory>
#include <iostream>

template<class T> 
using UPtr = std::unique_ptr<T>;
using GOUptr = UPtr<X::GameObject>;
using VGOUptr = std::vector<GOUptr>;

int main(void)
{
    // ------------------------------------------------------------------------
    // Set initial state here.
    X::Global global = X::Global::create_global();
    
    X::Game game;
    game.deltaTime = GetFrameTime();

    X::Renderer renderer;
    game.renderer = &renderer;

    // ------------------------------------------------------------------------


    InitWindow(global.screen_width, global.screen_height, global.title);
    SetTraceLogLevel(LOG_NONE);
    SetTargetFPS(global.FPS);
    SetExitKey(KEY_Q);

    X::GameObject object1({100,100});
    X::Sprite s1("../assets/debug.png", Vector2({200,200}));

    VGOUptr objects;

    for(int i = 0; i<= 10; i++)
    {
        float rx = GetRandomValue(0, global.screen_width - 20);
        float ry = GetRandomValue(0, global.screen_height - 20);

        UPtr<X::Sprite> o = std::make_unique<X::Sprite>("../assets/debug.png", Vector2 {rx,ry});

        o->game = &game;
        
        objects.push_back(std::move(o));
    }


    while (!WindowShouldClose())
    {
        game.deltaTime = GetFrameTime();

        for(auto& obj : objects)
        {
            obj->update();
        }

        BeginDrawing();
            ClearBackground(LIGHTGRAY);

            for(auto& obj : objects)
            {
                X::Sprite* spr = static_cast<X::Sprite*>(obj.get());
                X::GameObject* o = obj.get();

                obj->render();
            }

        EndDrawing();
    }

    std::cout << "Deleted All objects" << std::endl;

    CloseWindow();

    return 0;
}
