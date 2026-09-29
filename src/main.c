#include "gui.h"
#include "raylib.h"

int main(void)
{
    const int width = 800, height = 600;
    topbar bar;

    InitWindow(width, height, "SSCM - tool for creation addons");
    Init_Topbar(&bar);
    while (!WindowShouldClose()) {
          BeginDrawing();

          ClearBackground(BG_MAIN_COLOR);
          Draw_Topbar(&bar);

          EndDrawing();
      }
    CloseWindow();

    return 0;
}
