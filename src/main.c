#include "raylib.h"
#include <string.h>
#include "gui.h"
#include "topbar.h"

int main(void)
{
    topbar *bar = NULL;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SSCM - tool for creation addons");

    bar = Create_Topbar();

    while (!WindowShouldClose()) {
          BeginDrawing();

          ClearBackground(BG_MAIN_COLOR);
          Draw_Topbar(bar);
          Handle_Topbar(bar);
          Draw_Cordinates_Text();

          EndDrawing();
    }

    Destroy_Topbar(bar);
    CloseWindow();

    return 0;
}
