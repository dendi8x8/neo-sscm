#include <raylib.h>
#include "gui.h"
#include "topbar.h"

int main(void)
{
    topbar *main_topbar;
    actions_table *tb_actions;

    tb_actions = TB_Init_Actions_Table();
    main_topbar = Create_Main_Topbar(tb_actions);

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
    TB_Destroy_Actions_Table(tb_actions);
    return 0;
}
