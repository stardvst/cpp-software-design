#pragma once

#include "engine.h"
#include <memory>

class Car
{
public:
  virtual ~Car() = default;
  virtual void drive() = 0;

protected:
  Car(std::unique_ptr<Engine> engine)
      : m_engine(std::move(engine))
  {
  }

  Engine        *getEngine()        { return m_engine.get(); }
  const Engine  *getEngine() const  { return m_engine.get(); }

  std::unique_ptr<Engine> m_engine;
};
