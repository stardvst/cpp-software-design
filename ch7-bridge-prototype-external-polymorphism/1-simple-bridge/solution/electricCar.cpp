#include "electricEngine.h"
#include "electricCar.h"

ElectricCar::ElectricCar(/* args */)
    : Car(std::make_unique<ElectricEngine>(/* args */))
{
  m_engine->start();
}

ElectricCar::~ElectricCar()
{
  m_engine->stop();
}
