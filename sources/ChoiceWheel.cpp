#include "ChoiceWheel.hpp"

ChoiceWheel::ChoiceWheel()
{
  m_wheel = Drawable(0, 0, 96, 96, CHOICEWHEEL, "cw");

  std::vector<std::pair<int, int>> tmp;
  tmp.push_back(std::make_pair(0, 0));
  tmp.push_back(std::make_pair(0, 32));
  tmp.push_back(std::make_pair(32, 32));
  tmp.push_back(std::make_pair(32, 0));

  m_buttons.push_back(Button(TILE, 0, 0, tmp));
  m_buttons.back().setID(COVERING);
  m_buttons.push_back(Button(TILE, 0, 0, tmp));
  m_buttons.back().setID(COVERING);
  m_buttons.push_back(Button(ENEMY, 0, 0, tmp));
  m_buttons.back().setID(SPAWNING);
  m_buttons.push_back(Button(TURRET, 0, 0, tmp));
  m_buttons.back().setID(BUILDING);
}
ChoiceWheel::~ChoiceWheel() {}

void ChoiceWheel::init(int const y, int const x)
{
  m_wheel.setPos(y - (m_wheel.getHeight() / 2),
  	x - (m_wheel.getWidth() / 2));

  m_buttons[0].setPos(m_wheel.getPosY(), m_wheel.getPosX() + 32);
  m_buttons[1].setPos(m_wheel.getPosY() + 32, m_wheel.getPosX());
  m_buttons[2].setPos(m_wheel.getPosY() + 32, m_wheel.getPosX() + 64);
  m_buttons[3].setPos(m_wheel.getPosY() + 64, m_wheel.getPosX() + 32);

  m_isActive = true;
}

eTexture ChoiceWheel::getBuild() const
{
  return m_build;
}

void ChoiceWheel::setActive(bool const val)
{
  m_isActive = val;
}

void ChoiceWheel::getDrawable(std::list<Drawable> & rhs)
{
  if (m_isActive)
  {
  	rhs.push_back(m_wheel);

    for (std::vector<Button>::iterator it = m_buttons.begin();
      it != m_buttons.end(); it++)
    {
      rhs.push_back(*it);
    }
  }
}

eLMBAction ChoiceWheel::click(int const y, int const x)
{
  m_isActive = false;

  if (Cl::rectpoint(m_wheel.getRect(), y, x))
  {
    for (std::vector<Button>::iterator it = m_buttons.begin();
      it != m_buttons.end(); it++)
    {
      if (it->isClicked(y, x))
      {
        m_build = it->getTexture();
        return static_cast<eLMBAction>(it->getID());
      }
    }
  }
  m_build = GRASS;
  return CLICK;
}
