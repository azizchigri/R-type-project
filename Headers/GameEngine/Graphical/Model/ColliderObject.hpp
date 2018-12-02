//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// ColliderObject class
//

#ifndef COLLIDEROBJECT_HPP
#define COLLIDEROBJECT_HPP

#include <memory>
#include <iostream>
#include "ADrawable.hpp"

namespace Engine {
	namespace Graphical {
		template <class T>
		class ColliderObject {
			public:
			ColliderObject(ADrawable<T> *object, Vector3
			position = {0, 0, 0}, Vector3 dimensions =
			{0, 0, 0}) : _object(
			std::unique_ptr<ADrawable<T>>(object)),
			_position(position), _dimensions(dimensions)
			{
				if (_object) {
					_position = _object->getPosition();
					_dimensions = _object->getSize();
				}
			}

			virtual ~ColliderObject() = default;

			const Vector3 &getPosition() const
			{
				return _position;
			}

			void setPosition(const Vector3 &position)
			{
				ColliderObject::_position = position;
				if (_object)
					_object->setPosition(position);
			}

			Engine::Graphical::Color getColor()
			{
				Color result = {0, 0, 0};
				if (_object)
					result = _object->getColor();
				return result;
			}

			const Vector3 &getDimensions() const
			{
				return _dimensions;
			}

			void setDimensions(const Vector3 &dimensions)
			{
				ColliderObject::_dimensions = dimensions;
				if (_object)
					_object->setSize(dimensions);
			}

			bool contains(const Vector3 position) const
			{
				return (position.x >= this->_position.x
				&& position.y >= this->_position.y &&
				position.z >= this->_position.z	&& position.x
				<= this->_position.x + this->_dimensions.x
				&& position.y <= this->_position.y +
				this->_dimensions.y && position.z <=
				this->_position.z + this->_dimensions.z);
			}

			void draw(T &window) const
			{
				if (_object)
					_object->draw(window);
			}

			private:
			std::unique_ptr<ADrawable<T>>  _object;
			Vector3 _position;
			Vector3 _dimensions;
		};
	}
}

#endif //COLLIDEROBJECT_HPP
