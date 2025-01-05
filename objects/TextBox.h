#ifndef _TEXTBOX_
#define _TEXTBOX_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


class TextBox
{
private:
    sf::RenderWindow* window;
    bool mouse_over();
    bool clicked(sf::Event event);
    bool pressed = false;
public:
    sf::RectangleShape shape;
    sf::Font font;
    sf::Text text;
    std::string napis;
    std::string input;
    float x = 0;
    float y = 0;
    float rozmiar_x = 0;
    float rozmiar_y = 0;
    bool pomoc = false;
    bool pomoc1 = true;
    float rozmiar_text_x;
    float rozmiar_text_y;
    TextBox(float rozmiar_x, float rozmiar_y, float initialX, float initialY, sf::Color color, sf::RenderWindow* window, sf::String napis, int character_size);
    void zmien_nazwe(std::string napis);
    void wpisywanie(sf::Event event);
    int key_bind(sf::Event event);
    void setPos(float x, float y);
    sf::Vector2f getPos();
    void render();
};

#endif