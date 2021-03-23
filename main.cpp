#include "test.h"


int main() {
  TestErr(&FuncSol, &Func);

  TestMaxErr(&FuncSol, &Func);

  return 0;
}