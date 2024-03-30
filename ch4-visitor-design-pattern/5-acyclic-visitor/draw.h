#pragma once

#include <iostream>
#include "abstractVisitor.h"
#include "visitor.h"
#include "circle.h"
#include "square.h"

class Draw
  : public AbstractVisitor
  , public Visitor<Circle>
  , public Visitor<Square>
{
public:
  void visit(const Circle &circle) const override
  {
    std::cout << "drawing circle... r=" << circle.radius() << ", center x/y=" << circle.center().x << '/' << circle.center().y << '\n';
  }

  void visit(const Square &square) const override
  {
    std::cout << "drawing square... side=" << square.side() << ", center x/y=" << square.center().x << '/' << square.center().y << '\n';
  }
};
