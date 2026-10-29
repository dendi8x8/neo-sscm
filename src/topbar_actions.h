#ifndef TOPBAR_ACTIONS_H_SENTRY
#define TOPBAR_ACTIONS_H_SENTRY

#include "button.h"
#include <raylib.h>

enum { TB_Actions_Count = 2 };
enum {
    TB_Action_Edit,
    TB_Action_About
};

typedef struct
{
    button_callback actions[TB_Actions_Count];
} actions_table;

actions_table * TB_Init_Actions_Table();
void show_edit_dialog(void *param);
void show_about_dialog(void *param);
void TB_Destroy_Actions_Table(actions_table *table);

#endif /* TOPBAR_ACTIONS_H_SENTRY */
