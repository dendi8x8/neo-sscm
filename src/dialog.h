#ifndef DIALOG_H_SENTRY_
#define DIALOG_H_SENTRY_

#include <raylib.h>
#include "gui.h"

dialog *Create_Dialog(Rectangle *rec, char **lines, int count);
void Draw_Dialog(dialog *diag);
void Destroy_Dialog(dialog* diag);

#endif /* DIALOG_H_SENTRY_ ends here. */
