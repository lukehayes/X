#include "raylib.h"

#include "X/Global.h"
#include "X/GameObject.h"

int main(void)
{
    X::Global global = X::Global::create_global();

    InitWindow(global.screen_width, global.screen_height, global.title);
    SetTargetFPS(global.FPS);

    X::GameObject object1({100,100});
    X::GameObject object2({400,500});

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

            DrawRectangle(
                object2.transform.position.x,
                object2.transform.position.y,
                object2.transform.scale.x,
                object2.transform.scale.y,
                object2.color
            );
        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}
