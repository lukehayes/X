#include "raylib.h"

#include "X/Global.h"
#include "X/GameObject.h"

int main(void)
{
    X::Global global = X::Global::create_global();

    InitWindow(global.screen_width, global.screen_height, global.title);
    SetTargetFPS(global.FPS);

    X::GameObject object1({100,100});

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

        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}
