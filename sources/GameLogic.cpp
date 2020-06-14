#include "GameLogic.hpp"

GameLogic::GameLogic() //: tm(construction, units)
{
  for (int y = 0; y < mapSize; y++)
  {
  	map.push_back(std::vector<Cell>());
  	for (int x = 0; x < mapSize; x++)
  	{
  	  map[y].push_back(Cell());
  	}
  }

  // units.push_back(std::shared_ptr<IUnit>(new Base(BASE, 0, 0, 160));
  // units.push_back(std::shared_ptr<IUnit>(new Base(BASE, 10 * cell, 10 * cell, 160, m_rk)));
  units.push_back(Uf::getUnit(BASE, 10 * cell, 10 * cell, &m_rk));
  units.push_back(Uf::getUnit(MINER, 5 * cell, 12 * cell, nullptr));
  units.push_back(Uf::getUnit(MINER, 5 * cell, 11 * cell, nullptr));
  units.push_back(Uf::getUnit(MINER, 5 * cell, 10 * cell, nullptr));

  map[5][10].setCovering(ORE);
  map[5][11].setCovering(ORE);
  map[5][12].setCovering(ORE);

  units.push_back(Uf::getUnit(DRONE, 4 * cell, 9 * cell, nullptr));
  units.push_back(Uf::getUnit(TURRET, 7 * cell, 8 * cell, nullptr));
  units.back()->takeDamage(100);
  units.back()->takeDamage(50);
  units.push_back(Uf::getUnit(ENEMY, 10 * cell, 20 * cell, nullptr));

}
GameLogic::~GameLogic() {}

void GameLogic::getSurface(std::list<Drawable> & rhs)
{
  int scaled = cell * scale;

  for (int y = 0; y <= screen_h / scaled + 1; y++)
  {
  	for (int x = 0; x <= screen_w / scaled + 1; x++)
  	{
  	  if (y + (posY / cell) >= 0
  	  	&& y + (posY / cell) < mapSize
  	  	&& x + (posX / cell) >= 0
  	  	&& x + (posX / cell) < mapSize)
  	  {
        Cell & tmp = map[y + (posY / cell)][x + (posX / cell)];
  	  	rhs.push_back(Drawable(
  	  		((y) * cell - (posY % cell)), // * scale,
  	  		((x) * cell - (posX % cell)), // * scale,
  	  		cell, cell,
  	  		tmp.getSurface(),
  	  		"map"));
        rhs.back().setScale(scale);
        rhs.push_back(rhs.back());
        rhs.back().setTexture(tmp.getCovering());
  	  }
  	}
  }
}

// void GameLogic::getStructure(std::list<Drawable> & rhs)
// {
//   Rect screen = {posY, posX,
//     posY + static_cast<int>(screen_h / scale),
//     posX + static_cast<int>(screen_w / scale)
//   };

//   for (std::list<Structure>::iterator it = construction.begin();
//     it != construction.end(); it++)
//   {
//     Rect rect = it->getRect();
//     if (rectangeCollision(rect, screen))
//     {
//       rhs.push_back(Drawable(rect.y - posY, rect.x - posX,
//         rect.h, rect.w, it->getTexture(),
//       "struct"));
//       rhs.back().setScale(scale);
//     }
//   }
// }

void GameLogic::getUnit(std::list<Drawable> & rhs)
{
  Rect screen = {posY, posX,
    posY + static_cast<int>(screen_h / scale),
    posX + static_cast<int>(screen_w / scale)
  };

  for (std::list<std::shared_ptr<IUnit>>::iterator it = units.begin();
    it != units.end(); it++)
  {
    Rect rect = (*it)->getRect();
    if (Cl::rectangle(rect, screen))
    {
      rhs.push_back(Drawable((rect.y - posY), // * scale,
        (rect.x - posX), // * scale,
        rect.h, rect.w, (*it)->getTexture(),
      "unit"));
      rhs.back().setScale(scale);
    }
  }
}

void GameLogic::getUI(std::list<Drawable> & rhs)
{
  for (int x = 0; x < screen_w / cell; x++)
  {
    rhs.push_back(Drawable(0, x * cell, cell, cell, WHITE, "test"));
  }
  rhs.push_back(Drawable(0, 0, TEXT, std::to_string(m_rk.getDrone())));
  rhs.push_back(Drawable(0, 4 * cell, TEXT, std::to_string(m_rk.getOre())));
  cw.getDrawable(rhs);
  if (m_build)
  {
    rhs.push_back(Drawable(
      (mouseY / scale) - (static_cast<int>(mouseY / scale + posY) % cell),
      (mouseX / scale) - (static_cast<int>(mouseX / scale + posX) % cell),
      m_build));
    rhs.back().setScale(scale);
  }
  // rhs.push_back(Drawable(1 * cell, 0 * cell, 96, 96, CHOICEWHEEL, "CW"));
}

int makeScale(int mouse, float scale, float quantity)
{
  return ((mouse / scale) * (scale + quantity) - mouse) / (scale + quantity); 
}

bool GameLogic::clickUnit(int const y, int const x)
{
  for (std::list<std::shared_ptr<IUnit>>::iterator it = units.begin();
    it != units.end(); it++)
  {
    if (Cl::rectpoint((*it)->getRect(), posY + y, posX + x))
    {
      (*it)->onClick();
      return true;
    }
  }
  return false;
}

