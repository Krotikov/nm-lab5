#include "test.h"

static std::string FileName(std::string str, size_t symb) {
  char sym = symb + '0';
  std::string beg("Func/");
  std::string tmp = str + sym + ".txt";
  std::string res = beg + tmp;
 
  return res;
}

void TestErr(double(*funcSol)(double), double(*funcR)(double, double)) {
  double lbord = LBORD;
  double rbord = RBORD;
  size_t numNods[] = { NUMP1, NUMP2 };

  for (size_t i = 0; i < 2; ++i) {
    GridFunc grid(lbord, rbord, numNods[i], funcSol);
    Cauchy sol(grid, funcR);

    sol.PrintY(FileName("CalcRes", i + 1));
    sol.PrintErr(FileName("ErrFor", i + 1));
    grid.PrintGrid(FileName("XGridFor", i + 1) , FileName("YGridFor", i + 1));
  }

  return;
}

void TestMaxErr(double(*funcSol)(double), double(*funcR)(double, double)) {
  double lbord = LBORD;
  double rbord = RBORD;
  size_t numNods = 1;

  std::ofstream xout, err, hout;

  xout.open("len.txt");
  err.open("err.txt");
  hout.open("h.txt");

  for (size_t i = 1; i < 16; ++i) {
    numNods *= 2;
    GridFunc grid(lbord, rbord, numNods, funcSol);
    Cauchy sol(grid, funcR);

    double maxErr = sol.MaxErr();
    double h = (rbord - lbord) / numNods;
    double hMod = pow(h, ORDER);

    xout << h << " ";
    err << maxErr << " ";   
    hout << hMod << " ";
  }
  xout.close();
  err.close();
  hout.close();

  return;
}