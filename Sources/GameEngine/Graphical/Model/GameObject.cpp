//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// GameObject class implementation
//

#include "GameEngine/Graphical/Model/GameObject.hpp"

Engine::GameObject::GameObject()
{
	setPosition({0, 0, 0});
	setEnabled(true);
}

Engine::GameObject::GameObject(const Engine::Vector3 pos,
bool enabled, const float speed)
{
	setPosition(pos);
	setEnabled(enabled);
	setSpeed(speed);
}

const Engine::Vector3 &Engine::GameObject::getPosition() const
{
	return position;
}

void Engine::GameObject::setPosition(const Vector3 pos)
{
	this->position.x = pos.x;
	this->position.y = pos.y;
	this->position.z = pos.z;
}

bool Engine::GameObject::isEnabled() const
{
	return enabled;
}

void Engine::GameObject::setEnabled(bool enabled)
{
	this->enabled = enabled;
}

float Engine::GameObject::getSpeed() const
{
	return speed;
}

void Engine::GameObject::setSpeed(const float speed)
{
	this->speed = speed;
}
