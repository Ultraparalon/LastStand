#pragma once

#include "IUnit.hpp"

class CargoOre : public IUnit
{
public:
  CargoOre();
  CargoOre(eTexture, int, int, int);
  ~CargoOre();

  eTask getTask() const;
  void setTask(eTask);
  void doTask(std::list<std::shared_ptr<IUnit>> &);

  void setTarget(std::shared_ptr<IUnit>);
  void setDestination(int const y, int const x);

private:
  eTask m_task = INACTION;
  int m_progress = 0;

  std::shared_ptr<IUnit> m_target = nullptr;
	
};
