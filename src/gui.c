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
    enum { max_text_len = 5 };
    button *btn = NULL;

    btn = malloc(sizeof(*btn));
    btn->text = malloc(max_text_len);

    switch (type) {
        case edit:
            btn->rec.x = 0;
            btn->rec.y = 0;
            btn->rec.width = topbar_btn_width;
            btn->rec.height = topbar_height;
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
    bar->edit_btn->is_clicked = 0;
    return bar;
}

void Destroy_Topbar(topbar *bar)
{
    free(bar->edit_btn->text);
    free(bar->edit_btn);
    free(bar->rec);
    free(bar);
}

void Draw_Topbar(topbar *bar)
{
    DrawRectangleRec(*bar->rec, BG_TOPBAR_COLOR);
    DrawRectangleRec(bar->edit_btn->rec, BTN_COLOR);
    /* #TODO: Extract calculates to function.  */
    DrawText(
        FILE_BTN_TEXT,
        (bar->edit_btn->rec.width - MeasureText(FILE_BTN_TEXT, NORMAL_FONT_SIZE)) / 2,
        (bar->edit_btn->rec.height - NORMAL_FONT_SIZE) / 2,
        NORMAL_FONT_SIZE, TEXT_COLOR
    );
    Draw_Cordinates_Text();
}

dialog * Init_Dialog(int lines)
{
    dialog *dg;
    int i;

    dg = malloc(sizeof(*dg));
    dg->buttons = malloc(lines * sizeof(*dg->buttons));
    dg->count = lines;
    for(i = 0; i < lines; i++) {
        dg->buttons[i] = malloc(sizeof(**dg->buttons));
        dg->buttons[i]->is_clicked = 0;
    }

    return dg;
}

void Create_Dialog(dialog *dg, Rectangle *rec, char **text)
{
    enum { row_margin = 2 };
    int i;

    dg->rec.x = rec->x;
    dg->rec.y = rec->y;
    dg->rec.height = rec->height;
    dg->rec.width = rec->width;

    for (i = 0; i < dg->count; i++) {
        int row_y = (dg->rec.y + i * NORMAL_FONT_SIZE) + row_margin * i;
        int row_h =  NORMAL_FONT_SIZE;

        dg->buttons[i]->rec.x = dg->rec.x;
        dg->buttons[i]->rec.y = row_y;
        dg->buttons[i]->rec.width = MeasureText(text[i], NORMAL_FONT_SIZE);
        dg->buttons[i]->rec.height = row_h;

        dg->buttons[i]->text = strdup(text[i]);
    }
}

void Destroy_Dialog(dialog *diag)
{
    int i;
    for (i = 0; i < diag->count; i++) {
        if (!diag->buttons[i]->text) { continue; }
        free(diag->buttons[i]->text);
        free(diag->buttons[i]);
    }

    free(diag->buttons);
    free(diag);
}


void Show_Edit_Dialog(dialog *diag)
{
    enum { rows_count = 3, row_margin = 2 };

    Rectangle cur_rec;
    int i;

    DrawRectangleRec(diag->rec, DIALOG_COLOR);
    for (i = 0; i < rows_count; i++) {
        cur_rec = diag->buttons[i]->rec;
        DrawRectangleRec(diag->buttons[i]->rec, BTN_COLOR);
        DrawText(
            diag->buttons[i]->text,
            cur_rec.x,
            cur_rec.y,
            NORMAL_FONT_SIZE,
            TEXT_COLOR
        );
    }
}

void Handle_Topbar(topbar *bar, dialog *edit_diag)
{
    enum { clicked_text_x = 10 , clicked_text_y = 500 + NORMAL_FONT_SIZE };
    Vector2 mouse;

    mouse = GetMousePosition();
    if (CheckCollisionPointRec(mouse, bar->edit_btn->rec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        bar->edit_btn->is_clicked = !bar->edit_btn->is_clicked ;
    }

    if(!bar->edit_btn->is_clicked) {
        return;
    }

    Show_Edit_Dialog(edit_diag);
    DrawText("Edit button pressed", clicked_text_x, clicked_text_y, NORMAL_FONT_SIZE, TEXT_COLOR);
}
