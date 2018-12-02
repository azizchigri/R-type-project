//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// AEventManager class declaration
//

#ifndef AEVENTMANAGER_HPP
#define AEVENTMANAGER_HPP

#include <vector>
#include "GameEngine/Common/Event.hpp"

namespace Engine {
	namespace Graphical {
		template <class T>
		class AEventManager {
			public:
			virtual ~AEventManager() = default;
			virtual std::vector<Engine::EventObject>
			getEvents(T &window) = 0;

			protected:
			std::vector<Engine::EventObject> eventList;
		};
	}
}

#endif //AEVENTMANAGER_HPP
