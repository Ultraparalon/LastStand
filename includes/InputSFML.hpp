#ifndef INPUTSFML_HPP
#define INPUTSFML_HPP

#include <SFML/Graphics.hpp>

#include "InputKeeper.hpp"

class InputSFML
{
public:
  InputSFML(sf::RenderWindow &);
  ~InputSFML();

  void read(InputKeeper &);

private:
  sf::RenderWindow & m_window;
	
};

#endif