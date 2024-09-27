#include "raylib.h"

#include "X/Global.h"
#include "X/GameObject.h"
#include "X/Sprite.h"

#include <vector>

void DrawSprite(const X::Sprite& sprite)
{
    DrawTextureEx(
        sprite.texture,
        sprite.transform.position,
        0,
        12,
        sprite.color
    );
}

void DrawObject(const X::GameObject& object)
{
    DrawRectangle(
        object.transform.position.x,
        object.transform.position.y,
        object.transform.scale.x,
        object.transform.scale.y,
        object.color
    );
}

int main(void)
{
    X::Global global = X::Global::create_global();

    InitWindow(global.screen_width, global.screen_height, global.title);
    SetTargetFPS(global.FPS);
    SetExitKey(KEY_Q);

    X::GameObject object1({100,100});
    X::Sprite s1("../assets/debug.png", Vector2({200,200}));


    std::vector<X::Object> objects;

    for(int i = 0; i<= 100; i++)
    {
        float rx = GetRandomValue(0,600);
        float ry = GetRandomValue(0,600);

        X::Sprite o("../assets/debug.png", Vector2({rx,ry}));

        objects.push_back(o);

    }




    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(LIGHTGRAY);

            DrawRectangle(
                object1.transform.position.x,
                object1.transform.position.y,
                object1.transform.scale.x,
                object1.transform.scale.y,
                object1.color
            );

        for(auto o : objects)
        {
        }

        //     DrawTextureEx(
        //         s1->texture,
        //         s1->transform.position,
        //         0,
        //         4,
        //         WHITE
        //     );
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
