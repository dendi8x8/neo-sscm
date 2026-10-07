#ifndef GUI_H_SENTRY_
#define GUI_H_SENTRY_

#include <raylib.h>

#define SCREEN_WIDTH        800
#define SCREEN_HEIGHT       600
#define BASE_FONT_SIZE      32
#define NORMAL_FONT_SIZE    16
#define GUI_MARGIN_GLOBAL   2

#define BG_MAIN_COLOR       BLACK
#define BG_TOPBAR_COLOR     VIOLET
#define BUTTON_COLOR        BROWN
#define DIALOG_COLOR        VIOLET
#define TEXT_COLOR          WHITE

#define EDIT_BTN_TEXT       "Edit"
#define ABOUT_BTN_TEXT      "About"

/* TODO: Changle count to l_count(lines count). */
typedef struct {
  Rectangle rec;
  char **lines;
  int count;
} dialog;

typedef struct {
    Rectangle   rec;
    int         is_clicked;
    char        *text;
    dialog      *diag;
} button;

enum {
  TB_edit,
  TB_about
};

/* TODO: Change *rec to rec. */
typedef struct {
    Rectangle   *rec;
    button      **buttons;
    dialog      **dialogs;
    int         count;
} topbar;

void Handle_Window();
void Draw_Cordinates_Text();

#endif /* GUI_H_SENTRY_ ends here */
