#include <stdio.h>
#include <raylib.h>

int main(void)
{
  const int width = 800, height = 600;

  InitWindow(width, height, "SSCM");

  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }
  printf("Hello, World\n");
  CloseWindow();
  return 0;
}