void GameLogic::inputHandle(InputKeeper & ik)
{
  // static int mouseY = ik.getMouseY();
  // static int mouseX = ik.getMouseX();

  if (ik.getKeyW())
  {
  	posY -= 16;
  }
  if (ik.getKeyS())
  {
  	posY += 16;
  }
  if (ik.getKeyA())
  {
  	posX -= 16;
  }
  if (ik.getKeyD())
  {
  	posX += 16;
  }

  if (ik.getLMB())
  {
    if (m_lmba == CLICK)
    {
      if (!clickUnit(ik.getMouseY(), ik.getMouseX()))
      {
        cw.init(ik.getMouseY(), ik.getMouseX());
        m_lmba = CHOOSE;
      }
    }
    else if (m_lmba == CHOOSE)
    {
      m_lmba = cw.click(ik.getMouseY(), ik.getMouseX());
      m_build = cw.getBuild();
    }
    else if (m_lmba == COVERING)
    {
      int y = ((posY * scale) + ik.getMouseY()) / (cell * scale);
      int x = ((posX * scale) + ik.getMouseX()) / (cell * scale);
      
      if (map[y][x].getCovering() == BUSH)
      {
        map[y][x].setCovering(TILE);
      }
      m_lmba = CLICK;
      m_build = GRASS;
    }
    else if (m_lmba == BUILDING)
    {
      bool collision = false;
      uptr tmp = Uf::getUnit(m_build,
        posY + ik.getMouseY() / scale - static_cast<int>(posY + ik.getMouseY() / scale) % cell,
        posX + ik.getMouseX() / scale - static_cast<int>(posX + ik.getMouseX() / scale) % cell,
      // (mouseY / scale) - (static_cast<int>(mouseY / scale + posY) % cell),
      // (mouseX / scale) - (static_cast<int>(mouseX / scale + posX) % cell),
        // ((posY * scale) + ik.getMouseY()) / (cell * scale),
        // ((posX * scale) + ik.getMouseX()) / (cell * scale),
        nullptr);
      // std::cout << 
      for (std::list<uptr>::iterator it = units.begin();
        it != units.end(); it++)
      {
        if (Cl::rectangle((*it)->getRect(), tmp->getRect()))
        {
          collision = true;
        }
      }
      if (!collision)
      {
        units.push_back(tmp);
        m_lmba = CLICK;
        m_build = GRASS;
      }
      // else
      // {

      // }
    }
    else if (m_lmba == SPAWNING)
    {
      units.push_back(Uf::getUnit(ENEMY,
        ik.getMouseY() / scale + posY,
        ik.getMouseX() / scale + posX,
        nullptr));
      m_lmba = CLICK;
      m_build = GRASS;
    }



    // std::cout << "Scale: " << scale << std::endl;
    // std::cout << x << std::endl;
    // std::cout << posX << ' ' << ik.getMouseX() << std::endl;
    // std::cout << "Mouse unscaled: " << ik.getMouseX() / scale << std::endl;

  	// map[y][x].setCovering((map[y][x].getCovering() == BUSH) ? TILE : BUSH);

    ik.unsetMouseButton(1);
  }

  if (ik.getRMB())
  {
  	posY -= (ik.getMouseY() - mouseY) / scale;
  	posX -= (ik.getMouseX() - mouseX) / scale;
  }

  //Zoom
  if (ik.getKeyPlus() && scale < 4)
  {
    posY += makeScale(ik.getMouseY(), scale, 0.1f);
    posX += makeScale(ik.getMouseX(), scale, 0.1f);
    scale += 0.1f;
    
    ik.unsetKeyButton(1 << 5);
  }
  if (ik.getKeyMinus() && scale > 1)
  {
    posY += makeScale(ik.getMouseY(), scale, -0.1f);
    posX += makeScale(ik.getMouseX(), scale, -0.1f);
    scale -= 0.1f;

    ik.unsetKeyButton(1 << 6); 
  }

  //3.6 + 0.6 = 4.2
  //1.2 + -0.4 = 0.8
  //1.2 + -1.4 = -0.2

  //1 + -1.0 = 0
  // -1.0 + (1 - -1.0 + 1)

  if (ik.getScroll())
  {
    float scroll = static_cast<float>(ik.getScroll()) / 10;

    if (scale + scroll < 1)
    {
      scroll = scroll + (1 - scroll - scale);
    }
    if (scale + scroll > 4)
    {
      scroll = scroll - (scale + scroll - 4);
    }

    posY += makeScale(ik.getMouseY(), scale, scroll);
    posX += makeScale(ik.getMouseX(), scale, scroll);
    scale += scroll;
    ik.setScroll(0);
  }

  if (mapSize * cell * scale < screen_h)
  {
    posY = 0;
  }
  else
  {
    if (posY < 0)
    {
      posY = 0;
    }
    else if ((mapSize * cell - posY) * scale < screen_h)
    {
      posY = mapSize * cell - (screen_h / scale);
    }
  }

  if (mapSize * cell * scale < screen_w)
  {
    posX = 0;
  }
  else
  {
    if (posX < 0)
    {
      posX = 0;
    }
    else if ((mapSize * cell - posX) * scale < screen_w)
    {
      posX = mapSize * cell - (screen_w / scale);
    }
  }

  // std::cout << "PosX: " << posX << std::endl;
  mouseY = ik.getMouseY();
  mouseX = ik.getMouseX();
  
}

void GameLogic::tick()
{
  for (std::list<std::shared_ptr<IUnit>>::iterator it = units.begin();
    it != units.end();)
  {
    if ((*it)->dead())
    {
      // delete (*it);
      it = units.erase(it);
    }
    else
    {
      (*it)->doTask(units);
      it++;
    }
  }
}

// void GameLogic::setLMBAction(eL)
// {
//   m_lmba = BUILD;
// }

