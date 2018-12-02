//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// AGameServer class declaration
//

#ifndef AGAMESERVER_HPP
#define AGAMESERVER_HPP

#include <chrono>
#include <array>
#include <memory>
#include "GameEngine/Common/IThreadable.hpp"
#include "GameEngine/GameEngineError.hpp"
#include "Network/Common/Packet.hpp"
#include "GameEngine/Game/Model/Player.hpp"
#include "Network/Common/UdpConnection.hpp"
#include "Network/Server/UdpManager.hpp"

namespace Engine {
	namespace Game {
		struct PlayerPacket {
			Packet::RtypePacket packet;
			Engine::Game::PlayerTeam team;
		};

		class AGameServer : public IThreadable {
			public:
			AGameServer();
			virtual ~AGameServer() = default;

			virtual PlayerPacket listen(PlayerPacket
			&playerPacket) final;

			virtual void send(Packet::RtypePacket *packet) final;

			virtual void setTickRate(unsigned int tickRate);

			void launch() override = 0;

			protected:
			explicit AGameServer(UdpManager *manager,
			std::vector<UdpConnection*> clients,
			unsigned int tickRate);
			bool _isRunning;
			std::chrono::seconds _tickValue;
			private:
			std::vector<std::unique_ptr<UdpConnection>>
			_udp_clients;
			std::unique_ptr<UdpManager> _manager;
		};
	}
}

#endif //AGAMESERVER_HPP
