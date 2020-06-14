#pragma once

#include <list>
#include <iostream>

#include "Structure.hpp"

enum eTask
{
  INACTION,
  MOVE,
  ATTACK,
  REPAIR,
  DONE,
  MINE,
  WAIT,
  TAKE,
  DELIVER
};

class IUnit : public Structure
{
  public:
  virtual ~IUnit() {}

  virtual void setTask(eTask) = 0;
  virtual eTask getTask() const = 0;
  virtual void doTask(std::list<std::shared_ptr<IUnit>> &) = 0;

  virtual void setTarget(std::shared_ptr<IUnit>) = 0;
  virtual void setDestination(int const, int const) = 0;

  // virtual void onClick();

};

class UnitOperation
{
public:
  static std::shared_ptr<IUnit> find(std::list<std::shared_ptr<IUnit>> & lu,
    eTexture const type)
  {
    for (std::list<std::shared_ptr<IUnit>>::iterator it = lu.begin();
      it != lu.end(); it++)
    {
      if ((*it)->getTexture() == type)
        return *it;
    }
    return nullptr;
  }
};

typedef UnitOperation Uo;
typedef std::shared_ptr<IUnit> uptr;

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
