#include <raylib.h>
#include <stdlib.h>
#include "gui.h"
#include "gui_util.h"
#include "topbar_actions.h"

actions_table * TB_Init_Actions_Table()
{
    actions_table *table = NULL;

    table = malloc(sizeof(*table));
    table->actions[TB_Action_Edit].call = show_edit_dialog;
    table->actions[TB_Action_About].call = show_about_dialog;

    return table;
}

void show_edit_dialog(void *param)
{
    enum { /* Dialog dimensions */
        edit_width = 200,
        edit_x = (WINDOW_WIDTH - edit_width) / 2,
        edit_height = 300,
        edit_y = (WINDOW_HEIGHT - edit_width) / 2
    };
    Rectangle rec;

    Fill_Rec(&rec, edit_x, edit_y, edit_width, edit_height);
    DrawRectangleRec(rec, DIALOG_COLOR);
}

void show_about_dialog(void *param)
{
    /* #TODO(17.10.26): Create center macros. */
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

void TB_Destroy_Actions_Table(actions_table *table)
{
    free(table);
}
