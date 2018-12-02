//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// Packet class declaration
//

#ifndef CPP_RTYPE_2018_PACKET_HPP
#define CPP_RTYPE_2018_PACKET_HPP

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <boost/asio.hpp>

namespace Packet {
	const int header_length = sizeof(uint32_t) * 2;
	const int max_body_length = 1024;

	enum Command {
		KO = 0,
		OK = 1,
		CONNECTION = 2,
		DISCONNECT = 3,
		JOIN_ROOM  = 5,
		LEAVE_ROOM = 6,
		IS_READy = 7,
		START_GAME = 8,
		ASK_UDP_PORT = 9,
		LIST_ROOMS = 17
	};

	struct RtypePacket {
		uint32_t  type;
		uint32_t size;
		uint8_t  body[max_body_length];
	};

	template <typename Type> RtypePacket *buildPacket(int type, Type &myStruct)
	{
		RtypePacket *packet = new RtypePacket();
		memset(packet, 0, sizeof(RtypePacket));
		packet->type = (uint32_t) type;
		packet->size = (uint32_t) sizeof(myStruct);

		memcpy(&(packet->body[0]), &myStruct, sizeof(myStruct));
		return packet;
	}
};

struct roomData {
	char name[11];
	unsigned int id;
	unsigned int number_max_of_player;
	unsigned int number_of_player;
};

struct room_list {
	roomData rooms[10];
};

struct roomMenuManager {
	roomData rooms[10];
	long buttons[10];
};

struct Port {
	int port;
};

#endif //CPP_RTYPE_2018_PACKET_HPP
