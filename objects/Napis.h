#ifndef _NAPIS_
#define _NAPIS_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


class Napis
{
private:
	sf::RenderWindow* window;

public:
    int x;
    int y;
    int wartosc;
    bool pomoc_popup = false;
    sf::Text text;
    sf::Font font;
    sf::Color kolor_wypelnienia;
    sf::Color kolor_obramowki;


    Napis(sf::RenderWindow* window, float initialX, float initialY, std::string napis, int character_size, sf::Color kolor_wypelnienia, sf::Color kolor_obramowki, int wartosc);
    void setPos(float x, float y);
    void render(std::string napis, int wartosc);
};

#endif