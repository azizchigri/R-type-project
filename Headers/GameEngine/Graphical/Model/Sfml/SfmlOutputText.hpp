//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// SfmlOutputText class declaration
//

#ifndef SFMLOUTPUTTEXT_HPP
#define SFMLOUTPUTTEXT_HPP

#include <SFML/Graphics.hpp>
#include "GameEngine/Graphical/Model/AOutputText.hpp"
#include "GameEngine/Graphical/Model/Color.hpp"

namespace Engine {
	namespace Graphical {
		class SfmlOutputText : public AOutputText<sf::RenderWindow> {
			public:
			SfmlOutputText(const std::string &text,
			const std::string &font, Vector3 size);
			virtual ~SfmlOutputText() = default;
			void move(const Vector3 &dest) override;
			void draw(sf::RenderWindow &window) const override;

			void setRotation(Vector3 rotation) override;

			void setSize(Vector3 size) override;

			void setColor(const Color &color) override;

			void setPosition(const Vector3 pos) override;

			private:
			sf::Text _text;
			sf::Font _font;
		};
	}
}

#endif //SFMLOUTPUTTEXT_HPP
