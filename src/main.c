#include "gui.h"
#include "raylib.h"

int main(void)
{
    topbar *bar = 0;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SSCM - tool for creation addons");
    bar = Init_Topbar();
    while (!WindowShouldClose()) {
          BeginDrawing();

          ClearBackground(BG_MAIN_COLOR);
          Draw_Topbar(bar);
          Handle_Topbar(bar);

          EndDrawing();
    }

    Destroy_Topbar(bar);
    CloseWindow();

    return 0;
}
