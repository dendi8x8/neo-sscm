#ifndef GUI_H_SENTRY_
#define GUI_H_SENTRY_
#include <raylib.h>

#define BASE_FONT_SIZE      32
#define NORMAL_FONT_SIZE    16

#define BG_MAIN_COLOR       BLACK
#define BG_TOPBAR_COLOR     VIOLET
#define TEXT_COLOR          GREEN

typedef struct {
    Rectangle rec;
    Rectangle file_btn;
} topbar;

void Handle_Window();
void Init_Topbar(topbar *bar);
void Draw_Topbar(topbar *bar);

#endif
