#include <raylib.h>
#include "gui_util.h"

void Fill_Rec(Rectangle *dst, float x, float y, float width, float height)
{
    dst->x      = x;
    dst->y      = y;
    dst->width  = width;
    dst->height = height;
}

void Copy_Rec(Rectangle *dst, Rectangle *src)
{
    dst->x      = src->x;
    dst->y      = src->y;
    dst->width  = src->width;
    dst->height = src->height;
}

void Copy_Color(Color *dst, Color *src)
{
    dst->r = src->r;
    dst->b = src->b;
    dst->g = src->g;
    dst->a = src->a;
}

Vector2 Center_Text(Rectangle *rec, const char *text, int f_size)
{
    Vector2 new_pos;
    float text_width;

    text_width = rec->width - MeasureText(text, f_size);
    new_pos.x = 0;
    new_pos.y = 0;
    new_pos.x = rec->x + text_width / 2;
    new_pos.y = (rec->height - f_size) / 2;

    return new_pos;
}
