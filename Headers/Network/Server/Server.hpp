//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// Network class declaration
//

#ifndef CPP_RTYPE_2018_SERVER_HPP
#define CPP_RTYPE_2018_SERVER_HPP

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include "TcpConnection.hpp"
#include "RoomManager.hpp"

class Server {
	public:
		Server();
		~Server();
		void launch();
		void startAccept();
		void handleAccept(boost::shared_ptr<TcpConnection> connection,
		const boost::system::error_code& error);

	private:
		static int _client_id;
		RoomManager *_room_manager;
		boost::asio::ip::tcp::acceptor *_acceptor;
};

#endif //CPP_RTYPE_2018_SERVER_HPP
