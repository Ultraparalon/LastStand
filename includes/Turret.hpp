#pragma once

#include "IUnit.hpp"

class Turret : public IUnit
{
public:
  Turret();
  Turret(eTexture, int, int, int);
  ~Turret();

  eTask getTask() const;
  void setTask(eTask);
  void doTask(std::list<std::shared_ptr<IUnit>> &);

  void setTarget(std::shared_ptr<IUnit>);
  void setDestination(int const y, int const x);

private:
  eTask m_task = INACTION;
  int m_progress = 0;
  int m_radius = 32 * 5;
  int m_damage = 1;

  std::shared_ptr<IUnit> m_target = nullptr;
	
};
