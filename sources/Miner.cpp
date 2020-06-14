#include "Miner.hpp"

Miner::Miner() {}
Miner::Miner(eTexture t, int y, int x, int size)
{
  this->setTexture(t);
  this->setPosY(y);
  this->setPosX(x);
  this->setHeight(size);
  this->setWidth(size);
}
Miner::~Miner() {}

eTask Miner::getTask() const
{
  return m_task;
}

void Miner::setTask(eTask t)
{
  m_task = t;
}

void Miner::doTask(std::list<std::shared_ptr<IUnit>> & lu)
{
  if (m_progress < 500)
  {
  	m_progress++;
  }
  else
  {
    if (m_progress == 500)
    {
      lu.push_back(Uf::getUnit(CARGOORE, getPosY(), getPosX(), nullptr));
  	  // lu.back()->setTask()
  	  m_progress = 0;
  	}
  }
  
}

void Miner::setTarget(std::shared_ptr<IUnit> unit)
{
  m_target = unit;
}

void Miner::setDestination(int const y, int const x)
{
  // m_destY = y;
  // m_destX = x;
}
