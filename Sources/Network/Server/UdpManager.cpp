//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// UdpManager class implementation
//

#include "Network/Server/UdpManager.hpp"

void UdpManager::addClient(UdpConnection *client)
{
	_clients.push_back(client);
}

void UdpManager::sendAll(Packet::RtypePacket *packet)
{
	if (!_clients[0]) {
		std::cout << "no client in manager" << std::endl;
		return;
	}
	for (unsigned int i = 0; i < _clients.size(); i += 1) {
		_clients[i]->sendUdp(packet);
	}
}