#include <iostream>

#include "sandbox.h"


int main()
{
  InitWindow(800, 450, "Raylib Sandbox");

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("This is just a sandbox for raylib", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
