#include "Cell.hpp"

Cell::Cell() : m_surface(GRASS), m_covering(BUSH) {}
Cell::~Cell() {}

void Cell::setSurface(eTexture t)
{
  m_surface = t;
}

void Cell::setCovering(eTexture t)
{
  m_covering = t;
}

// void Cell::setStructure(Structure * s)
// {
//   m_structure = s;
// }


//Geters----
eTexture Cell::getSurface() const
{
  return m_surface;
}

eTexture Cell::getCovering() const
{
  return m_covering;
}
// std::list<int> & Cell::getUnits()
// {
//   return m_units;
// }

// Structure * Cell::getStructure()
// {
//   return m_structure;
// }
