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
