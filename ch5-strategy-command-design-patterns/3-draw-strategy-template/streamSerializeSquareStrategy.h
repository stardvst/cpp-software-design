#pragma once

#include <iostream>
#include "serializeStrategy.h"
#include "circle.h"

class StreamSerializeCircleStrategy : public SerializeStrategy<Circle>
{
public:
  virtual void serialize(const Circle &circle /*, some arguments*/) const override
  {
    std::cout << "serializing circle...\n";
  }
};
