//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// AMusic class implementation
//

#include "GameEngine/Graphical/Model/AMusic.hpp"

Engine::Graphical::AMusic::AMusic(const std::string &filename) : GameObject(),
trackFilename(filename)
{
	this->volume = 50;
	this->duration = 0;
	this->loop_number = 0;
	this->status = MusicState::STOP;
}

const std::string &Engine::Graphical::AMusic::getTrackFilename() const
{
	return trackFilename;
}

unsigned int Engine::Graphical::AMusic::getVolume() const
{
	return volume;
}

void Engine::Graphical::AMusic::setVolume(unsigned int volume)
{
	this->volume = volume;
}

unsigned int Engine::Graphical::AMusic::getDuration() const
{
	return duration;
}

unsigned int Engine::Graphical::AMusic::getLoopNumber() const
{
	return loop_number;
}

void Engine::Graphical::AMusic::setLoopNumber(unsigned int loop_number)
{
	this->loop_number = loop_number;
}

Engine::Graphical::AMusic::MusicState
Engine::Graphical::AMusic::getStatus() const
{
	return status;
}
