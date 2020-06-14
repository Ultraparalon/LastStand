#include "CargoOre.hpp"

CargoOre::CargoOre() {}
CargoOre::CargoOre(eTexture t, int y, int x, int size)
{
  this->setTexture(t);
  this->setPosY(y);
  this->setPosX(x);
  this->setHeight(size);
  this->setWidth(size);
}
CargoOre::~CargoOre() {}

eTask CargoOre::getTask() const
{
  return m_task;
}

void CargoOre::setTask(eTask t)
{
  m_task = t;
}

void CargoOre::doTask(std::list<std::shared_ptr<IUnit>> & lu)
{
  
}

void CargoOre::setTarget(std::shared_ptr<IUnit> unit)
{
  m_target = unit;
}

void CargoOre::setDestination(int const y, int const x)
{
  // m_destY = y;
  // m_destX = x;
}
