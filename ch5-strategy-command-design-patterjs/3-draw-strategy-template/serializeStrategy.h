#pragma once

template <typename Shape>
class SerializeStrategy
{
public:
  virtual ~SerializeStrategy() = default;
  virtual void serialize(const Shape &shape /*, some arguments*/) const = 0;
};
