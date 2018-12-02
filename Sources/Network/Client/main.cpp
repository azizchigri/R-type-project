//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// main function
//

#include "GameEngine/Game/Core/Rtype/RtypeClient.hpp"

int main(int ac, char **av)
{
	boost::asio::io_service ios;

	if (ac != 2)
	{
		std::cout << "Error: invalid parameters" << std::endl;
		return 84;
	}
	Engine::Game::RtypeClient client(2, ios,
	std::string(av[1]), 8080);
	if (!client.launch())
		return 84;
	return 0;
}