//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// AShape class declaration
//

#ifndef ASHAPE_HPP
#define ASHAPE_HPP

#include <iostream>
#include "GameEngine/Graphical/Model/ADrawable.hpp"

namespace Engine {
	namespace Graphical {
		enum ShapeType
		{
			UNKNOWN,
			SQUARE,
			CIRCLE,
			RECTANGLE
		};

		template <class T>
		class AShape : public ADrawable<T> {
			public:
			virtual ~AShape() = default;
			virtual void move(const Vector3 &dest) = 0;
			virtual void draw(T &window) const = 0;

			protected:
			AShape(const std::string &filename = "", const
			ShapeType type = ShapeType::UNKNOWN) : ADrawable<T>
			({0, 0, 0}, {30, 30, 30}, {50, 50, 50}),
			textureFilename(filename), type(type)
			{
			}

			const std::string textureFilename;
			const ShapeType type;
		};
	}
}

#endif //ASHAPE_HPP
