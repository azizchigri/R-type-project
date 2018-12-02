//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// Sensor structures
//

#ifndef SENSOR_HPP
#define SENSOR_HPP

namespace Engine {
	namespace Event {
		namespace Sensor {
			enum Type
			{
				Accelerometer,
				Gyroscope,
				Magnetometer,
				Gravity,
				UserAcceleration,
				Orientation,
				Count
			};
		}
	}
}

#endif //SENSOR_HPP
