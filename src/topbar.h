#ifndef TOPBAR_H_SENTRY
#define  TOPBAR_H_SENTRY

#include <raylib.h>
#include "button.h"
#include "topbar_actions.h"

typedef struct {
    Rectangle   rec;
    Color       color;
    button      **buttons;
    int         btns_count;
} topbar;

topbar * Create_Topbar(Rectangle *rec, Color color, button **buttons, int count);
void Draw_Topbar(topbar *bar);
void Handle_Topbar(topbar *bar);
void Destroy_Topbar(topbar *bar);
topbar * Create_Main_Topbar(actions_table *table);
void Destroy_Main_Topbar(topbar *bar);


#endif /* TOPBAR_H_SENTRY */
