#include <iostream>
#include "calculator.h"
#include "add.h"
#include "subtract.h"

int main()
{
  Calculator calculator;

  auto op1 = std::make_unique<Add>(3);
  auto op2 = std::make_unique<Add>(7);
  auto op3 = std::make_unique<Subtract>(4);
  auto op4 = std::make_unique<Subtract>(2);

  calculator.compute(std::move(op1)); // 0+3
  calculator.compute(std::move(op2)); // 3+7
  calculator.compute(std::move(op3)); // 10-4
  calculator.compute(std::move(op4)); // 6-2

  calculator.undoLast(); // 4+2

  std::cout << "result: " << calculator.result() << '\n';

  calculator.clear();
}
