#ifndef GUI_H_SENTRY_
#define GUI_H_SENTRY_
#include <raylib.h>

#define SCREEN_WIDTH        800
#define SCREEN_HEIGHT       600
#define BASE_FONT_SIZE      32
#define NORMAL_FONT_SIZE    16

#define BG_MAIN_COLOR       BLACK
#define BG_TOPBAR_COLOR     VIOLET
#define BTN_COLOR           BROWN
#define DIALOG_COLOR        VIOLET
#define TEXT_COLOR          WHITE

#define FILE_BTN_TEXT "Edit"

typedef struct {
    Rectangle   rec;
    int         is_clicked;
    char        *text;
} button;

typedef struct {
    Rectangle   *rec;
    button      *edit_btn;
} topbar;

typedef struct {
    Rectangle   rec;
    button      **buttons;
    int         count;
} dialog;

void Handle_Window();

/* Topbar related functions: */
topbar * Init_Topbar();
void Destroy_Topbar(topbar *bar);
void Draw_Topbar(topbar *bar);
void Handle_Topbar(topbar *bar, dialog *edit_diag);
/* Dialog list related functions */
dialog *Init_Dialog(int lines);
void Destroy_Dialog(dialog *diag);
void Create_Dialog(dialog *diag, Rectangle *rec, char **text);

#endif /* GUI_H_SENTRY_ ends here */
