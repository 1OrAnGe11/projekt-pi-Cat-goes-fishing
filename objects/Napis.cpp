#include "Napis.h"

Napis::Napis(sf::RenderWindow* window, float initialX, float initialY, std::string napis, int character_size, sf::Color kolor_wypelnienia, sf::Color kolor_obramowki, int wartosc)
{
	if (!font.loadFromFile("fonts/ARIAL.TTF"))
		std::cout << "Nie zaladowano fonta" << std::endl;
	if (wartosc != -1)
	{
		napis = std::to_string(wartosc);
		napis += '$';
	}
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

void Napis::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
	text.setPosition(x, y);
}

void Napis::render(std::string napis, int wartosc)
{
	if (wartosc != -1)
	{
		napis = std::to_string(wartosc);
		napis += '$';
	}
	text.setString(napis);
	text.setOrigin(text.getGlobalBounds().getSize() / 2.f + text.getLocalBounds().getPosition());
	setPos(x, y);
}