//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// SfmlMusic class declaration
//

#ifndef SFMLMUSIC_HPP
#define SFMLMUSIC_HPP

#include <SFML/Audio.hpp>
#include "GameEngine/Graphical/Model/AMusic.hpp"

namespace Engine {
	namespace Graphical {
		class SfmlMusic : public AMusic {
			public:
			explicit SfmlMusic(const std::string &filename);
			virtual ~SfmlMusic();
			void play() override;
			void stop() override;
			void pause() override;
			void move(const Vector3 &dest) override;

			void setVolume(unsigned int volume) override;
			void setLoopNumber(unsigned int loop_number) override;
			virtual void setPosition(const Vector3 pos) override;

			private:
			sf::SoundBuffer _buffer;
			sf::Sound _sound;
		};
	}
}

#endif //SFMLMUSIC_HPP
