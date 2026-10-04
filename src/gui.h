#ifndef GUI_H_SENTRY_
#define GUI_H_SENTRY_

#include <raylib.h>

#define SCREEN_WIDTH        800
#define SCREEN_HEIGHT       600
#define BASE_FONT_SIZE      32
#define NORMAL_FONT_SIZE    16

#define BG_MAIN_COLOR       BLACK
#define BG_TOPBAR_COLOR     VIOLET
#define BUTTON_COLOR        BROWN
#define DIALOG_COLOR        VIOLET
#define TEXT_COLOR          WHITE

#define EDIT_BTN_TEXT "Edit"

typedef struct {
    Rectangle   rec;
    int         is_clicked;
    char        *text;
} button;

enum {
  TB_edit,
  TB_about
};

typedef struct {
    Rectangle   *rec;
    button      **buttons;
    int         count;
} topbar;


void Handle_Window();
void Draw_Cordinates_Text();

#endif /* GUI_H_SENTRY_ ends here */
