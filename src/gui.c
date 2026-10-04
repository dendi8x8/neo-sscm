#include "gui.h"
#include "raylib.h"
#include <stdio.h>

void Draw_Cordinates_Text()
{
    enum { buf_len = 32 };
    enum { str_x = 10, str_y = 500 };
    Vector2 mouse;
    char str[buf_len];

    mouse.x = GetMouseX();
    mouse.y = GetMouseY();
    snprintf(str, buf_len - 1, "x: %.2f, y: %.2f", mouse.x, mouse.y);
    DrawText(str, str_x, str_y, NORMAL_FONT_SIZE, TEXT_COLOR);
}
