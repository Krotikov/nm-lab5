#include "func.h"

double Func(double x, double y) {
  double res = -(2.0 * y / x + pow(x, 4) * pow(y, 3) * exp(x));
  return res;
}

double FuncSol(double x) {
  double res = 1.0 / (x * x * exp(x / 2) * sqrt(2.0));
  return res;
}

double f2(double x, double y) {
  double res = -y * tan(x) + 1.0 / cos(x);
  return res;
}

double fs2(double x) {
  double res = sin(x) + cos(x);
  return res;
}