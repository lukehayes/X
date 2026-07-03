#ifndef X_GFX_DEBUG_H
#define X_GFX_DEBUG_H

#include "X/Model/CubeModel.h"
#include "X/Math/Random.h"
#include <vector>


namespace X::Gfx {

static std::vector<X::Model::CubeModel>
DebugTestCubes3D(int count, int spacing) {

std::vector<X::Model::CubeModel> cubes;

    for (int x = 0; x <= count - 1; x++) {

        X::Model::CubeModel cube { {0,0,1,1} };

        auto xp = X::Math::Random::RandDouble(-spacing, spacing);
        auto yp = X::Math::Random::RandDouble(-spacing, spacing);
        auto zp = X::Math::Random::RandDouble(-spacing, spacing);

        auto r = X::Math::Random::RandDouble(0,1);
        auto g = X::Math::Random::RandDouble(0,1);
        auto b = X::Math::Random::RandDouble(0,1);
        auto a = X::Math::Random::RandDouble(1,1);

        cube.color = {r,g,b, a};


        cube.transform.position.x = xp;
        cube.transform.position.y = yp;
        cube.transform.position.z = zp;

        cubes.push_back(cube);
    }

    return cubes;
}

}




#endif // !X_GFX_DEBUG_H
