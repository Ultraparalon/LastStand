#include "Drone.hpp"

Drone::Drone() {}
Drone::Drone(eTexture t, int y, int x)
{
  this->setTexture(t);
  this->setPosY(y);
  this->setPosX(x);
  this->setHeight(32);
  this->setWidth(32);
}
Drone::~Drone() {}

eTask Drone::getTask() const
{
  return m_task;
}

void Drone::setTask(eTask t)
{
  m_task = t;
}

void Drone::doTask(std::list<std::shared_ptr<IUnit>> & lu)
{
  if (m_task)
  {
    if (m_task == MOVE)
    {
      if (!move())
      {
        m_task = INACTION;
      }
    }
    else if (m_task == TAKE)
    {
      // std::cout << "TAKE" << std::endl;
      if (!this->move())
      {
        std::shared_ptr<IUnit> tmp = Uo::find(lu, BASE);
        // std::cout << "Found Base" << std::endl;
        if (tmp != nullptr)
        {
          m_destY = tmp->getPosY();
          m_destX = tmp->getPosX();
          m_task = DELIVER;
        }
        else
        {
          m_task = INACTION;
        }
      }
    }
    else if (m_task == DELIVER)
    {
      if (this->move())
      {
        m_target->setPosY(getPosY());
        m_target->setPosX(getPosX());
      }
      else
      {
        m_task = INACTION;
        m_target->setTask(INACTION);
        m_target = nullptr;
      }
    }
    else if (m_task == REPAIR)
    {
      if (this->move())
      {

      }
      else
      {
        if (m_target->damaged())
        {
          m_target->repair(m_repairPower);
        }
        else
        {
          m_target->setTask(INACTION);
          m_target = nullptr;
          m_task = INACTION;
        }
      }
    }
  }
  else
  {
    for (std::list<std::shared_ptr<IUnit>>::iterator it = lu.begin();
      it != lu.end(); it++)
    {
      if ((*it)->getTexture() == BASE)
      {
        if (getPosY() != (*it)->getPosY()
          || getPosX() != (*it)->getPosX())
        {
          m_task = MOVE;
          this->setDestination((*it)->getPosY(), (*it)->getPosX());
        }
        return ;
      }
    }
  }
}

void Drone::setTarget(std::shared_ptr<IUnit> unit)
{
  m_target = unit;
}

bool Drone::move()
{
  if (this->getPosY() == m_destY
    && this->getPosX() == m_destX)
  {
    return false;
  }
  else
  {
  	if (this->getPosY() != m_destY)
  	{
      this->moveY(getPosY() > m_destY ? -1 : 1);
  	}
  	if (this->getPosX() != m_destX)
  	{
      this->moveX(getPosX() > m_destX ? -1 : 1);
  	}
  }
  return true;
}

void Drone::setDestination(int const y, int const x)
{
  m_destY = y;
  m_destX = x;
}
