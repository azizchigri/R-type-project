//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// SfmlEventManager class declaration
//

#ifndef SFMLEVENTMANAGER_HPP
#define SFMLEVENTMANAGER_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <cstring>
#include "GameEngine/Graphical/Core/AEventManager.hpp"

namespace Engine {
	class SfmlEventManager : public
	Graphical::AEventManager<sf::RenderWindow> {
		public:
		virtual ~SfmlEventManager() = default;
		SfmlEventManager() = default;
		virtual std::vector<Engine::EventObject> getEvents(
		sf::RenderWindow &window) override;
	};
}

#endif //SFMLEVENTMANAGER_HPP
