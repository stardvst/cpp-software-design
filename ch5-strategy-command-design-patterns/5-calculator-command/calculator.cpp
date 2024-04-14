#include "calculator.h"

void Calculator::compute(std::unique_ptr<CalculatorCommand> command)
{
  m_value = command->execute(m_value);
  m_commands.push(std::move(command));
}

void Calculator::undoLast()
{
  if (m_commands.empty())
    return;

  auto command = std::move(m_commands.top());
  m_value = command->undo(m_value);
  m_commands.pop();
}

int Calculator::result() const
{
  return m_value;
}

void Calculator::clear()
{
  m_value = 0;
  CommandStack{}.swap(m_commands);
}
