#pragma once

#include "IUnit.hpp"
#include "UnitFactory.hpp"

class Miner : public IUnit
{
public:
  Miner();
  Miner(eTexture, int, int, int);
  ~Miner();

  eTask getTask() const;
  void setTask(eTask);
  void doTask(std::list<std::shared_ptr<IUnit>> &);

  void setTarget(std::shared_ptr<IUnit>);
  void setDestination(int const y, int const x);

private:
  eTask m_task = MINE;
  int m_progress = 0;

  std::shared_ptr<IUnit> m_target = nullptr;
	
};