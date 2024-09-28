#include "raylib.h"

#include "X/Global.h"
#include "X/GameObject.h"
#include "X/Sprite.h"
#include "X/Renderer.h"
#include <vector>
#include <memory>
#include <iostream>

template<class T> 
using UPtr = std::unique_ptr<T>;
using GOUptr = UPtr<X::GameObject>;


int main(void)
{
    X::Global global = X::Global::create_global();

    InitWindow(global.screen_width, global.screen_height, global.title);
    SetTraceLogLevel(LOG_NONE);
    SetTargetFPS(global.FPS);
    SetExitKey(KEY_Q);

    X::GameObject object1({100,100});
    X::Sprite s1("../assets/debug.png", Vector2({200,200}));

    std::vector<GOUptr>objects;

    for(int i = 0; i<= 10; i++)
    {
        float rx = GetRandomValue(0, global.screen_width - 20);
        float ry = GetRandomValue(0, global.screen_height - 20);

        std::unique_ptr<X::Sprite> o = std::make_unique<X::Sprite>("../assets/debug.png", Vector2 {rx,ry});

        // UPtr<X::Sprite> o = std::make_unique<X::Sprite>("../assets/debug.png", {rx,ry});
        //
        objects.push_back(std::move(o));

        // std::unique_ptr<X::GameObject> o;
        // o = std::make_unique<X::Sprite>("../assets/debug.png", Vector2({rx,ry}));
        // objects.push_back(std::move(o));
    }


    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(LIGHTGRAY);

            for(auto& obj : objects)
            {
                X::Sprite* spr = dynamic_cast<X::Sprite*>(obj.get());

                X::Renderer::DrawSprite(spr);

                // auto spr = dynamic_cast<X::Sprite*>(&obj);
                // DrawSprite(spr);
            }

            // for(auto& obj : objects)
            // {
            //     X::Sprite* spr = dynamic_cast<X::Sprite*>(obj.get());
            //     DrawSprite(spr);
            // }

        EndDrawing();
    }

    std::cout << "Deleted All objects" << std::endl;

    CloseWindow();

    return 0;
}
