//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// Event function header
//

#ifndef EVENT_HPP
#define EVENT_HPP

#include <cstdint>
#include "Key.hpp"
#include "Mouse.hpp"
#include "Joystick.hpp"
#include "Sensor.hpp"

namespace Engine {
	class EventObject {
		public:
		struct SizeEvent {
			unsigned int width;
			unsigned int height;
		};

		struct KeyEvent {
			Event::Keyboard::Key code;
			bool          alt;
			bool          control;
			bool          shift;
			bool          system;
		};

		struct TextEvent {
			uint32_t unicode;
		};

		struct MouseMoveEvent {
			int x;
			int y;
		};

		struct MouseButtonEvent {
			Event::Mouse::Button button;
			int           x;
			int           y;
		};

		struct MouseWheelEvent {
			int delta;
			int x;
			int y;
		};

		struct MouseWheelScrollEvent {
			Event::Mouse::Wheel wheel;
			float        delta;
			int          x;
			int          y;
		};

		struct JoystickConnectEvent {
			unsigned int joystickId;
		};

		struct JoystickMoveEvent {
			unsigned int   joystickId;
			Event::Joystick::Axis axis;
			float          position;
		};

		struct JoystickButtonEvent {
			unsigned int joystickId;
			unsigned int button;
		};

		struct TouchEvent {
			unsigned int finger;
			int x;
			int y;
		};

		struct SensorEvent {
			Event::Sensor::Type type;
			float x;
			float y;
			float z;
		};

		enum EventType {
			CLOSED,
			RESIZED,
			LOSTFOCUS,
			GAINEDFOCUS,
			TEXTENTERED,
			KEYPRESSED,
			KEYRELEASED,
			MOUSEWHEELMOVED,
			MOUSEWHEELSCROLLED,
			MOUSEBUTTONPRESSED,
			MOUSEBUTTONRELEASED,
			MOUSEMOVED,
			MOUSEENTERED,
			MOUSELEFT,
			JOYSTICKBUTTONPRESSED,
			JOYSTICKBUTTONRELEASED,
			JOYSTICKMOVED,
			JOYSTICKCONNECTED,
			JOYSTICKDISCONNECTED,
			TOUCHBEGAN,
			TOUCHMOVED,
			SENSORCHANGED,
			COUNT
		};

		Engine::EventObject::EventType type;

		union {
			SizeEvent             size;
			KeyEvent              key;
			TextEvent             text;
			MouseMoveEvent        mouseMove;
			MouseButtonEvent      mouseButton;
			MouseWheelEvent       mouseWheel;
			MouseWheelScrollEvent mouseWheelScroll;
			JoystickMoveEvent     joystickMove;
			JoystickButtonEvent   joystickButton;
			JoystickConnectEvent  joystickConnect;
			TouchEvent            touch;
			SensorEvent           sensor;
		};
	};
}

#endif //EVENT_HPP
