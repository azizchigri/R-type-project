//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// AMusic class declaration
//

#ifndef AMUSIC_HPP
#define AMUSIC_HPP

#include <iostream>
#include "GameObject.hpp"

namespace Engine {
	namespace Graphical {
		class AMusic : public Engine::GameObject {
			public:
			enum MusicState {
				PLAY,
				PAUSE,
				STOP
			};

			virtual ~AMusic() = default;
			virtual void play() = 0;
			virtual void stop() = 0;
			virtual void pause() = 0;
			virtual void move(const Vector3 &dest) = 0;
			virtual void setVolume(unsigned int volume);
			virtual void setLoopNumber(unsigned int loop_number);
			const std::string &getTrackFilename() const;
			unsigned int getVolume() const;
			unsigned int getDuration() const;
			unsigned int getLoopNumber() const;
			MusicState getStatus() const;

			protected:
			explicit AMusic(const std::string &filename);
			const std::string trackFilename;
			unsigned int volume;
			unsigned int duration;
			unsigned int loop_number;
			MusicState status;
		};
	}
}

#endif //AMUSIC_HPP
