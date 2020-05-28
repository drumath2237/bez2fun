#include <iostream>

#define N 1000
#define ETA 0.05

struct vector2
{
  double x, y;
};

// set bezier control points
vector2 p0 = {-1.0, -1.0};
vector2 p1 = {0.2, -0.6};
vector2 p2 = {-0.4, 0.6};
vector2 p3 = {1.0, 1.0};

vector2 calcBezier(double t)
{
  return {
      p0.x * (1.0 - t) * (1.0 - t) * (1.0 - t) + 3.0 * p1.x * (1.0 - t) * (1.0 - t) * t + 3.0 * p2.x * (1.0 - t) * t * t + p3.x * t * t * t,
      p0.y * (1.0 - t) * (1.0 - t) * (1.0 - t) + 3.0 * p1.y * (1.0 - t) * (1.0 - t) * t + 3.0 * p2.y * (1.0 - t) * t * t + p3.y * t * t * t};
}

inline double calcYChilda4d(double a0, double a1, double a2, double a3, double a4, double x)
{
  return a0 * x * x * x * x + a1 * x * x * x + a2 * x * x + a3 * x + a4;
}

int main()
{
  // init paramater a
  double a0 = 5.0;
  double a1 = 5.0;
  double a2 = 5.0;
  double a3 = 5.0;
  double a4 = 5.0;

  for (int k = 0; k < 100000; k++)
  {
#pragma region a0
    double a0_new;
    double dE_da0 = .0;
    for (int i = 0; i < N; i++)
    {
      double t_i = (double)i / (double)N;
      vector2 b = calcBezier(t_i);
      dE_da0 += (b.y - calcYChilda4d(a0, a1, a2, a3, a4, b.x)) * b.x * b.x * b.x* b.x;
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
      vector2 b = calcBezier(t_i);
      dE_da1 += (b.y - calcYChilda4d(a0, a1, a2, a3, a4, b.x)) * b.x * b.x* b.x;
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
      vector2 b = calcBezier(t_i);
      dE_da2 += (b.y - calcYChilda4d(a0, a1, a2, a3, a4, b.x)) * b.x * b.x;
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
      vector2 b = calcBezier(t_i);
      dE_da3 += (b.y - calcYChilda4d(a0, a1, a2, a3, a4, b.x))* b.x;
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
      vector2 b = calcBezier(t_i);
      dE_da4 += (b.y - calcYChilda4d(a0, a1, a2, a3, a4, b.x));
    }
    dE_da4 *= -2.0 / (double)N;
    a4_new = a4 - ETA * dE_da4;
    a4 = a4_new;
#pragma endregion a4

  }

  std::cout << a0 << " " << a1 << " " << a2 << " " << a3 << " " << a4 << std::endl;
}