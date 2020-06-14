#include "ResKeeper.hpp"

ResKeeper::ResKeeper() {}
ResKeeper::~ResKeeper() {}

int ResKeeper::getDrone() const
{
  return m_drone;
}

int ResKeeper::getOre() const
{
  return m_ore;
}

void ResKeeper::changeDrone(int const val)
{
  m_drone += val;
}

void ResKeeper::changeOre(int const val)
{
  m_ore += val;
}
