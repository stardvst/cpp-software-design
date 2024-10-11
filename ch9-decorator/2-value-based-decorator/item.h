#pragma once

#include "money.h"

class Item
{
public:
  virtual ~Item() = default;
  virtual Money price() const = 0;
};
