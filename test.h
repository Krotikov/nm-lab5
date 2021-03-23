#ifndef TEST_H
#define TEST_H

#include "Cauchy.h"

#define LBORD 1
#define RBORD 2
#define NUMP1 8
#define NUMP2 16
#define ORDER 4

void TestErr(double(*funcSol)(double), double(*funcR)(double, double));

void TestMaxErr(double(*funcSol)(double), double(*funcR)(double, double));

#endif //TEST_H
