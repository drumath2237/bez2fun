#include <iostream>

#include "vector2.h"
#include "bezier.h"
#include "func_converter.h"

using namespace Bez2Fun;
using namespace std;

int main()
{
  Bezier3 bezier = {
      {-1.0, -1.0},
      {-0.2, -0.8},
      {0.4, 0.8},
      {1.0, 1.0}};

  double res[6] = {0.0};

  funcEstimation(bezier, res);

  cout << res[0] << " "
        << res[1] << " "
        << res[2] << " "
        << res[3] << " "
        << res[4] << " "
        << res[5] << " "
        << endl;

  return 0;
}