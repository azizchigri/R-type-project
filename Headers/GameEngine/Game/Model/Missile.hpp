//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// MissileInfo structure
//

#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "Entity.hpp"

namespace Engine {
	namespace Game {
		struct Missile : Entity {
			unsigned int damage;
			unsigned int owner;

			Missile() : Entity(), damage(0), owner(0){}
		};
	}
}

#endif //MISSILE_HPP
