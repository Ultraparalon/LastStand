#include "Button.hpp"

Button::Button() {}
Button::Button(eTexture t, int y, int x,
  std::vector<std::pair<int, int>> area)
  : m_area(area)
{
  this->setTexture(t);
  this->setPosY(y);
  this->setPosX(x);
}
Button::~Button() {}

int Button::getID() const
{
  return m_actionID;
}

void Button::setID(int const val)
{
  m_actionID = val;
}

bool Button::isClicked(int const y, int const x)
{
  std::vector<std::pair<int, int>> tmp;

  for (std::vector<std::pair<int, int>>::iterator it = m_area.begin();
    it != m_area.end(); it++)
  {
    tmp.push_back(std::make_pair(it->first + getPosY(),
      it->second + getPosX()));
  }
  return Cl::polypoint(tmp, y, x);
}
