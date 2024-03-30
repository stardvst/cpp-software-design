#pragma once

#include <iostream>
#include "abstractVisitor.h"
#include "visitor.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"

class Draw
  : public AbstractVisitor
  , public Visitor<Circle>
  , public Visitor<Square>
  , public Visitor<Triangle>
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

  void visit(const Triangle &triangle) const
  {
    std::cout << "drawing triangle... p1=(" << triangle.p1().x << ", " << triangle.p1().y << "), p2=(" << triangle.p2().x << ", " << triangle.p2().y << "), p3=(" << triangle.p3().x << ", " << triangle.p3().y << ")\n";
  }
};
