#include "gui.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

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

enum {
    topbar_height = 50,
    topbar_btn_width = 50,
};

typedef enum {
    edit,
    about
} topbar_button_type;

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

button * Create_Topbar_Btn(int type)
{
    enum { max_text_len = 4 };
    button *btn = NULL;

    btn = malloc(sizeof(Rectangle));
    btn->rec = malloc(sizeof(*btn->rec));
    btn->text = malloc(max_text_len);

    switch (type) {
        case edit:
            btn->rec->x = 0;
            btn->rec->y = 0;
            btn->rec->width = topbar_btn_width;
            btn->rec->height = topbar_height;
            strncpy(btn->text, FILE_BTN_TEXT, max_text_len);
        case about:
            break;
    }

    return btn;
}

topbar * Init_Topbar()
{
    topbar *bar;
    bar = malloc(sizeof(topbar));

    bar->rec = Create_Bar_Rec();
    bar->edit_btn = Create_Topbar_Btn(edit);
    return bar;
}

void Destroy_Topbar(topbar *bar)
{
    free(bar->edit_btn->text);
    free(bar->edit_btn->rec);
    free(bar->edit_btn);
    free(bar->rec);
    free(bar);
}

void Draw_Topbar(topbar *bar)
{
    DrawRectangleRec(*bar->rec, BG_TOPBAR_COLOR);
    DrawRectangleRec(*bar->edit_btn->rec, BTN_COLOR);
    DrawText(
        FILE_BTN_TEXT,
        (bar->edit_btn->rec->width - MeasureText(FILE_BTN_TEXT, NORMAL_FONT_SIZE)) / 2,
        (bar->edit_btn->rec->height - NORMAL_FONT_SIZE) / 2,
        NORMAL_FONT_SIZE, TEXT_COLOR
    );
    Draw_Cordinates_Text();
}

void Handle_Topbar()
{
    ;   /* Empty function */
}
