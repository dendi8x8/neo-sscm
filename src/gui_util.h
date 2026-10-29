#ifndef GUI_UTIL_H_
#define GUI_UTIL_H_

#include <raylib.h>

void Fill_Rec(Rectangle *dst, float x, float y, float width, float height);
void Copy_Rec(Rectangle *dst, Rectangle *src);
void Copy_Color(Color *dst, Color *src);
Vector2 Center_Text(Rectangle *rec, const char *text, int f_size);

#endif /* GUI_UTIL_H_ */
