#include <raylib.h>
#include <stdlib.h>
#include "gui.h"
#include "gui_util.h"
#include "topbar_actions.h"

actions_table * Init_Actions_Table()
{
    actions_table *table = NULL;
    int i;

    table = malloc(sizeof(*table));
    for (i = 0; i < TB_Actions_Count; i++) {
    }
    return table;
}

void show_about_dialog()
{
    /* #TODO(17.10.26): Create center function. */
    enum {
        about_width = 200,
        about_x = (WINDOW_WIDTH - about_width) / 2,
        about_height = 150,
        about_y = (WINDOW_HEIGHT - about_height) / 2
    };
    Rectangle rec;

    Fill_Rec(&rec, about_x, about_y, about_width, about_height);
    DrawRectangleRec(rec, DIALOG_COLOR);
}
