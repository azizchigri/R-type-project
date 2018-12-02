//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// GameObject class declaration
//

#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "GameEngine/GameEngineError.hpp"
#include "GameEngine/Common/Vector3.hpp"

namespace Engine {
	class GameObject {
		public:
		virtual ~GameObject() = default;

		virtual void move(const Vector3 &dest) = 0;

		const Vector3 &getPosition() const;

		virtual void setPosition(const Vector3 pos);
		bool isEnabled() const;
		void setEnabled(bool enabled);
		float getSpeed() const;
		void setSpeed(float speed);

		protected:
		GameObject();
		GameObject(const Vector3 pos, bool enabled, const float
		speed);
		Engine::Vector3 position;
		bool enabled;
		float speed;
	};
}

#endif //GAMEOBJECT_HPP
