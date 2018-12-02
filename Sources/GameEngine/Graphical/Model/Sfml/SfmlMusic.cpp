//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// SfmlMusic class implementation
//

#include "GameEngine/Graphical/Model/Sfml/SfmlMusic.hpp"

Engine::Graphical::SfmlMusic::SfmlMusic(const std::string &filename) :
AMusic(filename)
{
	if (!_buffer.loadFromFile(filename))
		throw Engine::GameEngineError(("Can not load music : " +
		filename).c_str());
	_sound.setBuffer(_buffer);
	_sound.setVolume(this->volume);
	this->duration = static_cast<unsigned int>(_buffer.getDuration()
	.asSeconds() + 0.5);
	this->status = MusicState::STOP;
	_sound.setLoop(loop_number != 0);
}

void Engine::Graphical::SfmlMusic::play()
{
	_sound.play();
	this->status = AMusic::MusicState::PLAY;
}

void Engine::Graphical::SfmlMusic::stop()
{
	_sound.stop();
	this->status = AMusic::MusicState::STOP;
}

void Engine::Graphical::SfmlMusic::pause()
{
	_sound.pause();
	this->status = AMusic::MusicState::PAUSE;
}

void Engine::Graphical::SfmlMusic::move(const Engine::Vector3 &dest)
{
	_sound.setPosition(dest.x, dest.y, dest.z);
}

void Engine::Graphical::SfmlMusic::setVolume(unsigned int volume)
{
	AMusic::setVolume(volume);
	_sound.setVolume(volume);
}

void Engine::Graphical::SfmlMusic::setLoopNumber(unsigned int loop_number)
{
	AMusic::setLoopNumber(loop_number);
	_sound.setLoop(loop_number != 0);
}

void Engine::Graphical::SfmlMusic::setPosition(const Engine::Vector3 pos)
{
	GameObject::setPosition(pos);
	_sound.setPosition(pos.x, pos.y, pos.z);
}

Engine::Graphical::SfmlMusic::~SfmlMusic()
{
	if (status != MusicState::STOP)
		_sound.stop();
}
