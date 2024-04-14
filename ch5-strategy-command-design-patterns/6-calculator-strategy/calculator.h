#pragma once

#include <stack>
#include "calculatorStrategy.h"

class Calculator
{
public:
  void set(std::unique_ptr<CalculatorStrategy> operation);
  void compute(int value);

  int result() const;
  void clear();

private:
  std::unique_ptr<CalculatorStrategy> m_operation{};
  int m_value{};
};
