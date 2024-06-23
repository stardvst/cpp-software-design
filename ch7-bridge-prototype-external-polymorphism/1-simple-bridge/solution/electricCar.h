#pragma once

#include "car.h"
#include "engine.h"
#include <memory>
#include <iostream>

class ElectricCar : public Car
{
public:
  ElectricCar(/* args */);
  ~ElectricCar();

  void drive() override
  {
    std::cout << "ElectricCar::drive()\n";
  }
};
