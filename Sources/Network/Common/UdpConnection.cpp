//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// UdpConnection class implementation
//

#include "Network/Common/UdpConnection.hpp"

UdpConnection::UdpConnection(boost::asio::io_service &io_service,
const std::string &ip,const int &port) : _socket_udp(io_service),
_remote_endpoint(boost::asio::ip::address::from_string(ip), port)
{
	_ip = ip;
	memset(&_packet, 0, sizeof(Packet::RtypePacket));
	_port = port;
}

UdpConnection::UdpConnection(const std::string &ip, const int &port)
{
	_port = port;
	_ip = ip;
	_socket_udp.open(boost::asio::ip::udp::v4());
	_socket_udp.set_option(boost::asio::socket_base::reuse_address(true));
	_socket_udp.bind(boost::asio::ip::udp::endpoint
	(boost::asio::ip::address::from_string(ip), port));
	_io_service.run();
}

UdpConnection::~UdpConnection()
{
	_socket_udp.close();
}

void UdpConnection::sendUdp(Packet::RtypePacket *packet)
{
	boost::asio::io_service io_service;
	boost::asio::ip::udp::endpoint remote_endpoint =
	boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string
	(_ip), _port);
	boost::asio::ip::udp::socket socket(io_service, remote_endpoint
	.protocol());
	io_service.run();
	boost::system::error_code err;
	size_t written = socket.send_to(boost::asio::buffer(packet, sizeof
	(Packet::RtypePacket)), remote_endpoint, 0 , err);
	if (err) {
		std::cout << "Error: " << err.message() << std::endl;
		return;
	}
	socket.close();
}

const Packet::RtypePacket &UdpConnection::receiveUdp(Packet::RtypePacket
&packet)
{
	packet.type = (uint32_t) 99;
	if (_socket_udp.available() >= 1) {
		auto readed = _socket_udp.receive_from(
		boost::asio::buffer(&_packet, sizeof(Packet::RtypePacket)),
		_remote_endpoint);
		if (readed == 1032){
			memcpy(&packet, &_packet, sizeof(Packet::RtypePacket));
		}
	}
	return packet;
}