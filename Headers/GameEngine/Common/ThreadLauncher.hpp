//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// ThreadLauncher class
//

#ifndef THREADLAUNCHER_HPP
#define THREADLAUNCHER_HPP

#include <vector>
#include "IThreadable.hpp"

namespace Engine {
	class ThreadLauncher {
		public:
		ThreadLauncher() = default;
		~ThreadLauncher();
		void createThread(IThreadable *reference);

		private:
		void execute(IThreadable *reference);
		std::vector<std::thread> _thread;
	};
}

#endif //THREADLAUNCHER_HPP