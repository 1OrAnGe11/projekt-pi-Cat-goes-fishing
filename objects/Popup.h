#ifndef _POPUP_
#define _POPUP_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


class Popup
{
private:
    int currentFrame;
    sf::RenderWindow* window;

public:
    int x;
    int y;
    bool pomoc_popup = false;
    sf::Text text;
    sf::Font font;

    Popup(sf::RenderWindow* window, float initialX, float initialY, std::string napis, int character_size, sf::Color kolor_wypelnienia, sf::Color kolor_obramowki);
    void zmien_nazwe_miejsce(float initialX, float initialY, int wartosc);
    void setPos(float x, float y);
    void render();
};

#endif