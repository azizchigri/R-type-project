//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// TcpClient class declaration
//

#ifndef CPP_RTYPE_2018_TCPCLIENT_HPP
#define CPP_RTYPE_2018_TCPCLIENT_HPP

#include <boost/asio.hpp>
#include <iostream>
#include <fstream>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <cassert>
#include <boost/bind.hpp>
#include <unistd.h>
#include "GameEngine/Graphical/Model/Sfml/SfmlMusic.hpp"
#include "GameEngine/Graphical/Model/GameObject.hpp"
#include "GameEngine/Graphical/Model/Sfml/SfmlOutputText.hpp"
#include "GameEngine/Graphical/Model/Sfml/SfmlShape.hpp"
#include "GameEngine/Graphical/Core/Sfml/SfmlEventManager.hpp"
#include "GameEngine/Graphical/Model/ColliderObject.hpp"
#include "GameEngine/Graphical/Core/Sfml/SfmlMenu.hpp"
#include "Network/Server/RoomManager.hpp"
#include "Network/Common/Packet.hpp"

class TcpClient {
	public:
		TcpClient(boost::asio::io_service&
		io_service, const std::string &ip, const int port);
		~TcpClient();

	protected:
		void sendTcp(Packet::RtypePacket *);
		const Packet::RtypePacket &receiverTcp();
		void interpretor(Engine::Graphical::SfmlMenu &menu);
		void clearPacket();
		void close();
		boost::asio::ip::tcp::socket _socket;
		Packet::RtypePacket _packet;
};

#endif //CPP_RTYPE_2018_TCPCLIENT_HPP
