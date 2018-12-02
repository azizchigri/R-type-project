//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// UdpClient class implementation
//

#include "Network/Common/UdpClient.hpp"

void UdpClient::initClients(const std::string &ip, const int &port)
{
	initReceiverClient(ip, port);
	initSenderClient(ip, port + 1);
}

void UdpClient::initSenderClient(const std::string &ip, const int port)
{
	std::unique_ptr<UdpConnection> client (new UdpConnection(ip, port));
	_sender_client =  std::move(client);
}

void UdpClient::initReceiverClient(const std::string &ip, const int &port)
{
	std::unique_ptr<UdpConnection> client (new UdpConnection(ip, port));
	_receiver_client =  std::move(client);
}

void UdpClient::sendUdp(Packet::RtypePacket *packet)
{
	try {
		if (_sender_client)
			_sender_client->sendUdp(packet);
	} catch (...) {
	}
}

const Packet::RtypePacket& UdpClient::receiveUdp(Packet::RtypePacket &packet)
{
	try {
		if (_receiver_client)
			return _receiver_client->receiveUdp(packet);
	} catch (...) {
	}
	return packet;
}