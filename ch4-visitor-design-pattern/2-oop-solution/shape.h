#pragma once

class Shape
{
public:
  Shape() = default;
  virtual ~Shape() = default;

  virtual void draw() const = 0;
  virtual void serialize() const = 0;
};
