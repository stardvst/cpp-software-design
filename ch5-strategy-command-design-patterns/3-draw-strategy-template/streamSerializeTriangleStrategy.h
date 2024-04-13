#pragma once

#include <iostream>
#include "serializeStrategy.h"
#include "triangle.h"

class StreamSerializeTriangleStrategy : public SerializeStrategy<Triangle>
{
public:
  virtual void serialize(const Triangle &triangle /*, some arguments*/) const override
  {
    std::cout << "serializing triangle...\n";
  }
};
