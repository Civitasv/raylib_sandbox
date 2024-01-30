#include "sandbox.h"
#include "voronoi.h"

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 450

void ForVoronoi() {
  static Voronoi voronoi(WINDOW_WIDTH, WINDOW_HEIGHT); // define as a single instance

  { // Event handle
    if (IsKeyPressed(KEY_SPACE)) {
      voronoi.Next();
    }
  }

  { // Rendering
    BeginDrawing();
    ClearBackground(BLACK);
    voronoi.Render();
    EndDrawing();
  }
}

int main()
{
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Raylib Sandbox");

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  // It is resizable
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  // Enable Multi Sampling Anti Aliasing 4x (if available)
  SetConfigFlags(FLAG_MSAA_4X_HINT);

  while (!WindowShouldClose()) {
    ForVoronoi();
  }

  CloseWindow();

  return 0;
}
