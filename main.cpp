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
using millis = std::chrono::milliseconds;

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

    // UPtr<X::Sprite> spr1 = std::make_unique<X::Sprite>("../assets/debug.png", Vector2({200,300}));
    UPtr<X::GameObject> spr1 = std::make_unique<X::GameObject>(Vector2{100,100});
    spr1->game = &game;
    objects.push_back(std::move(spr1));

    std::chrono::time_point previous = std::chrono::steady_clock().now();
    long double tick  = 0.0;
    long double MS_PER_UPDATE = 0.016;

    millis accumulatedTime;
    double fixedTimestep = 0.016;

    while (!WindowShouldClose()) {

        game.deltaTime = GetFrameTime();

        std::chrono::time_point current = std::chrono::steady_clock().now();
        millis frameTime = std::chrono::duration_cast<millis>(current - previous);
        previous = current;
        accumulatedTime += frameTime;
        tick = accumulatedTime.count();

        std::cout << "Acc " << accumulatedTime.count() << std::endl;
        std::cout << "Tick " << tick << std::endl;
        std::cout << "Timestep " << fixedTimestep << std::endl;
        std::cout << "Timepoint " << current.time_since_epoch().count() << std::endl;

        // std::chrono::time_point current = std::chrono::steady_clock().now();
        // millis elapsed = std::chrono::duration_cast<millis>(current - previous);
        // previous     = current;
        // tick        += elapsed.count();
        //
        // std::cout << "Elapsed " << elapsed << std::endl;
        // std::cout << "Tick " << tick << std::endl;

        
        /**--------------------------------------------------------------------
        INPUT
        --------------------------------------------------------------------**/



        /**--------------------------------------------------------------------
        TICK PHYSICS
        --------------------------------------------------------------------**/
        while(tick >= fixedTimestep)
        {
            // Do physics simulation step at fixed dt   
            // DoPhysicsStep(fixedTimestep);
         
            game.tick = tick;

            for(auto& obj : objects)
            {
                obj->tick();
            }

            tick -= fixedTimestep;

        } 

        /**--------------------------------------------------------------------
        UPDATE DELTA
        --------------------------------------------------------------------**/

        // for(auto& obj : objects)
        // {
        //     obj->update();
        // }

        /**--------------------------------------------------------------------
        RENDER
        --------------------------------------------------------------------**/

        BeginDrawing();

            ClearBackground(LIGHTGRAY);

            for(auto& obj : objects)
            {
                // X::Sprite* spr = static_cast<X::Sprite*>(obj.get());

                // spr->render();
                obj->render();
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
