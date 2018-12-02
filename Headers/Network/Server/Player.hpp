//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// Player class declaration
//

#ifndef CPP_RTYPE_2018_PLAYER_HPP
#define CPP_RTYPE_2018_PLAYER_HPP

#include "Network/Common/Packet.hpp"

class TcpConnection;

class Player {
	public:
		Player(unsigned int id);
		~Player() = default;
		void setIp(const std::string &ip);
		std::string getIp() const;
		const bool isInRoom() const;
		void setIsInRoom(bool val);
		const unsigned int getId() const;
		void setTcpConnection(TcpConnection *connection);
		TcpConnection *getTcpConnection();
		bool operator==(const Player &other) const;

	private:
		unsigned int _id;
		std::vector<std::string> _buffer;
		bool _is_in_room;
		std::string _ip;
		TcpConnection *_tcp_connection;
};

#endif //CPP_RTYPE_2018_PLAYER_HPP
