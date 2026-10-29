#ifndef TOPBAR_ACTIONS_H_SENTRY
#define TOPBAR_ACTIONS_H_SENTRY

#include "button.h"
#include <raylib.h>

enum { TB_Actions_Count = 2 };

typedef struct
{
    button_callback *actions[TB_Actions_Count];
} actions_table;

actions_table * Init_Actions_Table();
void show_about_dialog();

#endif /* TOPBAR_ACTIONS_H_SENTRY */
