#include "Cauchy.h"

Cauchy::Cauchy(GridFunc const& grid, double (*func)(double, double))
  :grid(grid), func(func), a(grid.points[0]), resY(new double[grid.numOfPoints]) {

  resY[0] = a.y;
  double h = grid.dx;

  for (size_t i = 0; i < grid.numOfPoints - 1; ++i) {
    double k1 = func(grid.points[i].x, resY[i]);
    double k2 = func((grid.points[i].x + h / 3.0), (resY[i] + k1 * h / 3.0));
    double k3 = func((grid.points[i].x + 2.0 * h / 3.0), (resY[i] - k1 * h / 3.0 + k2 * h));
    double k4 = func((grid.points[i].x + h), (resY[i] + k1 * h - k2 * h + k3 * h));
    resY[i + 1] = resY[i] + h / 8.0 * (k1 + 3 * k2 + 3 * k3 + k4);
  }
}

Cauchy::Cauchy(GridFunc const& grid, double (*func)(double, double), double y0)
  :grid(grid), func(func), a(grid.points[0]), resY(new double[grid.numOfPoints]) {

  resY[0] = y0;
  double h = grid.dx;
  for (size_t i = 0; i < grid.numOfPoints - 1; ++i) {
    double k1 = func(grid.points[i].x, resY[i]);
    double k2 = func((grid.points[i].x + h / 3.0), (resY[i] + k1 * h / 3.0));
    double k3 = func((grid.points[i].x + 2 * h / 3.0), (resY[i] - k1 * h / 3.0 + k2 * h));
    double k4 = func((grid.points[i].x + h), (resY[i] + k1 * h - k2 * h + k3 * h));
    resY[i + 1] = resY[i] + h / 8.0 * (k1 + 3 * k2 + 3 * k3 + k4);
  }
}

double Cauchy::ErrInPoint() {
  double err = fabs(resY[1] - grid.points[1].y);
  return err;
}

double Cauchy::MaxErr() {
  double max = 0;
  for (size_t i = 1; i < grid.numOfPoints; ++i) {
    double err = fabs(resY[i] - grid.points[i].y);
    if (max < err)
      max = err;
  }
  return max;
}

bool Cauchy::PrintErr(std::string fileName) {
  std::ofstream out;

  if (fileName == "cout") {
    std::ostream &out = std::cout;
  }
  else {
    out.open(fileName);
    if (!out.is_open()) {
      return false;
    }
  }
  for (size_t i = 0; i < grid.numOfPoints; ++i) {
    double err = fabs(resY[i] - grid.points[i].y);
    out << err << " ";
  }
  out.close();
  return true;
}

bool Cauchy::PrintY(std::string fileName) {
  std::ofstream out;

  if (fileName == "cout") {
    std::ostream& out = std::cout;
  }
  else {
    out.open(fileName);
    if (!out.is_open()) {
      return false;
    }
  }
  for (size_t i = 0; i < grid.numOfPoints; ++i)
    out << resY[i] << " ";

  out.close();
  return true;
}


//other methods

//Cauchy::Cauchy(GridFunc const& grid, double (*func)(double, double))
//  :grid(grid), func(func), a(grid.points[0]), resY(new double[grid.numOfPoints]) {
//
//  resY[0] = a.y;
//  for (size_t i = 0; i < grid.numOfPoints - 1; ++i) {
//    double h = (grid.rbord - grid.lbord) / grid.numOfPoints;
//    double k1 = func(grid.points[i].x, resY[i]);
//    double k2 = func((grid.points[i].x + h / 2.0), (resY[i] + k1 * h / 2.0));
//    double k3 = func((grid.points[i].x + h / 2.0), (resY[i] - k2 * h / 2.0));
//    double k4 = func((grid.points[i].x + h), (resY[i] + k3 * h));
//    resY[i + 1] = resY[i] + h / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
//  }
//}

//Cauchy::Cauchy(GridFunc const& grid, double (*func)(double, double))
//  :grid(grid), func(func), a(grid.points[0]), resY(new double[grid.numOfPoints]) {
//
//  resY[0] = a.y;
//  for (size_t i = 0; i < grid.numOfPoints - 1; ++i) {
//    double h = (grid.rbord - grid.lbord) / grid.numOfPoints;
//    double k1 = func(grid.points[i].x, resY[i]);
//    double k2 = func((grid.points[i].x + h / 2.0), (resY[i] + k1 * h / 2.0));
//    double k3 = func((grid.points[i].x + h), (resY[i] - k1 * h + 2 * h * k2));
//    resY[i + 1] = resY[i] + h / 6.0 * (k1 + 4 * k2 + k3);
//  }
//}

//Cauchy::Cauchy(GridFunc const& grid, double (*func)(double, double))
//  :grid(grid), func(func), a(grid.points[0]), resY(new double[grid.numOfPoints]) {
//
//  resY[0] = a.y;
//  for (size_t i = 0; i < grid.numOfPoints - 1; ++i) {
//    double h = (grid.rbord - grid.lbord) / grid.numOfPoints;
//    double k1 = func(grid.points[i].x, resY[i]);
//    double k2 = func((grid.points[i].x + h), (resY[i] + k1 * h));
//    resY[i + 1] = resY[i] + h / 2.0 * (k1 + k2);
//  }
//}

//Cauchy::Cauchy(GridFunc const& grid, double (*func)(double, double))
//  :grid(grid), func(func), a(grid.points[0]), resY(new double[grid.numOfPoints]) {
//
//  resY[0] = a.y;
//  for (size_t i = 0; i < grid.numOfPoints - 1; ++i) {
//    double h = (grid.rbord - grid.lbord) / grid.numOfPoints;
//    double k1 = func(grid.points[i].x, resY[i]);
//    double k2 = func((grid.points[i].x + h/2.0), (resY[i] + k1 * h / 2.0));
//    resY[i + 1] = resY[i] + h * k2;
//  }
//}

//Cauchy::Cauchy(GridFunc const& grid, double (*func)(double, double))
//  :grid(grid), func(func), a(grid.points[0]), resY(new double[grid.numOfPoints]) {
//
//  resY[0] = a.y;
//  double h = (grid.rbord - grid.lbord) / (grid.numOfPoints - 1);
//
//  for (size_t i = 0; i < grid.numOfPoints - 1; ++i) {
//    double k1 = func(grid.points[i].x, resY[i]);
//    resY[i + 1] = resY[i] + h * k1;
//  }
//}

//Cauchy::Cauchy(GridFunc const& grid, double (*func)(double, double))
//  :grid(grid), func(func), a(grid.points[0]), resY(new double[grid.numOfPoints]) {
//
//  resY[0] = a.y;
//  for (size_t i = 0; i < grid.numOfPoints - 1; ++i) {
//    double h = (grid.rbord - grid.lbord) / grid.numOfPoints;
//    double k1 = func(grid.points[i].x, resY[i]);
//    resY[i + 1] = resY[i];
//  }
//}