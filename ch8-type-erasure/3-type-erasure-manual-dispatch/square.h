#pragma once

class Square
{
public:
  explicit Square(double side) : m_side{side} {}

  double side() const { return m_side; }

private:
  double m_side{};
};

inline bool operator==(const Square &lhs, const Square &rhs)
{
  return lhs.side() == rhs.side();
}
