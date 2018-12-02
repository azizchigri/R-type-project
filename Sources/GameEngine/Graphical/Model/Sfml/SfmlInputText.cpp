//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// SfmlInputText class implementation
//

#include "GameEngine/Graphical/Model/Sfml/SfmlInputText.hpp"

Engine::Graphical::SfmlInputText::SfmlInputText(const std::string &text,
const std::string &police) : AInputText<sf::RenderWindow>(text,
police)
{
}

void Engine::Graphical::SfmlInputText::move(const Engine::Vector3 &dest)
{
}

void Engine::Graphical::SfmlInputText::draw(sf::RenderWindow &window) const
{
}
