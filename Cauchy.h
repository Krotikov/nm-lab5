#ifndef CAUCHY_H
#define CAUCHY_H

#include "GridFunc.h"

class Cauchy {
public:
  Cauchy(GridFunc const& grid, double (*func)(double, double));

  double MaxErr();

  bool PrintErr(std::string fileName);

  bool PrintY(std::string fileName);

  ~Cauchy() {
    delete[] resY;
  }

  point_t a;
  double (*func)(double, double);
  GridFunc grid;
  double* resY;
};



#endif //CAUCHY_H