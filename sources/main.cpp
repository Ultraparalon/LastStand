#include <list>
#include <iostream>

#include "IEngine.hpp"
#include "EngineSFML.hpp"
#include "InputKeeper.hpp"
#include "GameLogic.hpp"
#include "Drawable.hpp"

int main()
{
  IEngine * engine = new EngineSFML();
  InputKeeper ik;
  GameLogic gl;
  std::list<Drawable> toDraw;

  while (!ik.getClose() && !ik.getEsc())
  {
  	engine->readInput(ik);
  	gl.inputHandle(ik);
    gl.tick();

    engine->drawBackground();

    gl.getSurface(toDraw);
  	for (std::list<Drawable>::iterator it = toDraw.begin();
  		it != toDraw.end(); it++)
  	{
  	  engine->drawObject(*it);
  	}
    toDraw.clear();

    // gl.getStructure(toDraw);
    // for (std::list<Drawable>::iterator it = toDraw.begin();
    //   it != toDraw.end(); it++)
    // {
    //   engine->drawObject(*it);
    // }
    // toDraw.clear();

    gl.getUnit(toDraw);
    for (std::list<Drawable>::iterator it = toDraw.begin();
      it != toDraw.end(); it++)
    {
      engine->drawObject(*it);
    }
    toDraw.clear();

    gl.getUI(toDraw);
    {
      for (std::list<Drawable>::iterator it = toDraw.begin();
      it != toDraw.end(); it++)
      {
        if (it->getTexture() == TEXT)
        {
          engine->drawText(*it);
        }
        else
        {
          engine->drawObject(*it);
        }
      }
    }
    toDraw.clear();

  	engine->renderFrame();
  }
  std::cout << "bye bye" << std::endl;

  system("leaks last_stand");
  return 0;
}
