#ifndef CELL_HPP
#define CELL_HPP

#include <list>

#include "Drawable.hpp"

class Cell
{
public:
  Cell();
  ~Cell();

  void setSurface(eTexture);
  void setCovering(eTexture);
  // void setStructure(Structure *);

  eTexture getSurface() const;
  eTexture getCovering() const;
  // std::list<int> & getUnits();
  // Structure * getStructure();

private:
  eTexture m_surface;
  eTexture m_covering;
  // std::list<int> m_units;
  // Structure * m_structure = nullptr;

};

#endif