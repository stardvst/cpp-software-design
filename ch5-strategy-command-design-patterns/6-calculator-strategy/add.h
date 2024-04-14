#pragma once

#include "calculatorStrategy.h"

class Add : public CalculatorStrategy
{
public:
  explicit Add(int operand) : m_operand(operand) {}

  int compute(int i) const override
  {
    return i + m_operand;
  }

private:
  int m_operand{};
};
