#include "Drawable.hpp"

Drawable::Drawable() : m_rect(0, 0, 0, 0) {}
Drawable::Drawable(const int y, const int x, const eTexture texture)
  :	m_rect(y, x, def_texture_size, def_texture_size),
	m_texture(texture), m_name("test") {}
Drawable::Drawable(const int y, const int x, const eTexture texture,
	const std::string name)
  : m_rect(y, x, def_texture_size, def_texture_size),
	m_texture(texture), m_name(name) {}
Drawable::Drawable(const int y, const int x, const int h, const int w,
	const eTexture txr, const std::string name)
  :	m_rect(y, x, h, w), m_texture(txr), m_name(name) {}
Drawable::~Drawable() {}

//Getters---------------------------
int Drawable::getPosY() const
{
	return m_rect.y;
}

int Drawable::getPosX() const
{
	return m_rect.x;
}

int Drawable::getHeight() const
{
	return m_rect.h;
}

int Drawable::getWidth() const
{
	return m_rect.w;
}

eTexture Drawable::getTexture() const
{
	return m_texture;
}

std::string Drawable::getName() const
{
	return m_name;
}

float Drawable::getScale() const
{
  return m_scale;
}

Rect Drawable::getRect() const
{
  return m_rect;
}

//Setters-----------------------------
void Drawable::setPosY(const int val)
{
	m_rect.y = val;
}

void Drawable::setPosX(const int val)
{
	m_rect.x = val;
}

void Drawable::setPos(const int y, const int x)
{
	m_rect.y = y;
	m_rect.x = x;
}

void Drawable::setHeight(const int val)
{
  m_rect.h = val;
}

void Drawable::setWidth(const int val)
{
  m_rect.w = val;
}

void Drawable::setName(const std::string str)
{
	m_name = str;
}

void Drawable::setTexture(const eTexture t)
{
    m_texture = t;
}

void Drawable::setScale(const float val)
{
  m_scale = val;
}

//--------------------------------------------
void Drawable::moveY(const int val)
{
	m_rect.y += val;
	// m_rect.h += val;
}

void Drawable::moveX(const int val)
{
	m_rect.x += val;
	// m_rect.w += val;
}

void Drawable::rescale(const float val)
{
  m_scale += val;
}


bool Drawable::operator==(Drawable const &d) const {
    return (this->getPosX() == d.getPosX() && this->getPosY() == d.getPosY());
}

bool Drawable::operator!=(Drawable const &d) const {
    return !(*this == d);
}
