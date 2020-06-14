#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

#include <iostream>

#include "Drawable.hpp"

class Structure : public Drawable
{
public:
  Structure();
  Structure(eTexture, int, int, int);
  ~Structure();

  void takeDamage(int);
  void repair(int);
  bool damaged();
  bool dead();

  void onClick();

  // void setTexture(eTexture);
  // void setPosY(int);
  // void setPosX(int);
  // void setSize(int);

  // eTexture getTexture() const;
  // int getPosX() const;
  // int getPosY() const;
  // int getSize() const;

private:
  int m_hp = 100;
  int m_maxHp = 100;
  int m_shield = 100;
  int m_maxShield = 100;

};

#endif