#include "dialog.h"
#include "gui_util.h"
#include <stdlib.h>
#include <string.h>

dialog *Create_Dialog(Rectangle *rec, char **lines, int count)
{
    dialog *diag;
    int i;

    diag = malloc(sizeof(*diag));
    Copy_Rec(&diag->rec, rec);
    diag->lines = malloc(count * sizeof(*diag->lines));
    diag->count = count;
    for (i = 0; i < count; i++) {
      diag->lines[i] = strdup(lines[i]);
    }

    return diag;
}

/* TODO: Refactor this shit. */
void Draw_Dialog(dialog *diag)
{
    int i, t_x = 0, t_y = 0, t_w = 0, t_h = 0;

    t_x = diag->rec.x + GUI_MARGIN_GLOBAL;
    t_h = t_y + GUI_MARGIN_GLOBAL;
    DrawRectangleRec(diag->rec, DIALOG_COLOR);
    for (i = 0; i < diag->count; i++) {
        t_y = diag->rec.y + GUI_MARGIN_GLOBAL + i * NORMAL_FONT_SIZE;
        t_w = MeasureText(diag->lines[i], NORMAL_FONT_SIZE);
        DrawRectangle(t_x, t_y, t_w, NORMAL_FONT_SIZE, BUTTON_COLOR);
        DrawText(diag->lines[i], t_x, t_y, NORMAL_FONT_SIZE, TEXT_COLOR);
    }
}

void Destroy_Dialog(dialog *diag)
{
    int i;

    for (i = 0; i < diag->count; i++) {
        free(diag->lines[i]);
    }
    free(diag->lines);
    free(diag);
}
