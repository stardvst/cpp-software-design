#pragma once

template <typename Shape>
class DrawStrategy
{
public:
  virtual ~DrawStrategy() = default;
  virtual void draw(const Shape &shape/*, some arguments*/) const = 0;
};
