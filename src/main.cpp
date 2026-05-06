#include "raylib.h"
#include "Include/Player.hpp"

int main(void) {

    const Color BG_COLOR = LIME;

    const int WIDTH = 800;
    const int HEIGHT = 600;

    Player plr{ 100, 100, 20, 3 };

    InitWindow(WIDTH, HEIGHT, "Hello Raylib");

    plr.Init();

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BG_COLOR);

            plr.Draw();
            plr.Update();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}