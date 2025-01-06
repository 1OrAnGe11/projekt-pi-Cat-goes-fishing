#include "TextBox.h"

TextBox::TextBox(float rozmiar_x, float rozmiar_y, float initialX, float initialY, sf::Color color, sf::RenderWindow* window, sf::String napis,
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
	text.setOrigin(text.getGlobalBounds().getSize() / 2.f + text.getLocalBounds().getPosition());
	text.setPosition(initialX + rozmiar_x / 2, initialY + rozmiar_y / 2);
	setPos(initialX, initialY);
	this->window = window;
	this->napis = napis;
	this->rozmiar_x = rozmiar_x;
	this->rozmiar_y = rozmiar_y;
}

void TextBox::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
	shape.setPosition(x, y);
}

sf::Vector2f TextBox::getPos()
{
	return sf::Vector2f(x, y);
}

bool TextBox::mouse_over()
{
	sf::Vector2i pos1 = sf::Vector2i(sf::Mouse::getPosition(*window));
	sf::Vector2f pos = window->mapPixelToCoords(pos1);
	return shape.getGlobalBounds().contains(pos.x, pos.y);
}

bool TextBox::clicked(sf::Event event)
{

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		if (!mouse_over()) {
			pomoc = false;
			pomoc1 = true;
			if (input == "")
				zmien_nazwe(napis);
			return false;
		}
		return true;
	}
	return false;
}

void TextBox::render()
{
	window->draw(shape);
}

void TextBox::zmien_nazwe(std::string napis)
{
	text.setString(napis);
	text.setOrigin(text.getGlobalBounds().getSize() / 2.f + text.getLocalBounds().getPosition());
	text.setPosition(x + (rozmiar_x / 2), y + (rozmiar_y / 2));
}

void TextBox::wpisywanie(sf::Event event)
{
	if (clicked(event))
		pomoc = true;
	if (pomoc && pomoc1)
	{
		pomoc1 = false;
		zmien_nazwe(input);
	}
	if (pomoc)
	{
		if (event.type == sf::Event::TextEntered)
		{

			if (event.text.unicode >= 32 && event.text.unicode <= 126)
			{
				input += (char)event.text.unicode;
				zmien_nazwe(input);
			}
			if (event.text.unicode == 8 && input.size() > 0)
			{
				input = input.substr(0, input.size() - 1);
				zmien_nazwe(input);
			}
		}
	}
}