#include "Structure.hpp"

Structure::Structure() {}
Structure::Structure(eTexture t, int y, int x, int size)
  : Drawable(y, x, size, size, t, "Structure") {}
Structure::~Structure() {}

void Structure::takeDamage(int val)
{
  if (m_shield)
  {
  	m_shield = (m_shield > val) ? m_shield - val : 0;
  }
  else if (m_hp)
  {
  	m_hp = (m_hp > val) ? m_hp - val : 0;
  }
}

void Structure::repair(int val)
{
  m_hp += val;
  m_hp = (m_hp > m_maxHp) ? m_maxHp : m_hp;
}

bool Structure::damaged()
{
  return (m_hp != m_maxHp);
}

bool Structure::dead()
{
  return (m_hp <= 0);
}

void Structure::onClick()
{
  std::cout << "HP " << m_hp << '/' << m_maxHp << std::endl;
  std::cout << "Shield" << m_shield << '/' << m_maxShield << std::endl;
}

//Setters--------------
// void Structure::setTexture(eTexture t)
// {
//   m_texture = t;
// }

// void Structure::setPosY(int val)
// {
//   m_posY = val;
// }

// void Structure::setPosX(int val)
// {
//   m_posX = val;
// }

// void Structure::setSize(int val)
// {
//   m_size = val;
// }

//Getters-----
// eTexture Structure::getTexture() const
// {
//   return m_texture;
// }

// int Structure::getPosY() const
// {
//   return m_posY;
// }

// int Structure::getPosX() const
// {
//   return m_posX;
// }

// int Structure::getSize() const
// {
//   return m_size;
// }
