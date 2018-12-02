//
// EPITECH PROJECT, 2018
// R-type
// File description:
// ThreadLauncher class implementation
//

#include "GameEngine/Common/ThreadLauncher.hpp"

Engine::ThreadLauncher::~ThreadLauncher()
{
	for (auto it = begin(_thread); it != end(_thread); ++it) {
		it->join();
	}
}

void Engine::ThreadLauncher::createThread(IThreadable *reference)
{
	_thread.push_back(std::thread(&ThreadLauncher::execute, this,
	reference));
}

void Engine::ThreadLauncher::execute(IThreadable *reference)
{
	reference->launch();
}
