#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include "gui_util.h"
#include "button.h"

button * Create_Button(Rectangle *rec, Color *color, char *text,
        button_callback *clbck)
{
    button *btn = NULL;

    btn = malloc(sizeof(*btn));
    if (!btn) {
        return NULL;
    }

    Copy_Rec(&btn->rec, rec);
    Copy_Color(&btn->color, color);
    btn->action.call    = clbck->call;
    btn->action.param   = clbck->param;
    btn->is_clicked     = 0;
    btn->text           = strdup(text);

    return btn;
}

void Draw_Button(button *btn)
{
    DrawRectangleRec(btn->rec, btn->color);
}

void Handle_Button(button *btn)
{
    Vector2 mouse;

    mouse = GetMousePosition();
    if (CheckCollisionPointRec(mouse, btn->rec) &&
        IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        btn->is_clicked = !btn->is_clicked;
    }

    if (btn->is_clicked) {
        btn->action.call(btn->action.param);
    }
}

void Destroy_Button(button *btn)
{
    free(btn->text);
    free(btn);
}
