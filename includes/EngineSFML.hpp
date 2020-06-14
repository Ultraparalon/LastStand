#ifndef ENGINESFML_HPP
#define ENGINESFML_HPP

#include "IEngine.hpp"
#include "GuiSFML.hpp"
// #include "AudioSFML.hpp"
#include "InputSFML.hpp"

#include "Drawable.hpp"
#include "InputKeeper.hpp"

class EngineSFML : public IEngine
{
public:
  EngineSFML();
  ~EngineSFML();

  void drawBackground();
  void drawObject(Drawable const &);
  void drawText(Drawable const &);
  void renderFrame();

  void readInput(InputKeeper &);

  void playMusic();
  void playSound();

private:
  GuiSFML m_gui;
  InputSFML m_input;
  // AudioSFML m_audio;

  sf::RenderWindow m_window;
	
};

#endif