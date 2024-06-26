#include "sheep.h"
#include <cstdlib>
#include <memory>

int main()
{
  const std::unique_ptr<Animal> dolly = std::make_unique<Sheep>("Dolly");
  dolly->makeSound();

  const std::unique_ptr<Animal> dollyClone = dolly->clone();
  dollyClone->makeSound();
}
