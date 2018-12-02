//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// AGameClient class implementation
//

#include "GameEngine/Game/Core/AGameClient.hpp"

Engine::Game::AGameClient::AGameClient(unsigned int framerate,
boost::asio::io_service&io_service, const std::string &ip, const int port) :
TcpClient(io_service, ip, port), UdpClient(), _framerate(framerate), _ip(ip)
{
}
