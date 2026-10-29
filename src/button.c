#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include "gui.h"
#include "gui_util.h"
#include "button.h"

button * Create_Button(Rectangle *rec, Color color, const char *text,
        button_callback *clbck)
{
    button *btn = NULL;

    btn = malloc(sizeof(*btn));
    if (!btn) {
        return NULL;
    }

    Copy_Rec(&btn->rec, rec);
    Copy_Color(&btn->color, &color);
    btn->action.call    = clbck->call;
    btn->action.param   = clbck->param;
    btn->is_clicked     = 0;
    btn->text           = strdup(text);

    return btn;
}

void Draw_Button(button *btn)
{
    Vector2 text_pos;

    text_pos.x = 0;
    text_pos.y = 0;
    text_pos = Center_Text(&btn->rec, btn->text, GUI_FONTSIZE);
    DrawRectangleRec(btn->rec, btn->color);
    DrawText(btn->text, text_pos.x, text_pos.y, GUI_FONTSIZE, TEXT_COLOR);
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
        /* Highlight current pressed button */
        DrawRectangleLines(btn->rec.x, btn->rec.y,btn->rec.width, btn->rec.height, TOPBAR_OUTLINE_COLOR);
        btn->action.call(btn->action.param);
    }
}

void Destroy_Button(button *btn)
{
    free(btn->text);
    free(btn);
}
