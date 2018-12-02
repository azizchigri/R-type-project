//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// TcpConnection class declaration
//

#ifndef CPP_RTYPE_2018_TCPCONNECTION_HPP
#define CPP_RTYPE_2018_TCPCONNECTION_HPP

#include <boost/asio/buffer.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <fstream>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <cassert>
#include <boost/bind.hpp>
#include "Network/Server/RoomManager.hpp"

class TcpConnection : public boost::enable_shared_from_this<TcpConnection> {
	public:
		TcpConnection(boost::asio::io_service& io_service, Player
		&player);
		void start();
		static boost::shared_ptr<TcpConnection> create
		(boost::asio::io_service& io_service, Player &player);
		boost::asio::ip::tcp::socket& getSocket();
		bool send(Packet::RtypePacket*);
		void receive();
		void setRoomManager(RoomManager *);

	private:
		void interpretor();
		void clearPacket();
		void close();
		void readPacket();
		void handleReadPacket(const boost::system::error_code &error,
		const std::size_t bytes_transferred);

	private:
		boost::asio::ip::tcp::socket _socket;
		Player _player;
		RoomManager *_room_manager;
		Packet::RtypePacket _packet;
};

#endif //CPP_RTYPE_2018_TCPCONNECTION_HPP
