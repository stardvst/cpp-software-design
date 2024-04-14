#pragma once

#include <stack>
#include "calculatorCommand.h"

class Calculator
{
public:
  void compute(std::unique_ptr<CalculatorCommand> command);
  void undoLast();

  int result() const;
  void clear();

private:
  using CommandStack = std::stack<std::unique_ptr<CalculatorCommand>>;

  CommandStack m_commands{};
  int m_value{};
};
