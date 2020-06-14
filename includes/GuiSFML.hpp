#ifndef GUISFML_HPP
#define GUISFML_HPP

#include <vector>

#include <SFML/Graphics.hpp>

#include "Drawable.hpp"

class GuiSFML
{
public:
  GuiSFML(sf::RenderWindow &);
  ~GuiSFML();

  void drawBackground();
  void drawObject(Drawable const &);
  void drawText(Drawable const &);
  void render();

private:
  sf::Texture loadtxr(std::string name);

  sf::RenderWindow & m_window;
  std::vector<sf::Texture> m_textures;
  sf::Font m_font;

  const std::string FONTPATH = "resources/fonts/";
  const std::string TEXTUREPATH = "resources/textures/";
  
};

#endif