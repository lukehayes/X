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
    
    auto previous = std::chrono::steady_clock().now();
    // auto current = std::chrono::steady_clock::now();
    long double elapsed = 0.0;
    long double tick  = 0.0;
    long double MS_PER_UPDATE = 0.033;

    while (!WindowShouldClose()) {

        auto current = std::chrono::steady_clock().now();
        long double elapsed = current.time_since_epoch().count() - previous.time_since_epoch().count();
        previous = current;

        auto t = std::chrono::duration<double, std::ratio<1,10000>>(current.time_since_epoch().count());
        // tick = t.count();
        tick += elapsed;
        // auto tick2 = std::chrono::duration<long double>(tick).count();

        std::cout << "Elapsed " << elapsed << std::endl;
        std::cout << "Tick " << tick << std::endl;
        std::cout << "t " << t << std::endl;

        // std::chrono::duration<double,std::ratio<1,1000>>
        // auto n = std::chrono::duration_cast<std::chrono::duration<double>>(previous - current);
        
        /**--------------------------------------------------------------------
        INPUT
        --------------------------------------------------------------------**/



        /**--------------------------------------------------------------------
        TICK PHYSICS
        --------------------------------------------------------------------**/
        // while(tick >= MS_PER_UPDATE)
        // {
        //     for(auto& obj : objects)
        //     {
        //         obj->tick();
        //     }
        //
        //     std::cout << "UPDATING. Currrent Tick: " << tick << std::endl;
        //     tick -= MS_PER_UPDATE;
        //     game.tick = tick;
        // }


        /**--------------------------------------------------------------------
        UPDATE DELTA
        --------------------------------------------------------------------**/
        std::cout << "Update" << std::endl;

        for(auto& obj : objects)
        {
            // obj->update();
        }

        /**--------------------------------------------------------------------
        RENDER
        --------------------------------------------------------------------**/
        BeginDrawing();
            ClearBackground(LIGHTGRAY);
            std::cout << "Render" << std::endl;

            for(auto& obj : objects)
            {
                X::Sprite* spr = static_cast<X::Sprite*>(obj.get());

                obj->render();
                // spr->render();
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
