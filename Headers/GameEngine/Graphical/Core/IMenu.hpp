//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// IMenu class declaration
//

#ifndef AMENUCREATOR_HPP
#define AMENUCREATOR_HPP

#include <iostream>
#include "GameEngine/Common/Event.hpp"
#include "GameEngine/Common/Vector3.hpp"
#include "GameEngine/Graphical/Model/Color.hpp"

namespace Engine {
	namespace Graphical {
		template <class T>
		class IMenu {
			public:
			virtual ~IMenu() = default;

			virtual void setMusic(const std::string &filename,
			unsigned int volume) = 0;
			virtual void setBackground(
			const std::string &filename) = 0;
			virtual void addText(const std::string &title,
			Vector3 position, Vector3 size, Color color) = 0;
			virtual long addButton(const std::string &title,
			Vector3 position, Vector3 size, Color color) = 0;
			virtual void updateButton(long id, const std::string
			&title, Vector3 size) = 0;
			virtual long getButtonClicked(T &window) = 0;
			virtual void draw(T &window) = 0;
			virtual void clear() = 0;
		};
	}
}

#endif //AMENUCREATOR_HPP
