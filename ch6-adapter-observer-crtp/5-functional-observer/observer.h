#include <functional>

template <typename Subject, typename StateTag>
class Observer
{
public:
  using OnUpdate = std::function<void(const Subject &, StateTag)>;

  // No virtual destructor necessary

  explicit Observer(OnUpdate onUpdate)
      : m_onUpdate(onUpdate)
  {
  }

  // Non-virtual update function
  void update(const Subject &subject, StateTag property)
  {
    m_onUpdate(subject, property);
  }

private:
  OnUpdate m_onUpdate{};
};
