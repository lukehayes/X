#include "raylib.h"

#include "X/Global.h"
#include "X/GameObject.h"
#include "X/Sprite.h"
#include "X/Renderer.h"
#include "X/Game.h"
#include <vector>
#include <memory>
#include <iostream>
#include <chrono>

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

    std::chrono::milliseconds start = std::chrono::duration()::zero;
    std::chrono::milliseconds end;
    double tick = 0;
    double ns = 1000000.0 / 60.0; // Syncs updates at 60 per second (59 - 61)

    while (!WindowShouldClose()) {

        auto start = (std::chrono::steady_clock::now()).time_since_epoch();

        std::chrono::milliseconds m = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

        std::cout << m.count() << std::endl;


        start = (std::chrono::steady_clock().now()).time_since_epoch();

        // tick  += (double)(start - end) / ns;

        std::cout << "Tick" << std::endl;

        while (tick >= 1.0) {
            
            // Call tick() here

            std::cout << "Tick" << std::endl;

            tick -=1.0;
        }


        std::cout << "Update" << std::endl;
        for(auto& obj : objects)
        {
            obj->update();
        }

        BeginDrawing();
            ClearBackground(LIGHTGRAY);
            std::cout << "Render" << std::endl;

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
