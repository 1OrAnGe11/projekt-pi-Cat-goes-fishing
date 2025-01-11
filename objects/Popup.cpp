#include "Popup.h"

Popup::Popup(sf::RenderWindow* window, float initialX, float initialY, std::string napis, int character_size, sf::Color kolor_wypelnienia, sf::Color kolor_obramowki)
{
	if (!font.loadFromFile("fonts/ARIAL.TTF"))
		std::cout << "Nie zaladowano fonta" << std::endl;
	text.setFont(font);
	text.setString(napis);
	text.setCharacterSize(character_size);
	text.setFillColor(kolor_wypelnienia);
	text.setOutlineThickness(2);
	text.setOutlineColor(kolor_obramowki);
	text.setStyle(sf::Text::Bold);
	text.setOrigin(text.getGlobalBounds().getSize() / 2.f + text.getLocalBounds().getPosition());
	setPos(initialX, initialY);
	this->window = window;
}

void Popup::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
	text.setPosition(x, y);
}

void Popup::render()
{
	window->draw(text);

	currentFrame++;
	int _y = y;

	_y -= 1;
	setPos(x, _y);

	if (currentFrame % 60 == 0)
	{
		setPos(-100, -100);
		pomoc_popup = false;
	}
}

void Popup::zmien_nazwe_miejsce(float initialX, float initialY, int wartosc)
{
	std::string napis = std::to_string(wartosc);
	napis += '$';
	text.setString(napis);
	setPos(initialX, initialY);
}