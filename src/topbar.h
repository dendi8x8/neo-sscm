#ifndef TOPBAR_H_SENTRY
#define  TOPBAR_H_SENTRY

#include <raylib.h>
#include "gui.h"

topbar * Create_Topbar();
void Draw_Topbar(topbar *bar);
void Handle_Topbar(topbar *bar);
void Destroy_Topbar(topbar *bar);

#endif
