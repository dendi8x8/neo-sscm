#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "button.h"
#include "gui_util.h"

button * Create_Button(Rectangle *rec, const char *text)
{
    button *btn;

    btn = malloc(sizeof(*btn));

    btn->rec.x = rec->x;
    btn->rec.y = rec->y;
    btn->rec.width = rec->width;
    btn->rec.height = rec->height;

    btn->is_clicked = 0;
    btn->text = strdup(text);

    return btn;
}

void Draw_Button(button *btn)
{
    Vector2 text_cord;

    text_cord = Center_Text(btn->text, &btn->rec);
    DrawRectangleRec(btn->rec, BUTTON_COLOR);
    DrawText(btn->text, text_cord.x, text_cord.y, NORMAL_FONT_SIZE, TEXT_COLOR);
}

void Handle_Button(button *btn, callback action, void *param)
{
    Vector2 mouse;

    mouse.x = 0;
    mouse.y = 0;
    mouse.x = GetMouseX();
    mouse.y = GetMouseY();
    if (CheckCollisionPointRec(mouse, btn->rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        btn->is_clicked = !btn->is_clicked;
    }
    if (btn->is_clicked) {
      action(param);
    }
}

void Destroy_Button(button *btn)
{
    free(btn->text);
    free(btn);
}
