#pragma once

#include <memory>

struct Animal
{
  virtual ~Animal() = default;
  virtual void makeSound() const = 0;

  virtual std::unique_ptr<Animal> clone() const = 0;
};
