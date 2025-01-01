#include "Ryba.h"

Ryba::Ryba(float initialX, float initialY, sf::Color color, float size, sf::Texture& texture)
{
    type = rand() % 3;

    if (!texture.loadFromFile("obrazy/ryba.png", sf::IntRect(0, 0, 515, 256)))
    {
        std::cerr << "Blad wczytywania tekstury ryby!" << std::endl;
    }

    rybaSprite.setTexture(texture);
    rybaSprite.setScale(sf::Vector2f(0.1, 0.1));
    rybaSprite.setColor(color);

    switch (type)
    {
    case 0:
        szybk_ryb = 1;
        break;
    case 1:
        szybk_ryb = 1.5;
        break;
    case 2:
        szybk_ryb = 2;
        break;
    }
    printf("szyb ryb %lf", szybk_ryb);

    //rybaFrameRect = sf::IntRect(0, 0, 20 * size, 10 * size);
    //rybaSprite.setTextureRect(rybaFrameRect);

    currentFrame = 0;
    elapsedTime = 0.0f;

    setPos(initialX, initialY);
}

void Ryba::setPos(float x, float y) {
    this->x = x;
    this->y = y;
    rybaSprite.setPosition(x, y);
}

sf::Vector2f Ryba::getPos() {
    return sf::Vector2f(x, y);
}


void Ryba::update() {
    currentFrame++;
    if (kierunek)          // w ktora strone plyna ryby, w zaleznosci od wspolrzednych (kiedy w lewo i kiedy w prawo)
        setPos(x - szybk_ryb, y);
    else
        setPos(x + szybk_ryb, y);
    if (x < 150)
        kierunek = 0;
    else if (x > 1550 && !kierunek)
        kierunek = 1;
}