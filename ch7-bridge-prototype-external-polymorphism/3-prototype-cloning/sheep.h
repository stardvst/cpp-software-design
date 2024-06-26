#pragma once

#include "animal.h"
#include <string>
#include <iostream>

struct Sheep : Animal
{
  explicit Sheep(std::string n) : name(std::move(n))
  {
  }

  void makeSound() const override
  {
    std::cout << "baa\n";
  }

  std::unique_ptr<Animal> clone() const override
  {
    return std::make_unique<Sheep>(*this);
  }

  std::string name;
};
