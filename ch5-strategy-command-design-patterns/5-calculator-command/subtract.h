#pragma once

#include "calculatorCommand.h"

class Subtract : public CalculatorCommand
{
public:
  explicit Subtract(int operand) : m_operand(operand) {}

  int execute(int i) const override
  {
    return i - m_operand;
  }

  int undo(int i) const override
  {
    return i + m_operand;
  }

private:
  int m_operand{};
};
