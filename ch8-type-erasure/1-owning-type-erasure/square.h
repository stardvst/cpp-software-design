#pragma once

class Square
{
public:
  explicit Square(double side) : m_side{side} {}

  double side() const { return m_side; }

private:
  double m_side{};
};
