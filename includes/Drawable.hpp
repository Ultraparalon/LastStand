#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <string>
#include <cmath>

#include <vector>
#include <utility>

const int def_texture_size = 32;

enum eTexture
{
  GRASS,
  BUSH,
  ORE,
  TILE,
  BASE,
  DRONE,
  MINER,
  WHITE,
  CARGOORE,
  TURRET,
  ENEMY,
  CHOICEWHEEL,
  TEXT
};

struct Rect
{
  Rect(int v1, int v2, int v3, int v4)
    : y(v1), x(v2), h(v3), w(v4) {}
  int y;
  int x;
  int h;
  int w;  
};

struct Circ
{
  Circ(int v1, int v2, int v3)
    : y(v1), x(v2), r(v3) {}
  int y;
  int x;
  int r;
};

class Drawable
{
public:
  Drawable();
  Drawable(const int, const int, const eTexture);
  Drawable(const int, const int,
    const eTexture, const std::string);
  Drawable(const int, const int, const int, const int,
    const eTexture, const std::string);
  ~Drawable();

  int getPosY() const;
  int getPosX() const;
  int getHeight() const;
  int getWidth() const;
  eTexture getTexture() const;
  std::string getName() const;
  float getScale() const;
  Rect getRect() const;

  void setPosY(const int);
  void setPosX(const int);
  void setPos(const int y, const int x);
  void setHeight(const int);
  void setWidth(const int);
  void setName(const std::string);
  void setTexture(const eTexture);
  void setScale(const float);

  void moveY(const int);
  void moveX(const int);
  void rescale(const float);

  bool operator==(Drawable const &) const;
  bool operator!=(Drawable const &) const;

private:
  Rect m_rect;
  float m_scale = 1;

  eTexture m_texture;
  std::string m_name;
	
};


class Collision
{
public:
  static bool rectpoint(Rect const & r,
    int const py, int const px)
  {
    return (px >= r.x
      && px <= r.x + r.w
      && py >= r.y
      && py <= r.y + r.h);
  }

  static bool rectangle(Rect const & r1, Rect const & r2)
  {
    return (r1.x + r1.w >= r2.x
      && r1.x <= r2.x + r2.w
      && r1.y + r1.h >= r2.y
      && r1.y <= r2.y + r2.h);
  }

  static bool rectCircle(Rect const & r, Circ const & c)
  {
    int tx = c.x;
    int ty = c.y;

    if (c.x < r.x)
      tx = r.x;
    else if (c.x > r.x + r.w)
      tx = r.x + r.w;

    if (c.y < r.y)
      ty = r.y;
    else if (c.y > r.y + r.h)
      ty = r.y + r.h;

    int distx = c.x - tx;
    int disty = c.y - ty;
    int distance = sqrt((distx * distx) + (disty * disty));

    return (distance <= c.r);
  }

  static bool polypoint(std::vector<std::pair<int, int>> const & p, int y, int x)
  {
    bool collision = false;
    int next = 0;

    for (int current = 0; current < p.size(); current++)
    {
      next = current + 1;
      if (next == p.size())
      {
        next = 0;
      }
      std::pair<int, int> pc = p[current];
      std::pair<int, int> pn = p[next];

      if (((pc.first >= y && pn.first < y)
        || (pc.first < y && pn.first >= y))
        && (x < (pn.second - pc.second) * (y - pc.first) / (pn.first - pc.first) + pc.second))
      {
        collision = !collision;
      }
    }
    return collision;
  }
};

typedef Collision Cl;

#endif