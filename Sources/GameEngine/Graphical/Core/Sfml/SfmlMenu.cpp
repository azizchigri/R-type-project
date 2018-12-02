//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// SfmlMenu class implementation
//

#include "GameEngine/Graphical/Core/Sfml/SfmlMenu.hpp"

Engine::Graphical::SfmlMenu::SfmlMenu()
{
	this->_background = nullptr;
	this->_id = 0;
	_music = nullptr;
}

void Engine::Graphical::SfmlMenu::setBackground(const std::string &filename)
{
	SfmlShape *tmp = new SfmlShape(filename,
	Graphical::ShapeType::UNKNOWN);
	_background = std::move(std::unique_ptr<SfmlShape>(tmp));
}

void
Engine::Graphical::SfmlMenu::addText(const std::string &title,
Engine::Vector3 position, Engine::Vector3 size, Color color)
{
	SfmlOutputText *text = new SfmlOutputText(title,
	"arial.ttf", size);
	text->setPosition(position);
	_text.push_back(std::unique_ptr<SfmlOutputText>(text));
}

long
Engine::Graphical::SfmlMenu::addButton(const std::string &title,
Engine::Vector3 position, Engine::Vector3 size, Color color)
{
	SfmlOutputText *text = new SfmlOutputText(title,
	"arial.ttf", size);
	text->setPosition(position);
	text->setColor(color);
	_buttons.push_back(std::unique_ptr<ColliderObject<sf
	::RenderWindow>>(new ColliderObject<sf::RenderWindow>(text)));
	_id += 1;
	return _id - 1;
}

long Engine::Graphical::SfmlMenu::getButtonClicked(sf::RenderWindow &window)
{
	std::vector<Engine::EventObject> list = _manager.getEvents(window);
	for (auto event : list) {
		if (event.type == Engine::EventObject::EventType
		::MOUSEBUTTONPRESSED && event.mouseButton.button ==
			    Engine::Event::Mouse::Button::Left)
			return identifyButtonClicked(event);
	}
	return -1;
}

void Engine::Graphical::SfmlMenu::draw(sf::RenderWindow &window)
{
	if (_background)
		_background->draw(window);
	for (auto it = begin(_text); it != end(_text); ++it) {
		it->get()->draw(window);
	}
	for (auto it = begin(_buttons); it != end(_buttons); ++it) {
		it->get()->draw(window);
	}
}

void Engine::Graphical::SfmlMenu::clear()
{
	_text.clear();
	_buttons.clear();
}

long
Engine::Graphical::SfmlMenu::identifyButtonClicked(Engine::EventObject event)
{
	for (auto it = begin(_buttons); it != end(_buttons); ++it) {
		if (it->get()->contains({(float) event.mouseButton.x, (float)
		event.mouseButton.y , 0}))
			return (it - _buttons.begin());
	}
	return -1;
}

void Engine::Graphical::SfmlMenu::setMusic(const std::string &filename,
unsigned int volume)
{
	SfmlMusic *music = new SfmlMusic(filename);

	_music = std::unique_ptr<SfmlMusic>(music);
	_music->setVolume(volume);
	_music->play();
}

void
Engine::Graphical::SfmlMenu::updateButton(long id, const std::string &title,
Engine::Vector3 size)
{
	if (_id >= 0 && id < _buttons.size()) {
		SfmlOutputText *text = new SfmlOutputText(title,
		"arial.ttf", size);
		text->setPosition(_buttons[id].get()->getPosition());
		text->setColor(_buttons[id].get()->getColor());
		_buttons[id] = std::unique_ptr<ColliderObject<sf
		::RenderWindow>>(new ColliderObject<sf::RenderWindow>(text));
	}
}
