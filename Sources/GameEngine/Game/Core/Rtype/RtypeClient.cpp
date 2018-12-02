//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// RtypeClient class implementation
//

#include "GameEngine/Game/Core/Rtype/RtypeClient.hpp"

Engine::Game::RtypeClient::RtypeClient(unsigned int framerate,
boost::asio::io_service &io_service, const std::string &ip, const int port):
AGameClient(framerate, io_service, ip, port)
{
	_events = std::unique_ptr<Graphical::AEventManager<sf
	::RenderWindow>>(new SfmlEventManager());
	initFuncPtr();
}

bool Engine::Game::RtypeClient::launch()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "R-type",
	sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(_framerate);
	_port_udp = -1;
	_rooms_menu_manager.buttons[0] = -1;
	try {
		initPlayers();
		launchMenu(window);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	launchGame(window);
	return true;
}

void Engine::Game::RtypeClient::handleInput(std::vector<Engine::EventObject>
events)
{
	for (auto event : events) {
		if (event.type == EventObject::EventType::KEYPRESSED) {
			if (event.key.code == Event::Keyboard::Left)
				sendUdp(Packet::buildPacket(
				RTypeCommunication::MOVELEFT, ""));
			if (event.key.code == Event::Keyboard::Right)
				sendUdp(Packet::buildPacket(
				RTypeCommunication::MOVERIGHT, ""));
			if (event.key.code == Event::Keyboard::Up)
				sendUdp(Packet::buildPacket(
				RTypeCommunication::MOVETOP, ""));
			if (event.key.code == Event::Keyboard::Down)
				sendUdp(Packet::buildPacket(
				RTypeCommunication::MOVEDOWN, ""));
			if (event.key.code == Event::Keyboard::Space)
				sendUdp(Packet::buildPacket(
				RTypeCommunication::SHOOT, ""));
		}
	}
}

void Engine::Game::RtypeClient::launchGame(sf::RenderWindow &window)
{
	while (window.isOpen()) {
		auto events = _events->getEvents(window);
		handleInput(events);
		gameInterpretor();
		window.clear(sf::Color::Black);
		drawObjects(window);
		window.display();
	}
}

void Engine::Game::RtypeClient::createRooms(Engine::Graphical::SfmlMenu &menu)
{
	float a = 150;
	for (unsigned int i = 0; i < 10; i += 1) {
		char RoomInfo[150];
		sprintf(RoomInfo, "%s %d/%d",
		_rooms_menu_manager.rooms[i].name,
		_rooms_menu_manager.rooms[i].number_of_player,
		_rooms_menu_manager.rooms[i].number_max_of_player);
		_rooms_menu_manager.buttons[i] = menu.addButton
		(std::string(RoomInfo), {0, a, 0}, {20, 4, 40}, {51, 255, 79});
		a += 35;
	}
}

void Engine::Game::RtypeClient::updateRooms(Engine::Graphical::SfmlMenu &menu)
{
	for (unsigned int i = 0; i < 10; i += 1) {
		char RoomInfo[150];
		sprintf(RoomInfo, "%s %d/%d",
		_rooms_menu_manager.rooms[i].name,
		_rooms_menu_manager.rooms[i].number_of_player,
		_rooms_menu_manager.rooms[i].number_max_of_player);
		menu.updateButton( _rooms_menu_manager.buttons[i],
		std::string(RoomInfo), {20, 4, 40});
	}
}

void Engine::Game::RtypeClient::displayRooms(Packet::RtypePacket &packet,
Engine::Graphical::SfmlMenu &menu)
{
	if (packet.type == 201) {
		memcpy(&_rooms_menu_manager.rooms, &packet.body, sizeof
		(room_list));
		if (_rooms_menu_manager.buttons[0] != -1) {
			updateRooms(menu);
		} else {
			createRooms(menu);
		}
	}
}

bool Engine::Game::RtypeClient::menuPacketInterpretor(Packet::RtypePacket
&packet)
{
	if (packet.type == 20 && _port_udp == -1) {
		Port *my_port = reinterpret_cast<Port *> (packet
		.body);
		_port_udp = my_port->port;
		initClients(_ip, _port_udp);
	}
	if (packet.type == 201) {
		displayRooms(packet, _menu);
	}
	return (packet.type == 30);
}

