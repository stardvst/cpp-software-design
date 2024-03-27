#include <iostream>
#include "circle.h"
#include "square.h"
#include "translate.h"

void Translate::visit(const Circle &circle) const
{
  std::cout << "translating circle...\n";
}

void Translate::visit(const Square &square) const
{
  std::cout << "translating square...\n";
}
