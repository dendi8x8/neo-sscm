#include <raylib.h>
#include "gui.h"
#include "topbar.h"

int main(void)
{
    topbar *main_topbar;

    main_topbar = Create_Main_Topbar();

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Neo-SSCM");
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);
        Draw_Topbar(main_topbar);
        Handle_Topbar(main_topbar);

        EndDrawing();
    }

    CloseWindow();
    Destroy_Main_Topbar(main_topbar);
    return 0;
}
