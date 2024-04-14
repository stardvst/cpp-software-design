#pragma once

class CalculatorStrategy
{
public:
  virtual ~CalculatorStrategy() = default;

  virtual int compute(int i) const = 0;
};
