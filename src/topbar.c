#include <raylib.h>
#include <stdlib.h>
#include "gui.h"
#include "gui_util.h"
#include "button.h"
#include "topbar_actions.h"
#include "topbar.h"

topbar * Create_Topbar(Rectangle *rec, Color color, button **buttons, int count)
{
    topbar *bar = NULL;

    bar = malloc(sizeof(*bar));
    if (!bar) {
        return NULL;
    }

    Copy_Rec(&bar->rec, rec);
    Copy_Color(&bar->color, &color);
    bar->buttons = buttons;
    bar->btns_count = count;

    return bar;
}

void Draw_Topbar(topbar *bar)
{
    int i;

    DrawRectangleRec(bar->rec, bar->color);
    for (i = 0; i < bar->btns_count; i++) {
        Draw_Button(bar->buttons[i]);
    }
}

void Handle_Topbar(topbar *bar)
{
    int i;
    for (i = 0; i < bar->btns_count; i++) {
        Handle_Button(bar->buttons[i]);
    }
}

void Destroy_Topbar(topbar *bar)
{
    free(bar);
}

topbar * Create_Main_Topbar()
{
    enum { /* Bar dimensions */
        bar_x = 0,
        bar_y = 0,
        bar_width = WINDOW_WIDTH,
        bar_height = 50
    };
    enum { /* Button bar dimensions */
        btn_x = 0,
        btn_y = 0,
        btn_width = 50,
        btn_height = 50
    };
    enum {
        btns_count = 1,
    };

    Rectangle rec;
    topbar *bar = NULL;
    button **buttons;
    int i;

    buttons = malloc(sizeof(*buttons) * btns_count);
    for (i = 0; i < btns_count; i++) {
        buttons[i] = malloc(sizeof(*buttons[0]));
        buttons[i]->action.call = show_about_dialog;
        Fill_Rec(&buttons[i]->rec,
                btn_x + i * btn_width, btn_y,
                btn_width, btn_height
        );
        buttons[i]->color = TOPBAR_BUTTON_COLOR;
    }

    Fill_Rec(&rec, bar_x, bar_y, bar_width, bar_height);
    bar = Create_Topbar(&rec, TOPBAR_COLOR, buttons, btns_count);

    return bar;
}

void Destroy_Main_Topbar(topbar *bar)
{
    int i;

    for (i = 0; i < bar->btns_count; i++) {
        free(bar->buttons[i]);
    }
    free(bar->buttons);
    Destroy_Topbar(bar);
}
