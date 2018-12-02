//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// TcpConnection class implementation
//

#include "Network/Server/TcpConnection.hpp"

TcpConnection::TcpConnection(boost::asio::io_service& io_service,
Player &player):  _socket(io_service), _player(player)
{
	memset(&_packet, 0, sizeof(Packet::RtypePacket));
	_player.setTcpConnection(this);
}

boost::asio::ip::tcp::socket& TcpConnection::getSocket()
{
	return _socket;
}

void TcpConnection::start()
{
	std::cout << "Created TcpConnection session" << std::endl;
	_room_manager->getAllRooms();
	std::string myIp = _socket.remote_endpoint().address().to_string();
	_player.setIp(myIp);
	receive();
}

boost::shared_ptr<TcpConnection> TcpConnection::create
(boost::asio::io_service& ios, Player &player)
{
	return boost::shared_ptr<TcpConnection>
	(new TcpConnection(ios, player));

}

void TcpConnection::receive()
{
	readPacket();
}

void TcpConnection::interpretor()
{
	std::cout << "Command received with code :" << unsigned(_packet
	.type) << std::endl;
	if (_packet.type == Packet::Command::LIST_ROOMS) {
		send(_room_manager->getAllRooms());
	} else if (_packet.type == Packet::Command::JOIN_ROOM){
		roomData *room = reinterpret_cast<roomData *> (&_packet.body);
		send(_room_manager->addPlayerInRoom(_player, room));
		send(_room_manager->getAllRooms());
	} else if (_packet.type == Packet::Command::LIST_ROOMS){
		roomData *room = reinterpret_cast<roomData *> (&_packet.body);
		send(_room_manager->removePlayerInRoom(_player, room));
	} else if(_packet.type == Packet::Command::START_GAME) {
		_room_manager->startGame(_player);
	} else if (_packet.type == Packet::Command::ASK_UDP_PORT){
		Port my_port;
		my_port.port = UDP_PORT + _player.getId();
		send(Packet::buildPacket(20, my_port));
	} else {
		send(Packet::buildPacket(404, "Unknown command."));
	}
}

void TcpConnection::close()
{
	std::cout <<  "Socket clos." << std::endl;
	_socket.close();
}

void TcpConnection::readPacket(){

	_socket.async_read_some(
		boost::asio::buffer(&_packet, sizeof(Packet::RtypePacket)),
		boost::bind(
			&TcpConnection::handleReadPacket, shared_from_this(),
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

void TcpConnection::handleReadPacket(const boost::system::error_code &error,
const std::size_t bytes_transferred)
{
	if (bytes_transferred >= 1) {
		std::cout << "Bits readed :" << bytes_transferred << std::endl;
		interpretor();
		clearPacket();
	}
	receive();
}

void TcpConnection::clearPacket(){
	_packet.size = 0;
	_packet.type = 0;
	memset(&_packet.body, 0, sizeof(_packet.size));
}

bool TcpConnection::send(Packet::RtypePacket *packet){
	boost::system::error_code ec;
	auto written = boost::asio::write(_socket, boost::asio::buffer
	(packet, sizeof(Packet::RtypePacket)));
	if (ec) {
		std::cout << "Error: " << ec.message() << std::endl;
		close();
		return false;
	}
	delete packet;
}

void TcpConnection::setRoomManager(RoomManager *manager)
{
	_room_manager = manager;
}
