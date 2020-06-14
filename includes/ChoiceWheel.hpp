#pragma once

#include <vector>
#include <list>

// #include "GameLogic.hpp"
#include "Drawable.hpp"
#include "Button.hpp"

enum eLMBAction
{
  CLICK,
  CHOOSE,
  BUILDING,
  COVERING,
  SPAWNING
};

class ChoiceWheel
{
public:
  ChoiceWheel();
  ~ChoiceWheel();

  void init(int const, int const);

  eTexture getBuild() const;

  void setActive(bool const);

  void getDrawable(std::list<Drawable> &);

  eLMBAction click(int const, int const);

private:
  bool m_isActive = false;
  Drawable m_wheel; //(0, 0, 96, 96, CHOICEWHEEL, "wheel");
  std::vector<Button> m_buttons;
  eTexture m_build = GRASS;
};

//aiypwzqp34U99