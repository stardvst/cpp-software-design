#pragma once

#include <utility>

template <typename T, typename Tag>
struct StrongType
{
public:
  using value_type = T;

  explicit StrongType(const T &value) : m_value{value} {}

  T &       get()       { return m_value; }
  const T & get() const { return m_value; }

private:
  T m_value;
};
