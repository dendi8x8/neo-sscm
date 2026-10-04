#include <stdlib.h>
#include <raylib.h>
#include "topbar.h"
#include "button.h"

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

void Create_Topbar_Buttons(topbar *bar)
{
    enum { rec_w = 50, rec_h = 50 };
    Rectangle btn_rec;

    btn_rec.x = 0;
    btn_rec.y = 0;
    btn_rec.width = rec_w;
    btn_rec.height = rec_h;

    bar->buttons[TB_edit] = Create_Button(&btn_rec, EDIT_BTN_TEXT);
}

topbar * Create_Topbar()
{
    enum { bar_buttons_count = 1 };
    topbar *bar;

    bar = malloc(sizeof(topbar));
    bar->rec = Create_Bar_Rec();
    bar->buttons = malloc(sizeof(bar->buttons) * bar_buttons_count);
    bar->count = bar_buttons_count;
    Create_Topbar_Buttons(bar);

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

void Destroy_Topbar(topbar *bar)
{
    int i;
    for (i = 0; i < bar->count; i++) {
        Destroy_Button(bar->buttons[i]);
    }
    free(bar->rec);
    free(bar);
}
