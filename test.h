#ifndef TEST_H
#define TEST_H

#include "Cauchy.h"

#define LBORD 1
#define RBORD 2
#define NUMP1 8
#define NUMP2 16
#define NUMP_DIST 16
#define NUM_NODS_DIST 1000
#define LDIST 4
#define RDIST -4
#define ORDER 4

void TestErr(double(*funcSol)(double), double(*funcR)(double, double));

void TestMaxErr(double(*funcSol)(double), double(*funcR)(double, double));

void TestDisturb(double(*funcSol)(double), double(*funcR)(double, double));

#endif //TEST_H
