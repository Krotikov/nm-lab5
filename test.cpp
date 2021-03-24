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

  xout.open("maxErr(h)/len.txt");
  err.open("maxErr(h)/err.txt");
  hout.open("maxErr(h)/h.txt");

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

void TestDisturb(double(*funcSol)(double), double(*funcR)(double, double)) {
  std::ofstream xout, maxErr;
  size_t num = NUM_NODS_DIST;

  xout.open("maxErr(y0)/y0Val.txt");
  maxErr.open("maxErr(y0)/maxErr.txt");

  double lbord = LBORD;
  double rbord = RBORD;
  double ldist = LDIST;
  double rdist = RDIST;
  double dx = (rdist - ldist) / num;
  double y0 = ldist;

  for (size_t i = 0; i < num; ++i, y0 += dx) {
    size_t numNods = NUMP_DIST;

    GridFunc grid(lbord, rbord, numNods, funcSol);
    Cauchy sol(grid, funcR, y0);

    double err = sol.MaxErr();

    if (err > 5)
      err = 5;

    xout << y0 << " ";
    maxErr << err << " ";
  }
  xout.close();
  maxErr.close();

  return;
}
