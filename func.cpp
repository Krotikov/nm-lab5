#include "func.h"

double Func(double x, double y) {
  double res = -(2.0 * y / x + pow(x, 4) * pow(y, 3) * exp(x));
  return res;
}

double FuncSol(double x) {
  double res = 1.0 / sqrt(2 * pow(x, 4) * exp(x));
  return res;
}