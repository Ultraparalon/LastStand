#pragma once

#include "IUnit.hpp"
#include <iostream>

class Drone : public IUnit
{
public:
  Drone();
  Drone(eTexture, int, int);
  ~Drone();

  eTask getTask() const;
  void setTask(eTask);
  void doTask(std::list<uptr> &);

  void setTarget(uptr);

  void setDestination(int const y, int const x);

private:
  eTask m_task = INACTION;
  int m_destY;
  int m_destX;

  std::shared_ptr<IUnit> m_target = nullptr;
  int m_repairPower = 1;

  bool move();

};

// class Unit : public Structure
// {
// public:
//   Unit();
//   Unit(eTexture, int, int, int);
//   ~Unit();

//   eTask getTask() const;

//   void setTask(eTask);

//   void move();
//   void setDestination(int, int);

// private:
//   eTask m_task = INACTION;
//   int m_destY;
//   int m_destX;
// };
