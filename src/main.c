#include "gui.h"
#include "raylib.h"

int main(void)
{
    const int width = 800, height = 600;

    InitWindow(width, height, "SSCM - tool for creation addons");
    Handle_Window();
    CloseWindow();

    return 0;
}
