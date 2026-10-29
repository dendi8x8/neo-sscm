#ifndef BUTTON_H_SENTRY
#define BUTTON_H_SENTRY

#include <raylib.h>

typedef void (*action_t)(void *);
typedef struct {
    action_t    call;
    void        *param;
} button_callback;

typedef struct {
    Rectangle           rec;
    Color               color;
    button_callback     action;
    int                 is_clicked;
    char                *text;
} button;

button * Create_Button(Rectangle *rec, Color color, const char *text,
        button_callback *clbck);
void Handle_Button(button *btn);

void Draw_Button(button *btn);
void Destroy_Button(button *btn);

#endif /* BUTTON_H_SENTRY */
