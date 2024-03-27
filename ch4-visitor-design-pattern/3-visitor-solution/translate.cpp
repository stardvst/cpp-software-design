#include <iostream>
#include "circle.h"
#include "square.h"
#include "triangle.h"
#include "translate.h"

void Translate::visit(const Circle &circle) const
{
  std::cout << "translating circle...\n";
}

void Translate::visit(const Square &square) const
{
  std::cout << "translating square...\n";
}

void Translate::visit(const Triangle &triangle) const
{
  std::cout << "translating triangle...\n";
}
