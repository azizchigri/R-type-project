//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// Room class declaration
//

#ifndef CPP_RTYPE_2018_ROOM_HPP
#define CPP_RTYPE_2018_ROOM_HPP

#include "Player.hpp"
#include "UdpManager.hpp"
#include "GameEngine/Common/ThreadLauncher.hpp"
#include "GameEngine/Game/Core/Rtype/RtypeServer.hpp"

#define MAXPLAYERPERROOM (4)

class Room {
	public:
		Room(const std::string &name, unsigned int i);
		~Room() = default;
		void setName(const std::string &name);
		const std::string & getName() const;
		bool join(Player &player);
		void leave(Player &player);
		void startGame(Engine::ThreadLauncher &thread);
		bool playerIsInRoom(Player &player);
		roomData getRoomData();
		unsigned int getId();
		const std::vector<Player> getPlayers() const;
		bool operator==(const Room &other) const;

	private:
		unsigned int _id;
		std::string _name;
		std::vector<Player> _players;
		unsigned int _number_max_of_player;
		bool _isStarted;
};

#endif //CPP_RTYPE_2018_ROOM_HPP
