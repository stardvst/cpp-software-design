#pragma once

#include <utility>

template <typename T, typename Tag, template <typename> class... Skills>
struct StrongType : public Skills<StrongType<T, Tag, Skills...>>...
{
public:
  using value_type = T;

  explicit constexpr StrongType(const T &value) : m_value{value} {}

  constexpr T &       get()       noexcept { return m_value; }
  constexpr const T & get() const noexcept { return m_value; }

  void swap(StrongType &other)
  {
    using std::swap;
    swap(m_value, other.m_value);
  }

private:
  T m_value;
};

template <typename T, typename Tag, template <typename> class... Skills>
std::ostream &operator<<(std::ostream &os, const StrongType<T, Tag, Skills...> &o)
{
  os << o.get();
  return os;
}

template <typename T, typename Tag, template <typename> class... Skills>
void swap(StrongType<T, Tag, Skills...> &lhs, StrongType<T, Tag, Skills...> &rhs)
{
  lhs.swap(rhs);
}
