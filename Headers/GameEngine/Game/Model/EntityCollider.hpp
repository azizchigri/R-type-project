//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// EntityCollider template class
//

#ifndef ENTITYCOLLIDER_HPP
#define ENTITYCOLLIDER_HPP

#include "GameEngine/Common/Vector3.hpp"

namespace Engine {
	namespace Game {
		template <typename T>
		class EntityCollider {
			public:
			EntityCollider() = default;
			~EntityCollider() = default;

			bool move()
			{
				return true;
			}

			bool contains(Vector3 position)
			{
				return (position.x >= this->_position.x &&
				position.y
				>= this->_position.y && position.z >=
				this->_position.z
				&& position.x <= this->_position.x +
				this->_dimensions.x && position.y <=
				this->_position.y
				+ this->_dimensions.y && position.z <=
				this->_position.z + this->_dimensions.z);
			}

			void shoot()
			{

			}

			private:
			T _data;
		};
	}
}

#endif //ENTITYCOLLIDER_HPP
