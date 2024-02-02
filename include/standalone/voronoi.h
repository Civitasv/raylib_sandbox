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

struct Voronoi {
private:
  std::vector<Point> seeds;
  Point *buffer_a;
  Point *buffer_b;
  bool read_from_a; // if read from buffer_a
  bool need_noise;  // if we need firstly generate noise
  bool applied_noise;
  int round_when_applied_noise;
  int round_needed_when_applied_noise;
  int w;
  int h;
  int step;
  Point *r_buffer;
  Point *w_buffer;

public:
  Voronoi(int w, int h) : w(w), h(h) {
    printf("Initialize Voronoi\n");

    buffer_a = new Point[w * h];
    buffer_b = new Point[w * h];

    GeneratePoints();
    Initialize();
  }

  ~Voronoi() {
    delete[] buffer_a;
    delete[] buffer_b;
  }

  int Random(int a, int b) { return a + rand() % (b - a + 1); }

  void GeneratePoints() {
    srand(time(0));
    int number = 200;
    for (int i = 0; i < number; i++) {
      int x = Random(0, w); // 0 + rand() % (w + 1);
      int y = Random(0, h); // 0 + rand() % (h + 1);

      printf("Point: {%d, %d}\n", x, y);

      seeds.push_back({x, y});
    }
  }

  void Initialize() {
    read_from_a = true;
    need_noise = false;
    applied_noise = false;
    round_when_applied_noise = 0;
    round_needed_when_applied_noise = std::log10(seeds.size()) + 1;
    printf("Round: %d\n", round_needed_when_applied_noise);

    step = std::max(w, h) / 2; // initial step

    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        int idx = (y * w + x);
        buffer_a[idx].x = -1;
        buffer_a[idx].y = -1;
      }
    }
    for (int i = 0; i < seeds.size(); i++) {
      buffer_a[(seeds[i].y * w + seeds[i].x)] = seeds[i];
    }
  }

  void ApplyNoise() {
    srand(time(0));

    if (read_from_a) {
      printf("Read from a, write to b\n");
      r_buffer = buffer_a;
      w_buffer = buffer_b;
    } else {
      printf("Read from b, write to a\n");
      r_buffer = buffer_b;
      w_buffer = buffer_a;
    }

    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        int idx = (y * w + x);
        Point &p = r_buffer[idx];

        if (p.x == -1 && p.y == -1) {
          // add noise
          int ridx = Random(0, seeds.size() - 1);
          //   printf("Random id: %d\n", ridx);
          w_buffer[idx] = seeds[ridx];
        }
      }
    }

    read_from_a = !read_from_a; // swap it
    applied_noise = true;
  }

  void Calculate() {
    if (seeds.size() == 0) {
      return;
    }

    int count = 0;

    if (step == 0 || (need_noise && round_when_applied_noise ==
                                        round_needed_when_applied_noise + 1)) {
      Initialize();
      return;
    }

    if (step >= 1) {
      printf("Step: %d\n", step);
      if (read_from_a) {
        printf("Read from a, write to b\n");
        r_buffer = buffer_a;
        w_buffer = buffer_b;
      } else {
        printf("Read from b, write to a\n");
        r_buffer = buffer_b;
        w_buffer = buffer_a;
      }

      // We can easily pallralize this part
      for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
          int idx = (y * w + x);
          Point &p = r_buffer[idx];
          w_buffer[idx] = p; // closest candidate
          if (p.x == x && p.y == y) {
            continue; // it is a seed
          }

          float dist = -1;
          if (p.x == -1 && p.y == -1) {
            dist = -1; // No closest seed has been fount for this point
          } else {
            dist = (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
          }

          // Retrieve 8 points
          for (int m = -1; m <= 1; m++) {   // y direction
            for (int n = -1; n <= 1; n++) { // x direction
              int ny = y + m * step;
              int nx = x + n * step;
              if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                continue;
              }
              int nidx = (ny * w + nx);
              Point &pk = r_buffer[nidx];
              if (pk.x == -1 && pk.y == -1) {
                continue; // empty point
              }
              float new_dist =
                  (pk.x - x) * (pk.x - x) + (pk.y - y) * (pk.y - y);
              if (dist == -1 || new_dist < dist) {
                count++;
                w_buffer[idx] = pk;
                dist = new_dist;
              }
            }
          }
        }
      }
      printf("Step: %d, count: %d\n", step, count);

      if (need_noise) {
        step /= 3;
        round_when_applied_noise++;
      } else {
        step /= 2;
      }
      read_from_a = !read_from_a; // swap it
    }
  }

  void Next() {
    if (need_noise && !applied_noise) {
      ApplyNoise();
    } else {
      Calculate();
    }
  }

  void Render() {
    Point *buffer = read_from_a ? buffer_a : buffer_b;
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        Point &p = buffer[y * w + x];
        if (p.x != -1 && p.y != -1) {
          unsigned char r = (p.y / (h * 1.0f)) * 255;
          unsigned char g = (p.x / (h * 1.0f)) * 255;
          unsigned char b = 255;
          unsigned char a = 255;
          DrawPixel(x, y, Color{r, g, b, a});
        }
      }
    }
  }
};
