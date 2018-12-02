//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// UdpManager class declaration
//

#ifndef CPP_RTYPE_2018_UDPMANAGER_HPP
#define CPP_RTYPE_2018_UDPMANAGER_HPP

#include "Network/Common/UdpConnection.hpp"
#include "Network/Server/Player.hpp"

class UdpManager {
	public:
		UdpManager() = default;
		~UdpManager() = default;
		void sendAll(Packet::RtypePacket *packet);
		void addClient(UdpConnection *client);
	private:
		std::vector<UdpConnection*> _clients;
};

#endif //CPP_RTYPE_2018_UDPMANAGER_HPP
