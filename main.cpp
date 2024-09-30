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

    // ------------------------------------------------------------------------
    // Raylib setup
    InitWindow(global.screen_width, global.screen_height, global.title);
    SetTraceLogLevel(LOG_NONE);
    SetTargetFPS(global.FPS);
    SetExitKey(KEY_Q);

    // ------------------------------------------------------------------------


    // ------------------------------------------------------------------------
    // Test objects
    VGOUptr objects;
    X::GameObject object1({100,100});

    UPtr<X::Sprite> spr1 = std::make_unique<X::Sprite>("../assets/debug.png", Vector2({200,300}));
    spr1->game = &game;
    objects.push_back(std::move(spr1));


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

                spr->render();
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
