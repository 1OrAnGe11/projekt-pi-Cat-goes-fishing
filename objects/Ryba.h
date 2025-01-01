#ifndef _RYBA_
#define _RYBA_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Ryba  //jeszcze nie dzia³a
{
private:
    int frameCount;
    int currentFrame;
    float frameDuration;
    float elapsedTime;

public:
    float x = 0;
    float y = 0;
    int kierunek = 1;
    int type;
    float szybk_ryb;
    Ryba(float initialX, float initialY, sf::Color color, float size, sf::Texture& texture);
    sf::Sprite rybaSprite;
    void setPos(float x, float y);
    sf::Vector2f getPos();
    void update();
};

#endif
