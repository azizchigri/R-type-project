//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// Room class implementation
//

#include "Network/Server/Room.hpp"

Room::Room(const std::string &name, unsigned int id)
{
	_id = id;
	_name = std::string(name);
	_number_max_of_player = MAXPLAYERPERROOM;
	_isStarted = false;
}

const std::string &Room::getName() const
{
	return _name;
}

void Room::setName(const std::string &name)
{
	if (name.length() < 10 )
		Room::_name = name;
}

bool Room::join(Player &player)
{
	if (_players.size() >= 4)
		return false;
	if  (!player.isInRoom()) {
		std::cout << "player :" << player.getId() << " joined a game"
		<< std::endl;
		player.setIsInRoom(true);
		_players.push_back(player);
		return true;
	}
	return false;
}

void Room::leave(Player &player)
{
	auto p = std::find(_players.begin(), _players.end(), player);
	if (p != _players.end())
		_players.erase(p);
	player.setIsInRoom(false);
}

void Room::startGame(Engine::ThreadLauncher &thread)
{
	if(_isStarted)
		return;
	_isStarted = true;
	UdpManager *manage = new UdpManager;
	boost::asio::io_service io_service;
	std::vector<UdpConnection*> udp_clients;
	for (unsigned int i = 0; i < _players.size(); i += 1) {
		UdpConnection *client = new UdpConnection(io_service,
		_players[i].getIp(), UDP_PORT +  _players[i].getId());
		UdpConnection *Sender = new UdpConnection(_players[i].getIp(),
		UDP_PORT +  _players[i].getId() + 1);
		udp_clients.push_back(Sender);
		manage->addClient(client);
	}
	thread.createThread(new Engine::Game::RtypeServer(30, {800, 600},
	manage, udp_clients));
}

bool Room::playerIsInRoom(Player &player)
{
	auto p = std::find(_players.begin(), _players.end(), player);
	return p != _players.end();
}

bool Room::operator==(const Room &other) const
{
	return _id == other._id;
}

unsigned int Room::getId()
{
	return _id;
}

roomData Room::getRoomData()
{
	roomData data;
	memset(&(data.name), 0, sizeof(_name.length() + 1));
	std::memcpy(&(data.name), _name.c_str(), sizeof(_name.length() + 1));
	data.id = _id;
	data.number_max_of_player = _number_max_of_player;
	data.number_of_player = (int) _players.size();
	return data;
}

const std::vector<Player> Room::getPlayers() const
{
	return  _players;
}