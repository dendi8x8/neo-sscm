#include <raylib.h>
#include <stdlib.h>
#include <string.h>
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

button **Create_Main_Buttons(int count, actions_table *table)
{
    enum { /* Buttons dimensions */
        x = 0,
        y = 0,
        width = 50,
        height = 50
    };
    const char *texts[] = {
        "Edit",      /* First button*/
        "About",     /* Second button */
    };
    button **buttons = NULL;
    button_callback clbck;
    Rectangle rec;
    int i;

    buttons = malloc(count * sizeof(*buttons));
    Fill_Rec(&rec, x, y, width, height);
    for (i = 0; i < count; i++) {
        clbck.call = table->actions[i].call;
        rec.x = width * i;
        buttons[i] = Create_Button(&rec, TOPBAR_BUTTON_COLOR, texts[i], &clbck);
    }

    return buttons;
}

topbar * Create_Main_Topbar(actions_table *table)
{
    enum { /* Bar dimensions */
        bar_x = 0,
        bar_y = 0,
        bar_width = WINDOW_WIDTH,
        bar_height = 50
    };
    enum { buttons_count = 2 };
    Rectangle rec;
    topbar *bar = NULL;
    button **buttons = NULL;

    buttons = Create_Main_Buttons(buttons_count, table);
    Fill_Rec(&rec, bar_x, bar_y, bar_width, bar_height);
    bar = Create_Topbar(&rec, TOPBAR_COLOR, buttons, buttons_count);

    return bar;
}

void Destroy_Main_Topbar(topbar *bar)
{
    int i;

    for (i = 0; i < bar->btns_count; i++) {
        Destroy_Button(bar->buttons[i]);
    }
    free(bar->buttons);
    Destroy_Topbar(bar);
}
