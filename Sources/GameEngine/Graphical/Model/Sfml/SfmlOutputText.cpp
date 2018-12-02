//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// SfmlOutputText class implementation
//

#include "GameEngine/Graphical/Model/Sfml/SfmlOutputText.hpp"

Engine::Graphical::SfmlOutputText::SfmlOutputText(const std::string &text,
const std::string &font, Vector3 size) : AOutputText(text, font, size)
{
	if (!_font.loadFromFile(font))
		throw Engine::GameEngineError(("Can not load font : " +
		font).c_str());
	_text.setFont(_font);
	_text.setCharacterSize(size.x);
	_text.setFillColor(sf::Color(this->color.r, this->color.g, this->color
	.b));
	_text.setString(text);
	_text.setRotation(this->rotation.x);
	_text.setPosition(this->position.x, this->position.y);
	this->size = { _text.getGlobalBounds().width, _text
	.getGlobalBounds().height, 0 };
}

void Engine::Graphical::SfmlOutputText::move(const Engine::Vector3 &dest)
{
	_text.move(dest.x, dest.y);
}

void Engine::Graphical::SfmlOutputText::draw(sf::RenderWindow &window) const
{
	window.draw(_text);
}

void Engine::Graphical::SfmlOutputText::setRotation(Vector3 rotation)
{
	ADrawable::setRotation(rotation);
	_text.rotate(rotation.x);
}

void Engine::Graphical::SfmlOutputText::setSize(Vector3 size)
{
	_text.setCharacterSize(size.x);
}

void Engine::Graphical::SfmlOutputText::setColor(const Color &color)
{
	ADrawable::setColor(color);
	_text.setFillColor(sf::Color(color.r, color.g, color.b));
}

void Engine::Graphical::SfmlOutputText::setPosition(const Engine::Vector3 pos)
{
	GameObject::setPosition(pos);
	_text.setPosition(pos.x, pos.y);
}
