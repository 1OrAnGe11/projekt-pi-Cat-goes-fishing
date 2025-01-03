#ifndef _BUTTON_
#define _BUTTON_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#define RozmiarOknaX 1600
#define RozmiarOknaY 900

class Button
{
private:
    sf::RenderWindow* window;
public:
    float x = 0;
    float y = 0;
    float rozmiar_x = 0;
    float rozmiar_y = 0;
    bool pomoc = false;
    float rozmiar_text_x;
    float rozmiar_text_y;

    sf::RectangleShape shape;
    sf::String napis;
    sf::Text text;
    sf::Font font;

    Button(float rozmiar_x, float rozmiar_y, float initialX, float initialY, sf::Color color, sf::RenderWindow* window, sf::String napis,
        int character_size);
    void render();
    void setPos(float x, float y);
    bool mouse_over();
    bool left_click();
    bool clicked();
    sf::Vector2f getPos();
};

#endif
