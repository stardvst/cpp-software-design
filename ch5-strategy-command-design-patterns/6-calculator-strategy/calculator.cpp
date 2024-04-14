#include "calculator.h"

void Calculator::set(std::unique_ptr<CalculatorStrategy> operation)
{
  m_operation = std::move(operation);
}

void Calculator::compute(int value)
{
  m_value = m_operation->compute(value);
}

int Calculator::result() const
{
  return m_value;
}

void Calculator::clear()
{
  m_value = 0;
  m_operation.reset(nullptr);
}
