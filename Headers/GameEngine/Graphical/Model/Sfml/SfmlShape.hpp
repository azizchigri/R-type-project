//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// SfmlShape class declaration
//

#ifndef SFMLSHAPE_HPP
#define SFMLSHAPE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameEngine/GameEngineError.hpp"
#include "GameEngine/Graphical/Model/AShape.hpp"
#include "GameEngine/Common/Vector3.hpp"
#include "GameEngine/Graphical/Model/Color.hpp"

namespace Engine {
	namespace Graphical {
		class SfmlShape : public AShape<sf::RenderWindow> {
			public:
			~SfmlShape() = default;
			SfmlShape(const std::string &filename, ShapeType type);
			void move(const Engine::Vector3 &dest) override;
			void draw(sf::RenderWindow &window) const override;

			virtual void setRotation(Vector3 rotation) override;

			virtual void setSize(Vector3 size) override;

			virtual void setColor(const Color &color) override;

			virtual void setPosition(const Vector3 pos) override;

			private:
			sf::Texture _texture;
			sf::Sprite _sprite;

		};
	}
}

#endif //SFMLSHAPE_HPP
