#include "InputKeeper.hpp"

InputKeeper::InputKeeper() : m_mousey(0), m_mousex(0), m_mouse(0),
  m_keyboard(0), m_system(0) {}

InputKeeper::~InputKeeper() {}

//Setters---------------------------
void InputKeeper::setMouseY(const int val)
{
  m_mousey = val;
}

void InputKeeper::setMouseX(const int val)
{
  m_mousex = val;
}

void InputKeeper::setMouseButton(const unsigned int val)
{
  m_mouse |= val;
}

void InputKeeper::setKeyButton(const unsigned int val)
{
  m_keyboard |= val;
}

void InputKeeper::setSystem(const unsigned int val)
{
  m_system |= val;
}

void InputKeeper::setScroll(const int val)
{
  m_scroll = val;
}

//Unsetters-------------------------
void InputKeeper::unsetMouseButton(const unsigned int val)
{
  m_mouse &= ~val;
}

void InputKeeper::unsetKeyButton(const unsigned int val)
{
  m_keyboard &= ~val;
}

//Getters---------------------------
int InputKeeper::getMouseY() const
{
  return m_mousey;
}

int InputKeeper::getMouseX() const
{
  return m_mousex;
}

int InputKeeper::getScroll() const
{
  return m_scroll;
}

bool InputKeeper::getLMB() const
{
  return m_mouse & (1);
}

bool InputKeeper::getRMB() const
{
  return m_mouse & (1 << 1);
}

bool InputKeeper::getEsc() const
{
  return m_keyboard & (1 << 0);
}

bool InputKeeper::getKeyW() const
{
  return m_keyboard & (1 << 1);
}

bool InputKeeper::getKeyS() const
{
  return m_keyboard & (1 << 2);
}

bool InputKeeper::getKeyA() const
{
  return m_keyboard & (1 << 3);
}

bool InputKeeper::getKeyD() const
{
  return m_keyboard & (1 << 4);
}

bool InputKeeper::getKeyPlus() const
{
  return m_keyboard & (1 << 5);
}

bool InputKeeper::getKeyMinus() const
{
  return m_keyboard & (1 << 6);
}

bool InputKeeper::getClose() const
{
  return m_system & (1 << 0);
}
