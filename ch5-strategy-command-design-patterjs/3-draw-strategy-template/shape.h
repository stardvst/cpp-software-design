#pragma once

class Shape
{
public:
  Shape() = default;
  virtual ~Shape() = default;

  virtual void draw(/*some arguments*/) const = 0;
  virtual void serialize(/*some arguments*/) const = 0;
};
