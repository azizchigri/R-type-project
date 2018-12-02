//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// SfmlInputText class declaration
//

#ifndef SFMLINPUTTEXT_HPP
#define SFMLINPUTTEXT_HPP

#include <SFML/Graphics.hpp>
#include "GameEngine/Graphical/Model/AInputText.hpp"
#include "GameEngine/Common/Vector3.hpp"

namespace Engine {
	namespace Graphical {
		class SfmlInputText : public AInputText<sf::RenderWindow> {
			public:
			SfmlInputText(const std::string &text,
			const std::string &police);
			virtual ~SfmlInputText() = default;
			void move(const Vector3 &dest) override;
			void draw(sf::RenderWindow &window) const override;

			private:
			sf::String _input;
			sf::Text _text;
		};
	}
}

#endif //SFMLINPUTTEXT_HPP
