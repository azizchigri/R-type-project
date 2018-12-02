//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// ADrawable class declaration
//

#ifndef ADRAWABLE_HPP
#define ADRAWABLE_HPP

#include "GameObject.hpp"
#include "Color.hpp"
#include "GameEngine/Common/Vector3.hpp"

namespace Engine {
	namespace Graphical {
		template<class T>
		class ADrawable : public GameObject {
			public:
			virtual ~ADrawable() = default;
			virtual void move(const Vector3 &dest) = 0;
			virtual void draw(T &window) const = 0;

			Vector3 getRotation() const
			{
				return rotation;
			}

			virtual void setRotation(Vector3 rotation)
			{
				this->rotation = rotation;
			}

			Vector3 getSize() const
			{
				return size;
			}

			virtual void setSize(Vector3 size)
			{
				this->size = size;
			}

			const Color &getColor() const
			{
				return color;
			}

			virtual void setColor(const Color &color)
			{
				this->color = color;
			}

			protected:
			ADrawable(Vector3 rotation, Vector3 size, Color
			color) : GameObject(), rotation(rotation), size
			(size), color(color)
			{
			}

			Vector3 rotation;
			Vector3 size;
			Color color;
		};
	}
}

#endif //ADRAWABLE_HPP
