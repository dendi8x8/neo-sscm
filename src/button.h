#ifndef BUTTON_H_SENTRY_
#define BUTTON_H_SENTRY_

#include <raylib.h>
#include "gui.h"

button * Create_Button(Rectangle *rec, const char *text);
void Draw_Button(button *btn);
void Destroy_Button(button *btn);

#endif /* BUTTON_H_SENTRY_ ends here. */
