#pragma once

#include <iostream>
#include "serializeStrategy.h"
#include "square.h"

class StreamSerializeSquareStrategy : public SerializeStrategy<Square>
{
public:
  virtual void serialize(const Square &square /*, some arguments*/) const override
  {
    std::cout << "serializing square...\n";
  }
};
