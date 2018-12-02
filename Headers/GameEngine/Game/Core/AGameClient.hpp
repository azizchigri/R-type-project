//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// AGameClient class declaration
//

#ifndef AGAMECLIENT_HPP
#define AGAMECLIENT_HPP

#include <string>
#include <boost/asio.hpp>
#include "Network/Client/TcpClient.hpp"
#include "Network/Common/UdpClient.hpp"

namespace Engine {
	namespace Game {
		class AGameClient : public TcpClient, public UdpClient{
			public:
			virtual ~AGameClient() = default;
			virtual bool launch() = 0;
			virtual void handleInput
			(std::vector<Engine::EventObject> events) = 0;

			protected:
			AGameClient(unsigned int framerate,
			boost::asio::io_service &io_service, const
			std::string &ip, const int port);
			unsigned int _framerate;
			std::string _ip;
		};
	}
}

#endif //AGAMECLIENT_HPP
