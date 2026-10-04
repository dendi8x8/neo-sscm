#ifndef TOPBAR_H_SENTRY
#define  TOPBAR_H_SENTRY

#include <raylib.h>
#include "gui.h"

topbar * Create_Topbar();
void Destroy_Topbar(topbar *bar);
void Draw_Topbar(topbar *bar);

#endif
