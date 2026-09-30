#include "gui.h"
#include "raylib.h"

int main(void)
{
    const int width = 800, height = 600;
    topbar *bar = 0;

    InitWindow(width, height, "SSCM - tool for creation addons");
    bar = Init_Topbar();
    while (!WindowShouldClose()) {
          BeginDrawing();

          ClearBackground(BG_MAIN_COLOR);
          Draw_Topbar(bar);

          EndDrawing();
    }

    Destroy_Topbar(bar);
    CloseWindow();

    return 0;
}
