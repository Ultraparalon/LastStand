#include "Turret.hpp"

Turret::Turret() {}
Turret::Turret(eTexture t, int y, int x, int size)
{
  this->setTexture(t);
  this->setPosY(y);
  this->setPosX(x);
  this->setHeight(size);
  this->setWidth(size);
}
Turret::~Turret() {}

eTask Turret::getTask() const
{
  return m_task;
}

void Turret::setTask(eTask t)
{
  m_task = t;
}

void Turret::doTask(std::list<std::shared_ptr<IUnit>> & lu)
{
  if (m_task)
  {
    if (m_task == ATTACK)
    {
      m_target->takeDamage(m_damage);
      if (m_target->dead())
      {
        m_task = INACTION;
        m_target = nullptr;
      }
    }

  }
  else
  {
    for (std::list<std::shared_ptr<IUnit>>::iterator it = lu.begin();
      it != lu.end(); it++)
    {
      Circ circ(getPosY(), getPosX(), m_radius);

      if ((*it)->getTexture() == ENEMY)
      {
        if (Cl::rectCircle((*it)->getRect(), circ))
        {
          m_task = ATTACK;
          m_target = *it;
          return ;
        }
      }
    }
  } 
}

void Turret::setTarget(std::shared_ptr<IUnit> unit)
{
  m_target = unit;
}

void Turret::setDestination(int const y, int const x)
{
  // m_destY = y;
  // m_destX = x;
}
