#ifndef _RYBA_
#define _RYBA_

#include <iostream>
#include <SFML/Graphics.hpp>

class Ryba  //jeszcze nie dzia³a
{
public:
    float x;
    float y;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::IntRect frameRect; int frameCount; int currentFrame; float frameDuration; float elapsedTime;
    Ryba(const std::string& textureFile, int frameWidth, int frameHeight, int frameCount, float frameDuration);
};

#endif