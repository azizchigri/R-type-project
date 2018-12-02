//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// RoomManager class declaration
//

#ifndef CPP_RTYPE_2018_MANAGEROOMS_HPP
#define CPP_RTYPE_2018_MANAGEROOMS_HPP

#include "Room.hpp"
#include "GameEngine/Common/ThreadLauncher.hpp"
#include "GameEngine/Game/Core/Rtype/RtypeServer.hpp"

class RoomManager {
	public:
		RoomManager();
		~RoomManager() = default;
		void addRoom(Room room);
		Packet::RtypePacket *getAllRooms();
		Packet::RtypePacket *addPlayerInRoom(Player &player,
		roomData*);
		Packet::RtypePacket *removePlayerInRoom(Player &player,
		roomData *);
		void startGame(Player &player);

	private:
		std::vector<Room> _rooms;
		Engine::ThreadLauncher _thread;
};

#endif //CPP_RTYPE_2018_MANAGEROOMS_HPP
