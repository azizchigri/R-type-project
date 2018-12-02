//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// UdpConnection class declaration
//

#ifndef CPP_RTYPE_2018_UDPCLIENT_HPP
#define CPP_RTYPE_2018_UDPCLIENT_HPP

#include <boost/asio/buffer.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <fstream>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <cassert>
#include <boost/bind.hpp>
#include <boost/array.hpp>
#include <memory>
#include "Packet.hpp"

#define UDP_PORT (6970)

class UdpConnection {
	public:
		UdpConnection(boost::asio::io_service &io_service,
		const std::string &ip, const int &port);
		UdpConnection(const std::string &ip,const int &port);
		UdpConnection() = default;
		~UdpConnection();
		void sendUdp(Packet::RtypePacket *packet);
		const Packet::RtypePacket & receiveUdp(
		Packet::RtypePacket &packet);

	private:
		boost::asio::io_service _io_service;
		boost::asio::ip::udp::socket _socket_udp{_io_service};
		boost::asio::ip::udp::endpoint _remote_endpoint;
		Packet::RtypePacket _packet;
		std::string _ip;
		int _port;
};

#endif //CPP_RTYPE_2018_UDPCLIENT_HPP
