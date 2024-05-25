#pragma once

#include <utility>
#include "addable.h"

template <typename T, typename Tag>
struct StrongType : private Addable<StrongType<T, Tag>>
{
public:
  using value_type = T;

  explicit StrongType(const T &value) : m_value{value} {}

  T &       get()       { return m_value; }
  const T & get() const { return m_value; }

private:
  T m_value;
};
