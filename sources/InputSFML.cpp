#include "InputSFML.hpp"

InputSFML::InputSFML(sf::RenderWindow & win) : m_window(win) {}
InputSFML::~InputSFML() {}

static unsigned int mouse(const sf::Mouse::Button button)
{
  switch (button)
  {
  	case sf::Mouse::Left: return 1;
  	case sf::Mouse::Right: return (1 << 1);
    default: return 0;
  }
}

static unsigned int key(const sf::Keyboard::Key key)
{
  switch (key)
  {
    case sf::Keyboard::Escape: return 1;
    case sf::Keyboard::W: return (1 << 1);
    case sf::Keyboard::S: return (1 << 2);
    case sf::Keyboard::A: return (1 << 3);
    case sf::Keyboard::D: return (1 << 4);
    case sf::Keyboard::Add: return (1 << 5);
    case sf::Keyboard::Subtract: return (1 << 6);
    default: return 0;
  }
}

// static unsigned int scroll(const sf::Mouse::WheelScroll wheel)
// {
//   switch (wheel)
//   {
//     case sf::Mouse::
//   }
// }

#include <iostream>

void InputSFML::read(InputKeeper & ik)
{
  sf::Event event;

  while (m_window.pollEvent(event))
  {
  	switch (event.type)
  	{
  	  case sf::Event::MouseMoved:
  	    ik.setMouseY(event.mouseMove.y);
  	    ik.setMouseX(event.mouseMove.x);
  	    break;
  	  case sf::Event::MouseButtonPressed:
  	    ik.setMouseButton(mouse(event.mouseButton.button));
  	    break;
  	  case sf::Event::MouseButtonReleased:
  	    ik.unsetMouseButton(mouse(event.mouseButton.button));
  	    break;
  	  case sf::Event::KeyPressed:
  	    ik.setKeyButton(key(event.key.code));
  	    break;
  	  case sf::Event::KeyReleased:
  	    ik.unsetKeyButton(key(event.key.code));
        break;
      case sf::Event::MouseWheelScrolled:
        if (event.mouseWheelScroll.wheel
            == sf::Mouse::VerticalWheel)
        {
          ik.setScroll(event.mouseWheelScroll.delta);
        }
        else if (event.mouseWheelScroll.wheel
                  == sf::Mouse::HorizontalWheel)
        {
          ;
        }
        break;
  	  case sf::Event::Closed:
  	    ik.setSystem(1);
  	    break;
      default: ;
  	}
  }
}
