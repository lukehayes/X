#include "raylib.h"

#include "X/Global.h"
#include "X/GameObject.h"
#include "X/Sprite.h"

#include <stdio.h>

void DrawObject(X::GameObject* obj)
{
    printf("Color: r: %d g: %d b: %d a: %d\n", 
           obj->color.r,
           obj->color.g,
           obj->color.b,
           obj->color.a
    );

    DrawRectangle(
        obj->object.transform.position.x,
        obj->object.transform.position.y,
        obj->object.transform.scale.x,
        obj->object.transform.scale.y,
        obj->color
    );
}

int main(void)
{
    X::Global global = X::Global::create_global();

    InitWindow(global.screen_width, global.screen_height, global.title);
    SetTargetFPS(global.FPS);
    SetExitKey(KEY_Q);

    X::GameObject object1 = X::GameObjectCreate({100, 200});
    X::Object* o = &object1.object; 

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(LIGHTGRAY);
            DrawObject(&object1);
        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}
