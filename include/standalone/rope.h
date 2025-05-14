#pragma once

#include <cmath>
#include <cstdlib>
#include <stdio.h>

#include <algorithm>
#include <vector>

#include "raylib.h"

struct Point {
  int x;
  int y;
};

struct Rope {
private:
  std::vector<Point> seeds;
  int w;
  int h;

public:
  Rope(int w, int h) : w(w), h(h) {
    printf("Initialize Rope\n");
  }

  ~Rope() {
  }

  void Render() {
    DrawText("Rope", 10, 10, 24, BLACK);
  }
};
