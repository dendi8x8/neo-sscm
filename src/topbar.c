#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "topbar.h"
#include "button.h"
#include "dialog.h"

enum {
    topbar_height = 50,
};

Rectangle * Create_Bar_Rec()
{
    Rectangle *bar = 0;

    bar = malloc(sizeof(*bar));
    bar->x = 0;
    bar->y = 0;
    bar->width = GetScreenWidth();
    bar->height = topbar_height;

    return bar;
}

void Create_Topbar_Buttons(topbar *bar, int count)
{
    enum { rec_w = 50, rec_h = 50 };
    Rectangle btn_rec;

    btn_rec.x = 0;
    btn_rec.y = 0;
    btn_rec.width = rec_w;
    btn_rec.height = rec_h;
    /* #FIXME: Change hardcoced TB_edit value to loop. */
    bar->buttons[TB_edit] = Create_Button(&btn_rec, EDIT_BTN_TEXT);
}

void Create_Topbar_Dialogs(topbar *bar, int count)
{
    /* #TODO: Recfactor this to function center. */
    enum {
        edit_diag_w = 200,
        edit_diag_h = 150,
        edit_diag_x = (SCREEN_WIDTH - edit_diag_w) / 2,
        edit_diag_y = (SCREEN_HEIGHT - edit_diag_h) / 2,
    };
    /* #FIXME: Change hardcoced TB_edit value to loop. */
    const char *lines[] = {
        "Hello",
        "World"
    };
    Rectangle edit_rec;
    edit_rec.x = edit_diag_x;
    edit_rec.y = edit_diag_y;
    edit_rec.width = edit_diag_w;
    edit_rec.height = edit_diag_h;

    bar->dialogs[TB_edit] = Create_Dialog(
        &edit_rec, (char **)lines, sizeof(lines) / sizeof(*lines)
    );
}

topbar * Create_Topbar()
{
    enum { bar_buttons_count = 1 };
    enum { bar_dialogs_count = bar_buttons_count };
    topbar *bar;

    bar = malloc(sizeof(topbar));
    bar->rec = Create_Bar_Rec();
    bar->buttons = malloc(sizeof(*bar->buttons) * bar_buttons_count);
    bar->dialogs = malloc(sizeof(*bar->dialogs) * bar_dialogs_count);
    bar->count = bar_buttons_count;
    Create_Topbar_Buttons(bar, bar_buttons_count);
    Create_Topbar_Dialogs(bar, bar_dialogs_count);

    return bar;
}

void Draw_Topbar(topbar *bar)
{
    int i;

    DrawRectangleRec(*bar->rec, BG_TOPBAR_COLOR);
    for(i = 0; i < bar->count; i++) {
        Draw_Button(bar->buttons[i]);
    }
}

void Handle_Topbar(topbar *bar)
{
    Handle_Button(bar->buttons[TB_edit], Draw_Dialog, bar->dialogs[TB_edit]);
}

/* #TODO: This function overcomplicated, so we need to create this functions:
 * Destroy_Topbar_Buttons; Destroy_Topbar_Dialogs and use them there.
 */
void Destroy_Topbar(topbar *bar)
{
    int i;
    for (i = 0; i < bar->count; i++) {
        Destroy_Button(bar->buttons[i]);
        Destroy_Dialog(bar->dialogs[i]);
    }
    free(bar->buttons);
    free(bar->dialogs);
    free(bar->rec);
    free(bar);
}
