//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// RtypeClient class declaration
//

#ifndef RTYPECLIENT_HPP
#define RTYPECLIENT_HPP

#include <SFML/Graphics.hpp>
#include "GameEngine/Game/Core/AGameClient.hpp"
#include "GameEngine/Graphical/Core/AEventManager.hpp"
#include "GameEngine/Graphical/Model/ColliderObject.hpp"
#include "GameEngine/Graphical/Model/Sfml/SfmlShape.hpp"

namespace Engine {
	namespace Game {
		class RtypeClient : public AGameClient {
			public:
			virtual ~RtypeClient() = default;

			bool launch() override;

			void handleInput(std::vector<Engine::EventObject>
			events) override;
			
			RtypeClient(unsigned int framerate,
			boost::asio::io_service &io_service, const
			std::string &ip, const int port);

			private:
			void launchMenu(sf::RenderWindow &window);
			void launchGame(sf::RenderWindow &window);
			bool menuPacketInterpretor(Packet::RtypePacket
			&packet);
			bool menuButtonInterpretor(long button);
			void displayRooms(Packet::RtypePacket &packet,
			Engine::Graphical::SfmlMenu &menu);
			void updateRooms(Engine::Graphical::SfmlMenu &menu);
			void createRooms(Engine::Graphical::SfmlMenu &menu);
			void initMenu();

			std::unique_ptr<Graphical::AEventManager<sf
			::RenderWindow>> _events;
			Engine::Graphical::SfmlMenu _menu;
			int _port_udp;
			roomMenuManager _rooms_menu_manager;
			std::array<std::function<void(Packet::RtypePacket)>,
			1> _funcPtr;
			std::array<std::unique_ptr<Graphical::ColliderObject<sf
			::RenderWindow>>, 4> _players;
			long _start_button;
			long _refresh_button;
			void initFuncPtr();
			void initPlayers();
			void gameInterpretor();
			void drawObjects(sf::RenderWindow &window);
			void restorePlayer(Packet::RtypePacket packet);
		};
	}
}

#endif //RTYPECLIENT_HPP