bool Engine::Game::RtypeClient::menuButtonInterpretor(long button)
{
	if (_rooms_menu_manager.buttons[0] == -1)
		return false;
	for(unsigned int i = 0; i < 10; i += 1) {
		if (button == _rooms_menu_manager.buttons[i]) {
			std::cout << "room asking: " << _rooms_menu_manager
			.rooms[i].name << std::endl;
			sendTcp(Packet::buildPacket(Packet::Command::JOIN_ROOM,
			_rooms_menu_manager.rooms[i]));
			return false;
		}
	}
	if (button == _start_button) {
		sendTcp(Packet::buildPacket(8, "start game"));
		return true;
	}
	if (button == _refresh_button) {
		sendTcp(Packet::buildPacket(17, "getListRooms"));
	}
	return false;
}

void  Engine::Game::RtypeClient::initMenu()
{
	_menu.setMusic("menu.wav", 10);
	_menu.addText("Bienvenue dans le jeu", {0, 0, 0}, {20, 40, 40}, {51,
	255, 79});
	_start_button = _menu.addButton("Appuie pour start game", {250, 60,
	0}, {20, 40, 40}, {51, 255, 79});
	_refresh_button = _menu.addButton("Appuie pour refresh", {500,
	60, 0}, {20, 40, 40}, {51, 255, 79});
	sendTcp(Packet::buildPacket(17, "getListRooms"));
	sendTcp(Packet::buildPacket(9, "getUdpPort"));
}

void Engine::Game::RtypeClient::launchMenu(sf::RenderWindow &window)
{
	Packet::RtypePacket tcp_pack;
	Packet::RtypePacket udp_pack;
	long btn;
	initMenu();
	while (window.isOpen()) {
		tcp_pack = receiverTcp();
		if (_port_udp != -1)
			receiveUdp(udp_pack);
		btn = _menu.getButtonClicked(window);
		if (menuButtonInterpretor(btn) ||
		menuPacketInterpretor(tcp_pack))
			break;
		window.clear(sf::Color::Black);
		_menu.draw(window);
		window.display();
	}
}

void Engine::Game::RtypeClient::gameInterpretor()
{
	Packet::RtypePacket packet;

	receiveUdp(packet);
	while (packet.type != 99) {
		if (packet.type == RTypeCommunication::PLAYERS)
			_funcPtr[0](packet);
		receiveUdp(packet);
	}
}

void Engine::Game::RtypeClient::initFuncPtr()
{
	_funcPtr.at(0) = std::bind
	(&RtypeClient::restorePlayer, this, std::placeholders::_1);
}

void Engine::Game::RtypeClient::restorePlayer(Packet::RtypePacket packet)
{
	Player p[4];
	memcpy(&p, packet.body, packet.size);
	for (auto player : p) {
		_players[player.team]->setPosition(player.position);
	}
}

void Engine::Game::RtypeClient::initPlayers()
{
	_players.at(PlayerTeam::BLUE) = std::unique_ptr<
	Graphical::ColliderObject<sf::RenderWindow>>(new
	Graphical::ColliderObject<sf::RenderWindow>(new Graphical::SfmlShape
	("player1.png", Graphical::ShapeType::RECTANGLE)));
	_players.at(PlayerTeam::RED) = std::unique_ptr<
	Graphical::ColliderObject<sf::RenderWindow>>(new
	Graphical::ColliderObject<sf::RenderWindow>(new Graphical::SfmlShape
	("player2.png", Graphical::ShapeType::RECTANGLE)));
	_players.at(PlayerTeam::YELLOW) = std::unique_ptr<
	Graphical::ColliderObject<sf::RenderWindow>>(new
	Graphical::ColliderObject<sf::RenderWindow>(new Graphical::SfmlShape
	("player3.png", Graphical::ShapeType::RECTANGLE)));
	_players.at(PlayerTeam::GREEN) = std::unique_ptr<
	Graphical::ColliderObject<sf::RenderWindow>>(new
	Graphical::ColliderObject<sf::RenderWindow>(new Graphical::SfmlShape
	("player4.png", Graphical::ShapeType::RECTANGLE)));
}

void Engine::Game::RtypeClient::drawObjects(sf::RenderWindow &window)
{
	for (auto it = begin(_players); it != end(_players); ++it) {
		it->get()->draw(window);
	}
}
