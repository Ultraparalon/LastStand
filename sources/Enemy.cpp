#include "Enemy.hpp"

Enemy::Enemy() {}
Enemy::Enemy(eTexture t, int y, int x, int size)
{
  this->setTexture(t);
  this->setPosY(y);
  this->setPosX(x);
  this->setHeight(size);
  this->setWidth(size);
}
Enemy::~Enemy() {}

eTask Enemy::getTask() const
{
  return m_task;
}

void Enemy::setTask(eTask t)
{
  m_task = t;
}

void Enemy::doTask(std::list<std::shared_ptr<IUnit>> & lu)
{
  if (m_task)
  {
    if (m_task == MOVE)
    {
      move();
      if (Cl::rectangle(getRect(), m_target->getRect()))
      {
        m_task = ATTACK;
      }
    }
    if (m_task == ATTACK)
    {
      m_target->takeDamage(m_damage);
      if (m_target->dead())
      {
        m_target = nullptr;
        m_task = INACTION;
      }
    }
  }
  else
  {
    findTarget(lu);
  }
}

void Enemy::setTarget(std::shared_ptr<IUnit> unit)
{
  m_target = unit;
}

bool Enemy::move()
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

void Enemy::setDestination(int const y, int const x)
{
  m_destY = y;
  m_destX = x;
}

void Enemy::findTarget(std::list<std::shared_ptr<IUnit>> & lu)
{
  std::shared_ptr<IUnit> tmp = Uo::find(lu, BASE);
  if (tmp)
  {
    setTarget(tmp);
    setDestination(tmp->getPosY(), tmp->getPosX());
    m_task = MOVE;
  }
}
