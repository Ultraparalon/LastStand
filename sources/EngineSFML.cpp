#include "EngineSFML.hpp"

EngineSFML::EngineSFML() : m_gui(m_window), m_input(m_window)
{
  // m_window.create(sf::VideoMode(1280, 1080), "sfml");
  m_window.create(sf::VideoMode(1920, 1080), "sfml");
  // m_window.setKeyRepeatEnabled(false);
  m_window.setFramerateLimit(60);
}

EngineSFML::~EngineSFML()
{
  m_window.close();
}

void EngineSFML::drawBackground()
{
  m_gui.drawBackground();
}

void EngineSFML::drawObject(Drawable const & dr)
{
  m_gui.drawObject(dr);
}

void EngineSFML::drawText(Drawable const & dr)
{
  m_gui.drawText(dr);
}

void EngineSFML::renderFrame()
{
  m_gui.render();
}

void EngineSFML::readInput(InputKeeper & ik)
{
  m_input.read(ik);
}

void EngineSFML::playMusic()
{

}

void EngineSFML::playSound()
{
  
}
