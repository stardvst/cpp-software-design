#pragma once

#include "calculatorStrategy.h"

class Subtract : public CalculatorStrategy
{
public:
  explicit Subtract(int operand) : m_operand(operand) {}

  int compute(int i) const override
  {
    return i - m_operand;
  }

private:
  int m_operand{};
};
