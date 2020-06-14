#include "GuiSFML.hpp"

sf::Texture GuiSFML::loadtxr(std::string name)
{
  sf::Texture texture;

  if (!texture.loadFromFile(TEXTUREPATH + name))
  {
  	exit(1);
  }
  // texture.setSmooth(true);
  return texture;
}

GuiSFML::GuiSFML(sf::RenderWindow & win) : m_window(win)
{
  if (!m_font.loadFromFile(FONTPATH + "transistor.ttf"))
  {
    exit(1);
  }
  m_textures.push_back(loadtxr("grass.png"));
  m_textures.push_back(loadtxr("bush.png"));
  m_textures.push_back(loadtxr("ore.png"));
  m_textures.push_back(loadtxr("tile.png"));
  m_textures.push_back(loadtxr("base.png"));
  m_textures.push_back(loadtxr("drone.png"));
  m_textures.push_back(loadtxr("miner.png"));
  m_textures.push_back(loadtxr("white.png"));
  m_textures.push_back(loadtxr("cargo_ore.png"));
  m_textures.push_back(loadtxr("turret.png"));
  m_textures.push_back(loadtxr("enemy.png"));
  m_textures.push_back(loadtxr("choicewheel.png"));
}

GuiSFML::~GuiSFML()
{
}

void GuiSFML::drawBackground()
{
  m_window.clear(sf::Color::Black);
}

void GuiSFML::drawObject(Drawable const & dr)
{
  sf::Sprite sprite;
  sprite.setTexture(m_textures[dr.getTexture()]);
  sprite.setPosition(sf::Vector2f(
    // dr.getPosX(), dr.getPosY()));
    dr.getPosX() * dr.getScale(),
    dr.getPosY() * dr.getScale()));
  sprite.setScale(dr.getScale(), dr.getScale());
  m_window.draw(sprite);
}

void GuiSFML::drawText(Drawable const & dr)
{
  sf::Text text;
  text.setFont(m_font);
  text.setString(dr.getName());
  text.setCharacterSize(32);
  text.setFillColor(sf::Color::Black);

  text.setPosition(dr.getPosX(), dr.getPosY());
  m_window.draw(text);
}

void GuiSFML::render()
{
  m_window.display();
}
