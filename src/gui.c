#include "gui.h"
#include "raylib.h"
#include <stdio.h>

void Draw_Topbar()
{
    enum { hover_width = 100, hover_height = 50};
    enum { str_x = 10, str_y = 500 };
    enum { buf_len = 32 };
    Rectangle bar;
    Vector2 mouse;
    char str[buf_len];
    int is_hover;

    bar.x = 0;
    bar.y = 0;
    bar.width = GetScreenWidth();
    bar.height = 50;
    DrawRectangleRec(bar, RAYWHITE);
    mouse.x = GetMouseX();
    mouse.y = GetMouseY();
    snprintf(str, buf_len - 1, "x: %.2f, y: %.2f", mouse.x, mouse.y);
    if(CheckCollisionPointRec(mouse, bar)) {
        DrawText(str, str_x, str_y, NORMAL_FONT_SIZE, RED);
        DrawRectangle(mouse.x, mouse.y, hover_width, hover_height, BLUE);
    } else {
        DrawText(str, str_x, str_y, NORMAL_FONT_SIZE, GREEN);
        ClearBackground(VIOLET);
    }
}

void Handle_Window()
{
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(VIOLET);

        Draw_Topbar();

        EndDrawing();
    }
}
