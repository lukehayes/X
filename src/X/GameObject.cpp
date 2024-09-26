#include "X/GameObject.h"

namespace X
{
    GameObject GameObjectCreate(Vector2 pos)
    {
        GameObject go;
        go.object = ObjectCreate(pos, {0,0}, {16,16});
        go.color = {1,0,1,1};
        return go;
    }
}

