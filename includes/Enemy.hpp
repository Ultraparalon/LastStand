#pragma once

#include "IUnit.hpp"
#include <iostream>

class Enemy : public IUnit
{
public:
  Enemy();
  Enemy(eTexture, int, int, int);
  ~Enemy();

  eTask getTask() const;
  void setTask(eTask);
  void doTask(std::list<std::shared_ptr<IUnit>> &);

  void setTarget(std::shared_ptr<IUnit>);
  void setDestination(int const y, int const x);

private:
  eTask m_task = INACTION;
  int m_destY;
  int m_destX;

  std::shared_ptr<IUnit> m_target = nullptr;
  int m_damage = 1;

  bool move();
  void findTarget(std::list<std::shared_ptr<IUnit>> &);

};