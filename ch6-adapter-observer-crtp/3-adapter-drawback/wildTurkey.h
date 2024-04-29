#pragma once

#include <iostream>
#include "turkey.h"

class WildTurkey : public Turkey
{
public:
  void gobble() override
  {
    std::cout << "WildTurkey::gobble()\n";
  }

  void fly() override
  {
    std::cout << "WildTurkey::fly()\n";
  }
};
