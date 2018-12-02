//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// RoomManager class implementation
//

#include "Network/Server/RoomManager.hpp"
#include "Network/Server/TcpConnection.hpp"

RoomManager::RoomManager()
{
	int nb_room_max = 10;
	for (int i = 1; i <= nb_room_max; i += 1) {
		std::string room_name = "Room "  + std::to_string(i) ;
		addRoom(Room(room_name, i));
	}
}

void RoomManager::addRoom(Room room)
{
	_rooms.push_back(room);
}

Packet::RtypePacket *RoomManager::getAllRooms()
{
	room_list rooms = {0};
	std::string list_string;
	for (unsigned int i = 0; i < _rooms.size() && i < 10; i += 1) {
		rooms.rooms[i] = _rooms[i].getRoomData();
		list_string += _rooms[i].getName() + ";";
	}
	std::cout << list_string << std::endl;
	return Packet::buildPacket(201, rooms);
}

Packet::RtypePacket *RoomManager::addPlayerInRoom(Player &player, roomData *
room)
{
	std::cout << "room asked :" << room->name <<  std::endl;
	std::string answer = "Succes Room joined.";
	if (player.isInRoom())
		removePlayerInRoom(player, room);
	for (unsigned int i = 0; i < _rooms.size(); i += 1) {
		if (_rooms[i].getId() == room->id && !_rooms[i].join(player)) {
			return Packet::buildPacket(0, "Error, you can't join"
				 " this room.");
			}
	}
	return Packet::buildPacket(202, answer);
}

Packet::RtypePacket *RoomManager::removePlayerInRoom(Player &player,
roomData *)
{
	std::string answer = "Success rooms leaved.";
	if (!player.isInRoom()) {
		answer = "Error room not joined";
		return Packet::buildPacket(0, answer);
	}
	for (unsigned int i = 0; i < _rooms.size(); i += 1) {
		_rooms[i].leave(player);
	}
	return Packet::buildPacket(202, answer);
}

void RoomManager::startGame(Player &player)
{
	if (!player.isInRoom())
		return;
	for (unsigned int i = 0; i < _rooms.size(); i += 1) {
		if (_rooms[i].playerIsInRoom(player)) {
			std::vector<Player>  player = _rooms[i].getPlayers();
			if (player.size() < 4)
				return;
			for (unsigned int i = 0; i < player.size(); i += 1) {
				std::cout << "player id:" << player[i].getId
				() << std::endl;
				TcpConnection* connection = player[i].
				getTcpConnection();
				connection->send
				(Packet::buildPacket(30, "Game started"));
			}
			_rooms[i].startGame(_thread);
			return;
		}
	}
}
