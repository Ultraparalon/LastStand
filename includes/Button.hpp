#pragma once

#include <vector>
#include <utility>

#include "Drawable.hpp"
// #include "GameLogic.hpp"

class Button : public Drawable
{
public:
  Button();
  Button(eTexture, int, int, std::vector<std::pair<int, int>>);
  ~Button();

  int getID() const;

  void setID(int const);

  bool isClicked(int const, int const);

  void onClick();

private:
  int m_actionID = 0;
  std::vector<std::pair<int, int>> m_area;
  
};
