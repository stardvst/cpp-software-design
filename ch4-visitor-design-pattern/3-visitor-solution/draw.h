#pragma once

#include "shapeVisitor.h"

class Draw : public ShapeVisitor
{
public:
  void visit(const Circle &circle) const override;
  void visit(const Square &square) const override;
  void visit(const Triangle &square) const override;
};
