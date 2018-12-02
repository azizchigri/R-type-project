//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// SfmlShape class implementation
//

#include "GameEngine/Graphical/Model/Sfml/SfmlShape.hpp"

Engine::Graphical::SfmlShape::SfmlShape(const std::string &filename,
ShapeType type) : AShape(filename, type)
{
	if (!_texture.loadFromFile(filename))
	{
		if (!_texture.create(size.x, size.y))
		{
			throw Engine::GameEngineError(("Can not load texture :"
				  " " + filename).c_str());
		}
	}
	_texture.setSmooth(false);
	_sprite.setPosition(position.x, position.y);
	_sprite.setTexture(_texture);
	this->size = { _sprite.getGlobalBounds().width, _sprite
	.getGlobalBounds().height, 0 };
}

void Engine::Graphical::SfmlShape::move(const Engine::Vector3 &dest)
{
	_sprite.move(dest.x, dest.y);
}

void Engine::Graphical::SfmlShape::draw(sf::RenderWindow &window) const
{
	window.draw(_sprite);
}

void Engine::Graphical::SfmlShape::setRotation(Vector3 rotation)
{
	ADrawable::setRotation(rotation);
	_sprite.rotate(rotation.x);
}

void Engine::Graphical::SfmlShape::setSize(Vector3 size)
{
	ADrawable::setSize(size);
	_sprite.setScale(size.x, size.y);
}

void Engine::Graphical::SfmlShape::setColor(const Color &color)
{
	ADrawable::setColor(color);
	_sprite.setColor(sf::Color(color.r, color.g, color.b));
}

void Engine::Graphical::SfmlShape::setPosition(const Engine::Vector3 pos)
{
	GameObject::setPosition(pos);
	_sprite.setPosition(pos.x, pos.y);
}
