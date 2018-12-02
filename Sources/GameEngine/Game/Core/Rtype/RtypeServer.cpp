//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// RtypeServer class implementation
//

#include "GameEngine/Game/Core/Rtype/RtypeServer.hpp"

Engine::Game::RtypeServer::RtypeServer(unsigned int tickRate, Vector2
mapSize, UdpManager *manager, std::vector<UdpConnection *> clients) :
AGameServer(manager, clients, tickRate), _mapSize
(mapSize), _id(0)
{
	initPlayers();
	initFuncPtr();
}

void Engine::Game::RtypeServer::launch()
{
	send(Packet::buildPacket(RTypeCommunication::BACKGROUND, _mapSize));
	send(Packet::buildPacket(RTypeCommunication::PLAYERS, _players));
	while (_isRunning) {
		auto beforeTime = std::chrono::high_resolution_clock::now();
		interpretCommand();
		send(Packet::buildPacket(RTypeCommunication::PLAYERS,
		_players));
		auto duration = std::chrono::high_resolution_clock::now() -
				beforeTime;
		if (duration < _tickValue) {
			std::this_thread::sleep_for(_tickValue - duration);
		}
	}
}

void Engine::Game::RtypeServer::interpretCommand()
{
	PlayerPacket packet;

	listen(packet);
	while (packet.packet.type != 99) {
		if (packet.packet.type > 0 && packet.packet.type <
		RTypeCommunication::COUNT)
			_funcPtr[packet.packet.type](packet);
		listen(packet);
	}
}


void Engine::Game::RtypeServer::initPlayers()
{
	for (int i = 0; i < 4; i++) {
		_players[i].health = 100;
		_players[i].speed = 1;
		_players[i].rotation = {0, 0, 0};
		_players[i].size = {32, 17, 1};
		_players[i].position = {_mapSize.x / 10, i * (_mapSize.y / 4),
		0};
		_players[i].team = (PlayerTeam) _id;
		_players[i].id = _id;
		_id += 1;
	}
}

void Engine::Game::RtypeServer::initFuncPtr()
{
	_funcPtr.at(RTypeCommunication::MOVERIGHT) = std::bind
	(&RtypeServer::moveRight, this, std::placeholders::_1);
	_funcPtr.at(RTypeCommunication::MOVELEFT) = std::bind
	(&RtypeServer::moveLeft, this, std::placeholders::_1);
	_funcPtr.at(RTypeCommunication::MOVETOP) = std::bind
	(&RtypeServer::moveTop, this, std::placeholders::_1);
	_funcPtr.at(RTypeCommunication::MOVEDOWN) = std::bind
	(&RtypeServer::moveDown, this, std::placeholders::_1);
	_funcPtr.at(RTypeCommunication::MOVESTOP) = std::bind
	(&RtypeServer::moveStop, this, std::placeholders::_1);
	_funcPtr.at(RTypeCommunication::SHOOT) = std::bind
	(&RtypeServer::shoot, this, std::placeholders::_1);
}

void Engine::Game::RtypeServer::moveRight(Engine::Game::PlayerPacket packet)
{
	if (_players[packet.team].position.x < _mapSize.x)
		_players[packet.team].position.x += 1;
}

void Engine::Game::RtypeServer::moveLeft(Engine::Game::PlayerPacket packet)
{
	if (_players[packet.team].position.x > 0)
		_players[packet.team].position.x -= 1;
}

void Engine::Game::RtypeServer::moveTop(Engine::Game::PlayerPacket packet)
{
	if (_players[packet.team].position.y > 0)
		_players[packet.team].position.y -= 1;
}

void Engine::Game::RtypeServer::moveDown(Engine::Game::PlayerPacket packet)
{
	if (_players[packet.team].position.y < _mapSize.y)
		_players[packet.team].position.y += 1;
}

void Engine::Game::RtypeServer::moveStop(Engine::Game::PlayerPacket packet)
{
}

void Engine::Game::RtypeServer::shoot(Engine::Game::PlayerPacket packet)
{
}


