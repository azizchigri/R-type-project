//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// Network class implementation
//

#include "Network/Server/Server.hpp"

int Server::_client_id = 0;

Server::Server()
{
	boost::asio::io_service io_service;
	_acceptor = new boost::asio::ip::tcp::acceptor(io_service,
	boost::asio::ip::tcp::endpoint
	(boost::asio::ip::tcp::v4(), 8080));
	_room_manager = new RoomManager();
	startAccept();
	io_service.run();
}

Server::~Server()
{
	delete _room_manager;
}

void Server::launch()
{
	startAccept();
}

void Server::startAccept()
{
	Player my_player(Server::_client_id);
	boost::shared_ptr<TcpConnection> newConnection =
	TcpConnection::create(_acceptor->get_io_service(), my_player);

	_acceptor->async_accept(newConnection->getSocket(),
	boost::bind(&Server::handleAccept, this, newConnection,
	boost::asio::placeholders::error));
	Server::_client_id += 2;
}

void Server::handleAccept(boost::shared_ptr<TcpConnection> connection,
const boost::system::error_code &error)
{
	if (!error) {
		std::cout << "Reçu un client!" << std::endl;
		connection->setRoomManager(_room_manager);
		connection->start();
	}
	startAccept();
}