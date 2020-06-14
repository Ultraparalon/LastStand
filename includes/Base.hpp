#pragma once

#include "IUnit.hpp"
#include "UnitFactory.hpp"

#include "ResKeeper.hpp"

class Base : public IUnit
{
public:
  Base(eTexture, int, int, int, ResKeeper *);
  ~Base();

  eTask getTask() const;
  void setTask(eTask);
  void doTask(std::list<std::shared_ptr<IUnit>> &);

  void setTarget(std::shared_ptr<IUnit>);
  void setDestination(int const y, int const x);

private:
  ResKeeper * m_rk = nullptr;

  eTask m_task = INACTION;

  std::shared_ptr<IUnit> m_target = nullptr;
	
};
