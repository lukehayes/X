#include "XX/System/Engine.h"

int main(int argc, char *argv[]) {

    constexpr int SCREEN_SCALE = 10;
    XX::System::Engine engine(320 * SCREEN_SCALE, 180 * SCREEN_SCALE, "Game");
    engine.run();
}
