#include "gui.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
    enum { lines = 3 };
    enum {
        dialog_w = 200,
        dialog_h = 150,
        dialog_x = (SCREEN_WIDTH - dialog_w) / 2,
        dialog_y = (SCREEN_HEIGHT - dialog_h) / 2,
    };

    const char *rows[] = {
            "Open .mdl file",
            "Open .addoninfo file",
            "Close program"
    };
    topbar *bar = NULL;
    dialog *dialog = NULL;
    Rectangle d_rec;
    int i;
    d_rec.x = dialog_x;
    d_rec.y = dialog_y;
    d_rec.width = dialog_w;
    d_rec.height = dialog_h;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SSCM - tool for creation addons");

    bar = Init_Topbar();
    dialog = Init_Dialog(lines);
    Create_Dialog(dialog, &d_rec, (char **)rows);
    for(i = 0; i < lines; i++) {
        printf("[%d] %s\n", i, dialog->buttons[i]->text);
    }

    while (!WindowShouldClose()) {
          BeginDrawing();

          ClearBackground(BG_MAIN_COLOR);
          Draw_Topbar(bar);
          Handle_Topbar(bar, dialog);

          EndDrawing();
    }

    Destroy_Topbar(bar);
    Destroy_Dialog(dialog);
    CloseWindow();

    return 0;
}
