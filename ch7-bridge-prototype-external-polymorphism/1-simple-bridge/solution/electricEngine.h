#pragma once

#include "engine.h"
#include <iostream>

class ElectricEngine : public Engine
{
public:
  void start() override
  {
    std::cout << "ElectricEngine::start()\n";
  }

  void stop() override
  {
    std::cout << "ElectricEngine::stop()\n";
  }

private:
  // ...
};
