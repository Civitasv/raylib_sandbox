#include "standalone/rope.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450

void ForRope() {
  static Rope rope(WINDOW_WIDTH,
                         WINDOW_HEIGHT); // define as a single instance

  { // Event handle
  }

  { // Rendering
    BeginDrawing();
    ClearBackground(WHITE);
    rope.Render();
    EndDrawing();
  }
}

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Raylib Sandbox");

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  // It is resizable
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  // Enable Multi Sampling Anti Aliasing 4x (if available)
  SetConfigFlags(FLAG_MSAA_4X_HINT);

  while (!WindowShouldClose()) {
    ForRope();
  }

  CloseWindow();

  return 0;
}
