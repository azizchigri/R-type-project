//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// Thread handling interface
//

#ifndef ITHREADABLE_HPP
#define ITHREADABLE_HPP

#include <thread>

namespace Engine {
	class IThreadable {
		public:
		virtual void launch() = 0;
	};
}

#endif //ITHREADABLE_HPP
