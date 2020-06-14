#pragma once

class ResKeeper
{
public:
  ResKeeper();
  ~ResKeeper();

  int getDrone() const;
  int getOre() const;

  void changeDrone(int const);
  void changeOre(int const);

private:
  int m_drone = 2;
  int m_ore = 0;

};
