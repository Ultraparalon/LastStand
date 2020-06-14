#include "Base.hpp"
#include <iostream>

Base::Base(eTexture t, int y, int x, int size, ResKeeper * rk)
 : m_rk(rk)
{
  this->setTexture(t);
  this->setPosY(y);
  this->setPosX(x);
  this->setHeight(size);
  this->setWidth(size);

}
Base::~Base() {}

eTask Base::getTask() const
{
  return m_task;
}

void Base::setTask(eTask t)
{
  m_task = t;
}

void Base::doTask(std::list<std::shared_ptr<IUnit>> & lu)
{
  for (std::list<std::shared_ptr<IUnit>>::iterator it = lu.begin();
  	it != lu.end(); it++)
  {
    if ((*it)->getTexture() == ENEMY)
    {
      continue ;
    }
  	if ((*it)->getTexture() == DRONE
  		&& (*it)->getTask() == INACTION
      && Collision::rectangle(this->getRect(), (*it)->getRect()))
  	{
      m_rk->changeDrone(1);
  	  it = lu.erase(it);
      return ;
  	}
    if ((*it)->getTexture() == CARGOORE
      && (*it)->getTask() == INACTION
      && Collision::rectangle(this->getRect(), (*it)->getRect()))
    {
      m_rk->changeOre(1);
      it = lu.erase(it);
      return ;
    }

    if ((*it)->damaged()
      && (*it)->getTask() != REPAIR)
    {
      (*it)->setTask(REPAIR);
      uptr drone(Uf::getUnit(DRONE, getPosY(), getPosX(), m_rk));
      drone->setTask(REPAIR);
      drone->setTarget(*it);
      drone->setDestination((*it)->getPosY(), (*it)->getPosX());
      m_rk->changeDrone(-1);
      lu.push_back(drone);
      return ;
    }

    if ((*it)->getTexture() == CARGOORE
      && (*it)->getTask() == INACTION
      && m_rk->getDrone())
    {
      (*it)->setTask(WAIT);
      uptr drone(Uf::getUnit(DRONE, getPosY(), getPosX(), m_rk));
      drone->setTarget(*it);
      drone->setTask(TAKE);
      // std::cout << "created new drone" << std::endl;
      drone->setDestination((*it)->getPosY(), (*it)->getPosX());
      m_rk->changeDrone(-1);
      lu.push_back(drone);
      return ;
    }
  }
}

void Base::setTarget(std::shared_ptr<IUnit> unit)
{
  m_target = unit;
}

void Base::setDestination(int const y, int const x)
{
  // m_destY = y;
  // m_destX = x;
}
