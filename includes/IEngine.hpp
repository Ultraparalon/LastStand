#ifndef IENGINE_HPP
#define IENGINE_HPP

#include "Drawable.hpp"
#include "InputKeeper.hpp"

class IEngine
{
public:
  virtual ~IEngine() {};

  virtual void drawBackground() = 0;
  virtual void drawObject(Drawable const &) = 0;
  virtual void drawText(Drawable const &) = 0;
  virtual void renderFrame() = 0;

  virtual void readInput(InputKeeper &) = 0;

  virtual void playMusic() = 0;
  virtual void playSound() = 0;
	
};

#endif