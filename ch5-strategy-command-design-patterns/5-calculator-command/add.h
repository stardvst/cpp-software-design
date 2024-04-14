#pragma once

#include "calculatorCommand.h"

class Add : public CalculatorCommand
{
public:
  explicit Add(int operand) : m_operand(operand) {}

  int execute(int i) const override
  {
    return i + m_operand;
  }

  int undo(int i) const override
  {
    return i - m_operand;
  }

private:
  int m_operand{};
};
