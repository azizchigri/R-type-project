//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// AGameServer class implementation
//

#include "GameEngine/Game/Core/AGameServer.hpp"

Engine::Game::AGameServer::AGameServer(UdpManager *manager,
std::vector<UdpConnection*> clients, unsigned int tickRate) : _isRunning(true)
{
	for (auto client : clients) {
		_udp_clients.push_back(std::unique_ptr<UdpConnection>(client));
	}
	_manager = std::unique_ptr<UdpManager>(manager);
	setTickRate(tickRate);
}

void Engine::Game::AGameServer::setTickRate(unsigned int tickRate)
{
	if (tickRate == 0)
		throw GameEngineError("tickRate can not be equals to 0");
	_tickValue = std::chrono::seconds(1 / tickRate);
}

Engine::Game::PlayerPacket
Engine::Game::AGameServer::listen(PlayerPacket &playerPacket)
{
	playerPacket.packet.type = (uint32_t) 99;
	for (auto it = begin(_udp_clients); it != end(_udp_clients); ++it) {
		playerPacket.packet = it->get()->receiveUdp(playerPacket
		.packet);
		if (playerPacket.packet.type != 99)
		{
			playerPacket.team =
			static_cast<Engine::Game::PlayerTeam>(
			it - _udp_clients.begin());
			break;
		}
	}
	return playerPacket;
}

void Engine::Game::AGameServer::send(Packet::RtypePacket *packet)
{

	if (_manager) {
		_manager->sendAll(packet);
	}
	if (packet)
		delete packet;
}