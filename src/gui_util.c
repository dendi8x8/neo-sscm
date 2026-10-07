#include <string.h>
#include "gui_util.h"
#include "gui.h"

Vector2 Center_Text(const char *text, Rectangle *rec)
{
    Vector2 pos;
    int text_size;

    pos.x = 0;
    pos.y = 0;
    text_size = MeasureText(text, NORMAL_FONT_SIZE);
    pos.x = (rec->width - text_size) / 2;
    pos.y = (rec->height - NORMAL_FONT_SIZE) / 2;

    return pos;
}

void Copy_Rec(Rectangle *dst, Rectangle *src)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->width = src->width;
    dst->height = src->height;
}
