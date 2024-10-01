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

template<class T>
using dur = std::chrono::duration<T>;

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

    using secs = std::chrono::milliseconds;
    using millis = std::chrono::seconds;
    using sys_clock = std::chrono::high_resolution_clock;
    using time_point = std::chrono::high_resolution_clock::time_point;


    millis startMS  = std::chrono::duration_cast<millis>(sys_clock::now().time_since_epoch());
    
    auto t1 = std::chrono::steady_clock().now();
    time_point t2;

    long double start = 0.0, end = 0.0;
    long double tick  = 0.0;
    long double ns    = 1000000.0 / 60.0; // Syncs updates at 60 per second (59 - 61)

    while (!WindowShouldClose()) {

        t1 = std::chrono::steady_clock().now();
        start = t1.time_since_epoch().count();

        std::cout << "Start " << start << std::endl;
        std::cout << "End " << end << std::endl;
        std::cout << "start - end " << (start - end) << std::endl;
        std::cout << "start - end / ns " << (long double)(start - end) / ns << std::endl;
        std::cout << "ns" << ns << std::endl;
        std::cout << "   " << std::endl;
        std::cout << "---------" << std::endl;

        // auto n = std::chrono::duration_cast<std::chrono::duration<double>>(t1 - t2);

        // tick  += (double)n.count() / ns;
        tick  += (double)(start - end) / ns;
        end = start;

        std::cout << "tick " << tick << std::endl;

        game.tick = tick;
        while (tick >= 1.0) {

            // Call n.count()() here
            for(auto& obj : objects)
            {
                X::Sprite* spr = static_cast<X::Sprite*>(obj.get());

                spr->update();
            }

            std::cout << "---------> tick Update: " << (long double)tick << std::endl;
            tick -= 1.0;
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
