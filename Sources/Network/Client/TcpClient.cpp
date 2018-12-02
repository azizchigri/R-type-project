//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// TcpClient class implementation
//

#include "Network/Client/TcpClient.hpp"

TcpClient::TcpClient(boost::asio::io_service&
 io_service, const std::string &ip, const int port) : _socket
		      (io_service)
{
	boost::asio::ip::tcp::endpoint endpoint
	(boost::asio::ip::address::from_string(ip), port);
	boost::asio::ip::tcp::socket socket(io_service);
	socket.connect(endpoint);
	_socket.connect(endpoint);
	io_service.run();
}

TcpClient::~TcpClient()
{
	close();
}

void TcpClient::interpretor(Engine::Graphical::SfmlMenu &menu)
{

	room_list *room = reinterpret_cast<room_list*>(&_packet.body);
	float a = 150;
	for(unsigned int i = 0; i < 10; i += 1) {
		char roominfo[150];
		sprintf(roominfo, "%s %d/%d", room->rooms[i].name,
		room->rooms[i].number_of_player,
		room->rooms[i].number_max_of_player);
		long id = menu.addButton(roominfo, {0, a, 0}, {40, 40, 40},
		{51, 255, 79});
		a += 30;
	}
	std::cout << "room asking: " << room->rooms[0].name << std::endl;
}

void TcpClient::close()
{
	std::cout <<  "Socket clos." << std::endl;
	_socket.close();
}

void TcpClient::clearPacket()
{
	_packet.size = 0;
	_packet.type = 0;
	memset(&_packet.body, 0 , sizeof(_packet.size));
}

void TcpClient::sendTcp(Packet::RtypePacket *packet)
{
	boost::system::error_code ec;
	auto written = boost::asio::write(_socket, boost::asio::buffer
	(packet, sizeof(Packet::RtypePacket)));
	if (ec) {
		std::cout << "Error: " << ec.message() << std::endl;
		close();
		return;
	}
	delete packet;
}

const Packet::RtypePacket& TcpClient::receiverTcp()
{
	boost::system::error_code ec;
	_packet.type = (uint32_t) 99;
	if (_socket.available(ec) > 1) {
		std::size_t readed = _socket
		.read_some(boost::asio::buffer(&_packet,
		sizeof(Packet::RtypePacket)));
		if (ec) {
			std::cout << "Error: " << ec.message() << std::endl;
			close();
			return _packet;
		}
		if (readed > 0) {
			std::cout << "respond :" << _packet.type << std::endl;
		}
	}
	if (ec) {
		std::cout << "Error: " << ec.message() << std::endl;
		close();
	}
	return _packet;
}
