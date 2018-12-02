//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// AUdpClient class declaration
//

#ifndef CPP_RTYPE_2018_AUDPCLIENT_HPP
#define CPP_RTYPE_2018_AUDPCLIENT_HPP

#include "UdpConnection.hpp"

class UdpClient {
	protected:
		UdpClient() = default;
		~UdpClient() = default;
		void initClients(const std::string &ip,const int &port);
		void sendUdp(Packet::RtypePacket *packet);
		const Packet::RtypePacket& receiveUdp(
		Packet::RtypePacket &packet);

	private:
		void initSenderClient(const std::string &ip, const int port);
		void initReceiverClient(const std::string &ip,
		const int &port);
		boost::asio::io_service _io_service;
		std::unique_ptr<UdpConnection> _sender_client;
		std::unique_ptr<UdpConnection> _receiver_client;
};

#endif //CPP_RTYPE_2018_AUDPCLIENT_HPP
