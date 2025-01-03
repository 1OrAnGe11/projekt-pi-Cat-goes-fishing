#include "Button.h"

Button::Button(float rozmiar_x, float rozmiar_y, float initialX, float initialY, sf::Color color, sf::RenderWindow* window, sf::String napis,
	int character_size)
{
	shape.setSize(sf::Vector2f(rozmiar_x, rozmiar_y));
	shape.setFillColor(color);
	if (!font.loadFromFile("fonts/ARIAL.TTF"))
		std::cout << "Nie zaladowano fonta" << std::endl;
	text.setFont(font);
	text.setString(napis);
	text.setCharacterSize(character_size);
	text.setFillColor(sf::Color::Black);
	rozmiar_text_x = text.getLocalBounds().width;
	rozmiar_text_y = text.getLocalBounds().height;
	text.setOrigin(text.getGlobalBounds().getSize() / 2.f + text.getLocalBounds().getPosition());
	text.setPosition(initialX + rozmiar_x / 2, initialY + rozmiar_y / 2) ;
	setPos(initialX , initialY);
	this->window = window;
}

void Button::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
	shape.setPosition(x, y);
}

sf::Vector2f Button::getPos()
{
	return sf::Vector2f(x, y);
}

bool Button::mouse_over()
{
	sf::Vector2i pos1 = sf::Vector2i(sf::Mouse::getPosition(*window));
	sf::Vector2f pos = window->mapPixelToCoords(pos1);
	return shape.getGlobalBounds().contains(pos.x, pos.y);
}

bool Button::left_click()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool Button::clicked()
{
	return mouse_over() && left_click();
}

void Button::render()
{
	window->draw(shape);
}

