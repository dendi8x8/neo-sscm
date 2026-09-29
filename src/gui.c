#include "gui.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

void Draw_Cordinates_Text()
{
    enum { buf_len = 32 };
    enum { str_x = 10, str_y = 500 };
    Vector2 mouse;
    char str[buf_len];
    mouse.x = GetMouseX();
    mouse.y = GetMouseY();
    snprintf(str, buf_len - 1, "x: %.2f, y: %.2f", mouse.x, mouse.y);
    DrawText(str, str_x, str_y, NORMAL_FONT_SIZE, GREEN);
}

enum { topbar_height = 50 };
typedef enum {
    edit,
    about
} topbar_button_type;

void Create_Bar_Rec(Rectangle *bar)
{
    bar->x = 0;
    bar->y = 0;
    bar->width = GetScreenWidth();
    bar->height = topbar_height;
}

void Create_Topbar_Btn(int type)
{
    switch (type) {
        case edit:
            break;
        case about:
            break;
    }
}

void Init_Topbar(topbar *bar)
{
    Create_Bar_Rec(&(bar->rec));
}

void Draw_Topbar(topbar *bar)
{
    DrawRectangleRec(bar->rec, BG_TOPBAR_COLOR);
    Draw_Cordinates_Text();
}

void Handle_Topbar()
{
}
