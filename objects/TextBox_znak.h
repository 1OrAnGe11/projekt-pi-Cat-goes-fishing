#ifndef _TEXTBOX_ZNAK_
#define _TEXTBOX_ZNAK_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


class TextBox_znak
{
private:
    sf::RenderWindow* window;
    bool mouse_over();
    bool pressed = false;
public:
    sf::RectangleShape shape;
    sf::Font font;
    sf::Text text;
    std::string napis;
    std::string input;
    sf::Keyboard::Key bind;
    sf::Keyboard::Key default_bind;
    sf::Sprite textbox_znakSprite;

    float x = 0;
    float y = 0;
    float rozmiar_x = 0;
    float rozmiar_y = 0;
    bool pomoc = false;
    bool pomoc1 = true;
    float rozmiar_text_x;
    float rozmiar_text_y;
    TextBox_znak(float rozmiar_x, float rozmiar_y, float initialX, float initialY, sf::Color color, sf::RenderWindow* window, sf::Keyboard::Key bind, int character_size, sf::Texture& texture);
    void zmien_nazwe(std::string napis);
    void key_bind(sf::Event event);
    std::string klawisz_na_unicode(sf::Keyboard::Key k);
    void setPos(float x, float y);
    sf::Vector2f getPos();
    void render();
    bool clicked(sf::Event event);
};

#endif