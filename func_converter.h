#pragma once

#include <iostream>

#include "vector2.h"
#include "bezier.h"

#define N 500
#define ETA 0.2

namespace Bez2Fun
{
  inline double calcYChilda4d(double a0, double a1, double a2, double a3, double a4, double a5, double x)
  {
    return a0 * x * x * x * x * x + a1 * x * x * x * x + a2 * x * x * x + a3 * x * x + a4 * x + a5;
  }

  void funcEstimation(Bezier3 bezier, double *res_params)
  {
    double a0 = 5.0;
    double a1 = 5.0;
    double a2 = 5.0;
    double a3 = 5.0;
    double a4 = 5.0;
    double a5 = 5.0;

    for (int k = 0; k < 10000; k++)
    {
#pragma region a0
      double a0_new;
      double dE_da0 = .0;
      for (int i = 0; i < N; i++)
      {
        double t_i = (double)i / (double)N;
        Vector2 b = calcBezier(bezier, t_i);
        dE_da0 += (b.y - calcYChilda4d(a0, a1, a2, a3, a4, a5, b.x)) * b.x * b.x * b.x * b.x * b.x;
      }
      dE_da0 *= -2.0 / (double)N;
      a0_new = a0 - ETA * dE_da0;
      a0 = a0_new;
#pragma endregion a0

#pragma region a1
      double a1_new;
      double dE_da1 = .0;
      for (int i = 0; i < N; i++)
      {
        double t_i = (double)i / (double)N;
        Vector2 b = calcBezier(bezier, t_i);
        dE_da1 += (b.y - calcYChilda4d(a0, a1, a2, a3, a4, a5, b.x)) * b.x * b.x * b.x * b.x;
      }
      dE_da1 *= -2.0 / (double)N;
      a1_new = a1 - ETA * dE_da1;
      a1 = a1_new;
#pragma endregion a1

#pragma region a2
      double a2_new;
      double dE_da2 = .0;
      for (int i = 0; i < N; i++)
      {
        double t_i = (double)i / (double)N;
        Vector2 b = calcBezier(bezier, t_i);
        dE_da2 += (b.y - calcYChilda4d(a0, a1, a2, a3, a4, a5, b.x)) * b.x * b.x * b.x;
      }
      dE_da2 *= -2.0 / (double)N;
      a2_new = a2 - ETA * dE_da2;
      a2 = a2_new;
#pragma endregion a2

#pragma region a3
      double a3_new;
      double dE_da3 = .0;
      for (int i = 0; i < N; i++)
      {
        double t_i = (double)i / (double)N;
        Vector2 b = calcBezier(bezier, t_i);
        dE_da3 += (b.y - calcYChilda4d(a0, a1, a2, a3, a4, a5, b.x)) * b.x * b.x;
      }
      dE_da3 *= -2.0 / (double)N;
      a3_new = a3 - ETA * dE_da3;
      a3 = a3_new;
#pragma endregion a3

#pragma region a4
      double a4_new;
      double dE_da4 = .0;
      for (int i = 0; i < N; i++)
      {
        double t_i = (double)i / (double)N;
        Vector2 b = calcBezier(bezier, t_i);
        dE_da4 += (b.y - calcYChilda4d(a0, a1, a2, a3, a4, a5, b.x)) * b.x;
      }
      dE_da4 *= -2.0 / (double)N;
      a4_new = a4 - ETA * dE_da4;
      a4 = a4_new;
#pragma endregion a4

#pragma region a5
      double a5_new;
      double dE_da5 = .0;
      for (int i = 0; i < N; i++)
      {
        double t_i = (double)i / (double)N;
        Vector2 b = calcBezier(bezier, t_i);
        dE_da5 += (b.y - calcYChilda4d(a0, a1, a2, a3, a4, a5, b.x));
      }
      dE_da5 *= -2.0 / (double)N;
      a5_new = a5 - ETA * dE_da5;
      a5 = a5_new;
#pragma endregion a5
    }

    std::cout << a0 << "x^5+" << a1 << "x^4+" << a2 << "x^3+" << a3 << "x^2+" << a4 << "x+" << a5 << std::endl;

    res_params[0] = a0;
    res_params[1] = a1;
    res_params[2] = a2;
    res_params[3] = a3;
    res_params[4] = a4;
    res_params[5] = a5;

  }

}; // namespace Bez2Fun