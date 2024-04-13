#pragma once

class Circle;
class Square;

class DrawStrategy
{
public:
  virtual ~DrawStrategy() = default;

  virtual void draw(const Circle &circle /*, some arguments*/) const = 0;
  virtual void draw(const Square &square /*, some arguments*/) const = 0;
};
