#ifndef INPUTKEEPER_HPP
#define INPUTKEEPER_HPP

class InputKeeper
{
public:
  InputKeeper();
  ~InputKeeper();

  void setMouseY(const int);
  void setMouseX(const int);
  void setMouseButton(const unsigned int);
  void setKeyButton(const unsigned int);
  void setSystem(const unsigned int);
  void setScroll(const int);

  void unsetMouseButton(const unsigned int);
  void unsetKeyButton(const unsigned int);

  int getMouseY() const;
  int getMouseX() const;
  int getScroll() const;
  bool getLMB() const;
  bool getRMB() const;
  bool getEsc() const;
  bool getKeyW() const;
  bool getKeyS() const;
  bool getKeyA() const;
  bool getKeyD() const;
  bool getKeyPlus() const;
  bool getKeyMinus() const;
  bool getClose() const;

private:
  int m_mousey;
  int m_mousex;
  int m_scroll = 0;
  unsigned int m_mouse;
  unsigned int m_keyboard;
  unsigned int m_system;
	
};

#endif