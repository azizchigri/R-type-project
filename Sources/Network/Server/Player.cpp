//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// Player class implementation
//

#include "Network/Server/Player.hpp"
#include "Network/Server/TcpConnection.hpp"

Player::Player(unsigned int id)
{
	_id = id;
	_is_in_room = false;
}

void Player::setIp(const std::string &ip)
{
	_ip = ip;
}

std::string Player::getIp() const
{
	return _ip;
}

const bool Player::isInRoom() const
{
	return  _is_in_room;
}

const unsigned int Player::getId() const
{
	return _id;
}

bool Player::operator==(const Player &other) const
{
	return  _id == other._id;
}

void Player::setIsInRoom(bool val)
{
	_is_in_room = val;
}

void Player::setTcpConnection(TcpConnection *connection)
{
	_tcp_connection = connection;
}

TcpConnection *Player::getTcpConnection()
{
	return _tcp_connection;
}