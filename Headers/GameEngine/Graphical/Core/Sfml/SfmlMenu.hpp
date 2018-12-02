//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// SfmlMenu class declaration
//

#ifndef SFMLMENU_HPP
#define SFMLMENU_HPP

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameEngine/Graphical/Model/Sfml/SfmlOutputText.hpp"
#include "GameEngine/Graphical/Model/Sfml/SfmlShape.hpp"
#include "GameEngine/Graphical/Core/IMenu.hpp"
#include "GameEngine/Graphical/Model/ColliderObject.hpp"
#include "SfmlEventManager.hpp"
#include "GameEngine/Graphical/Model/Sfml/SfmlMusic.hpp"

namespace Engine {
	namespace Graphical {
		class SfmlMenu : public IMenu<sf::RenderWindow> {
			public:
			virtual ~SfmlMenu() = default;
			SfmlMenu();
			void setBackground(
			const std::string &filename) override;

			void addText(const std::string &title, Vector3
			position, Vector3 size, Color color) override;

			long addButton(const std::string &title, Vector3
			position, Vector3 size, Color color) override;

			long getButtonClicked(sf::RenderWindow &window)
			override;

			void draw(sf::RenderWindow &window) override;

			void setMusic(const std::string &filename,
			unsigned int volume) override;

			void updateButton(long id, const std::string &title,
			Vector3 size) override;

			void clear() override;

			private:
			SfmlEventManager _manager;
			std::unique_ptr<SfmlShape> _background;
			std::vector<std::unique_ptr<ColliderObject<
			sf::RenderWindow>>> _buttons;
			std::vector<std::unique_ptr<SfmlOutputText>> _text;
			std::unique_ptr<SfmlMusic> _music;
			long _id;
			long identifyButtonClicked(EventObject event);
		};
	}
}

#endif //SFMLMENU_HPP
