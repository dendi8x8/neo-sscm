#ifndef BUTTON_H_SENTRY_
#define BUTTON_H_SENTRY_

#include <raylib.h>
#include "gui.h"

typedef void (*callback)(dialog *);

enum {
  BTN_Action_Show_Dialog,
};

button * Create_Button(Rectangle *rec, const char *text);
void Draw_Button(button *btn);
void Handle_Button(button *btn, callback action, void *diag);
void Destroy_Button(button *btn);

#endif /* BUTTON_H_SENTRY_ ends here. */
