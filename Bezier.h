#pragma once

#include "vector2.h"

namespace Bez2Fun
{
  struct Bezier3
  {
    Vector2 p0, p1, p2, p3;
  };

  Vector2 calcBezier(Bezier3 b, double t)
  {
    return {
        b.p0.x * (1.0 - t) * (1.0 - t) * (1.0 - t) + 3.0 * b.p1.x * (1.0 - t) * (1.0 - t) * t + 3.0 * b.p2.x * (1.0 - t) * t * t + b.p3.x * t * t * t,
        b.p0.y * (1.0 - t) * (1.0 - t) * (1.0 - t) + 3.0 * b.p1.y * (1.0 - t) * (1.0 - t) * t + 3.0 * b.p2.y * (1.0 - t) * t * t + b.p3.y * t * t * t};
  }
}; // namespace Bez2Fun
