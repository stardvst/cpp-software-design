#pragma once

#include "electricEngine.h"
// now electric car is tied to electric engine...

class ElectricCar
{
public:
  ElectricCar(/* args */)
    : m_engine(/* args */)
  {
  }

  void drive() {}

private:
  ElectricEngine m_engine;
};
