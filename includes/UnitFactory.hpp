#pragma once

#include "IUnit.hpp"
#include "ResKeeper.hpp"
#include "Base.hpp"
#include "Drone.hpp"
#include "Miner.hpp"
#include "CargoOre.hpp"
#include "Turret.hpp"
#include "Enemy.hpp"

class UnitFactory
{
public:
  UnitFactory();
  ~UnitFactory();

  static uptr getUnit(eTexture const,
  	int const, int const, ResKeeper *);

private:
  static uptr getBase(int const, int const, ResKeeper *);
  static uptr getDrone(int const, int const);
  static uptr getMiner(int const, int const);
  static uptr getCargoOre(int const, int const);
  static uptr getTurret(int const, int const);
  static uptr getEnemy(int const, int const);

};

typedef UnitFactory Uf;
