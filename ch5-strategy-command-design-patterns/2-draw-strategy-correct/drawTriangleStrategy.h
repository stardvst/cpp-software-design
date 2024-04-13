#pragma once

class Triangle;

class DrawTriangleStrategy
{
public:
  virtual ~DrawTriangleStrategy() = default;
  virtual void draw(const Triangle &triangle /*, some arguments*/) const = 0;
};
