//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// Mouse structures
//

#ifndef MOUSE_HPP
#define MOUSE_HPP

namespace Engine {
	namespace Event {
		namespace Mouse {
			enum Button {
				Left,
				Right,
				Middle,
				XButton1,
				XButton2,
				ButtonCount
			};

			enum Wheel {
				VerticalWheel,
				HorizontalWheel
			};
		}
	}
}

#endif //MOUSE_HPP
