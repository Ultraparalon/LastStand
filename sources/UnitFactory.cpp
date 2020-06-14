#include "UnitFactory.hpp"

UnitFactory::UnitFactory() {}
UnitFactory::~UnitFactory() {}

uptr UnitFactory::getUnit(eTexture const t,
  int const y, int const x, ResKeeper * rk)
{
  switch (t)
  {
  	case (BASE): return UnitFactory::getBase(y, x, rk); break;
  	case (DRONE): return Uf::getDrone(y, x); break;
  	case (MINER): return Uf::getMiner(y, x); break;
  	case (CARGOORE): return Uf::getCargoOre(y, x); break;
  	case (TURRET): return Uf::getTurret(y, x); break;
  	case (ENEMY): return Uf::getEnemy(y, x); break;
  	default: return nullptr;
  }
}

uptr UnitFactory::getBase(int const y,
	int const x, ResKeeper * rk)
{
  return uptr(new Base(BASE, y, x, 160, rk));
}

uptr UnitFactory::getDrone(int const y, int const x)
{
  return uptr(new Drone(DRONE, y, x));
}

uptr UnitFactory::getMiner(int const y, int const x)
{
  return uptr(new Miner(MINER, y, x, 32));
}

uptr UnitFactory::getCargoOre(int const y, int const x)
{
  return uptr(new CargoOre(CARGOORE, y, x, 32));
}

uptr UnitFactory::getTurret(int const y, int const x)
{
  return uptr(new Turret(TURRET, y, x, 32));
}

uptr Uf::getEnemy(int const y, int const x)
{
  return uptr(new Enemy(ENEMY, y, x, 32));
}
