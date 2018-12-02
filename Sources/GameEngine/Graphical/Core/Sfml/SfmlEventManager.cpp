//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// SfmlEventManager class implementation
//

#include "GameEngine/Graphical/Core/Sfml/SfmlEventManager.hpp"

std::vector<Engine::EventObject> Engine::SfmlEventManager::getEvents(
sf::RenderWindow &window)
{
	sf::Event event;
	Engine::EventObject ev;
	eventList.clear();
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		memcpy(&ev, &event, sizeof(event));
		eventList.push_back(ev);
	}
	return eventList;
}