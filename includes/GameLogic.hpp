#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#include <iostream>

#include <list>
#include <vector>

#include "Drawable.hpp"
#include "InputKeeper.hpp"

#include "Cell.hpp"
#include "Structure.hpp"
#include "IUnit.hpp"
#include "ResKeeper.hpp"

#include "Button.hpp"
#include "ChoiceWheel.hpp"
#include "UnitFactory.hpp"

// class Button;

class GameLogic
{
public:
  GameLogic();
  ~GameLogic();

  void getSurface(std::list<Drawable> &);
  // void getStructure(std::list<Drawable> &);
  void getUnit(std::list<Drawable> &);
  void getUI(std::list<Drawable> &);

  void inputHandle(InputKeeper &);
  void tick();

private:
  // TaskManager tm;

  std::vector<std::vector<Cell>> map;
  // std::list<Structure> construction;
  std::list<Button> buttons;
  std::list<std::shared_ptr<IUnit>> units;

  ChoiceWheel cw;

  int mapSize = 100;
  int posY = 0;
  int posX = 0;
  int cell = 32;
  int screen_w = 1920;
  int screen_h = 1080;

  int mouseY = 0;
  int mouseX = 0;
  float scale = 1;

  eLMBAction m_lmba = CLICK;
  eTexture m_build = GRASS;

  ResKeeper m_rk;

  // void setLMBBuild();
  bool clickUnit(int const, int const);

  // IScene * scene;
	
};

#endif