#include "test.h"


int main() {

  TestErr(&FuncSol, &Func);

  TestMaxErr(&FuncSol, &Func);

  TestDisturbUPD(&FuncSol, &Func);

  return 0;
}