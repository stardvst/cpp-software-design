#include <iostream>
#include <memory>
#include "duck.h"
#include "turkey.h"

// pretend turkey is a duck

class TurkeyAdapter : public Duck
{
public:
  explicit TurkeyAdapter(std::unique_ptr<Turkey> turkey)
      : m_turkey{std::move(turkey)}
  {
  }

  void quack() override
  {
    std::cout << "A duck-like turkey quacking: ";
    m_turkey->gobble();
  }

  void fly() override
  {
    std::cout << "A duck-like turkey flying: ";
    m_turkey->fly();
  }

private:
  std::unique_ptr<Turkey> m_turkey;
};
