//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// Entity structure
//

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "GameEngine/Common/Vector3.hpp"

namespace Engine {
	namespace Game {
		struct Entity {
			int health;
			long id;
			int speed;
			Engine::Vector3 position;
			Engine::Vector3 size;
			Engine::Vector3 rotation;

			Entity() : health(0), id(0), speed(0), position({0,
			0, 0}), size({0, 0, 0}), rotation({0, 0, 0}){}
		};
	}
}

#endif //ENTITY_HPP
