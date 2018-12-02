//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// Enemy structure
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"

namespace Engine {
	namespace Game {
		struct Enemy : Entity {
			int reward;
			int idSprite;

			Enemy() : Entity(), reward(0), idSprite(0){}
		};
	}
}

#endif //ENEMY_HPP
