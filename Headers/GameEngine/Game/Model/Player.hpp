//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// PlayerInfo structure
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

namespace Engine {
	namespace Game {
		enum PlayerTeam {
			BLUE = 0,
			RED = 1,
			YELLOW = 2,
			GREEN = 3
		};

		enum PlayerStatus {
			ALIVE,
			DEAD
		};

		struct Player : Entity {
			int score;
			PlayerTeam team;
			PlayerStatus status;

			Player() : Entity(), score(0), team
			(PlayerTeam::BLUE), status(PlayerStatus::ALIVE){}
		};
	}
}

#endif //PLAYER_HPP
