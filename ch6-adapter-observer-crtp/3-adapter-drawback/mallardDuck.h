#pragma once

#include <iostream>
#include "duck.h"

class MallardDuck : public Duck
{
public:
  void quack() override
  {
    std::cout << "MallardDuck::quack()\n";
  }

  void fly() override
  {
    std::cout << "MallardDuck::fly()\n";
  }
};
