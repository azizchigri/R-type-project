//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// RtypeServer class declaration
//

#ifndef RTYPESERVER_HPP
#define RTYPESERVER_HPP

#include <functional>
#include <array>
#include "GameEngine/Game/Core/AGameServer.hpp"
#include "GameEngine/Common/Vector2.hpp"
#include "GameEngine/Game/Model/Player.hpp"

namespace Engine {
	namespace Game {
		enum RTypeCommunication {
			MOVERIGHT = 0,
			MOVELEFT,
			MOVETOP,
			MOVEDOWN,
			MOVESTOP,
			SHOOT,
			BACKGROUND,
			PLAYERS,

			COUNT
		};

		class RtypeServer : public AGameServer {
			public:
			virtual ~RtypeServer() = default;

			void launch() override;

			RtypeServer(unsigned int tickRate, Vector2
			mapSize, UdpManager *manager,
			std::vector<UdpConnection*> clients);

			private:
			Vector2 _mapSize;
			long _id;
			Player _players[4];
			std::array<std::function<void(PlayerPacket)>,
			6> _funcPtr;
			void initPlayers();
			void initFuncPtr();
			void interpretCommand();
			void moveRight(PlayerPacket packet);
			void moveLeft(PlayerPacket packet);
			void moveTop(PlayerPacket packet);
			void moveDown(PlayerPacket packet);
			void moveStop(PlayerPacket packet);
			void shoot(PlayerPacket packet);
		};
	}
}

#endif //RTYPESERVER_HPP
