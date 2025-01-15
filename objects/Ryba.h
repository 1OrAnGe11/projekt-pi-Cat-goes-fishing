#ifndef _RYBA_
#define _RYBA_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Ryba 
{
private:
    int frameCount;
    int currentFrame;
    float frameDuration;
    float elapsedTime;

public:
    float x = 0;
    float y = 0;
    bool kierunek = true;
    int gora_dol = 1;
    int licznik_gora_dol;
    int type;
    float szybk_ryb;
    int cena;

    Ryba(float initialX, float initialY, sf::Color color, float size, sf::Texture& texture1, sf::Texture& texture2, sf::Texture& texture3);
    sf::Sprite rybaSprite;
    void setPos(float x, float y);
    sf::Vector2f getPos();
    void update();
    void obrot();

    //do lowienia
    bool czyNaHaczyku = false;
    float poprawka_wspolrzednych;
    void lapanie();
    void kill();
    void zerwana();
};

#endif
