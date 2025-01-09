#include "Ryba.h"

Ryba::Ryba(float initialX, float initialY, sf::Color color, float size, sf::Texture& texture1, sf::Texture& texture2, sf::Texture& texture3)
{
    type = rand() % 3;

    
    rybaSprite.setScale(sf::Vector2f(3, 3));
    rybaSprite.setColor(color);

    switch (type)
    {
    case 0:
        szybk_ryb = 1;
        rybaSprite.setTexture(texture3);
        break;
    case 1:
        szybk_ryb = 1.5;
        rybaSprite.setTexture(texture2);
        break;
    case 2:
        szybk_ryb = 2;
        rybaSprite.setTexture(texture1);
        break;
    }

    currentFrame = 0;
    elapsedTime = 0.0f;

    setPos(initialX, initialY);
}

void Ryba::setPos(float x, float y) 
{
    this->x = x;
    this->y = y;
    rybaSprite.setPosition(x, y);
}

sf::Vector2f Ryba::getPos()
{
    return sf::Vector2f(x, y);
}

void Ryba::obrot()          // obrot sprite'a ryby, obrot jest od lewego dolnego piksela wiec trzeba pomnozyc wartosc x o w tym wypadku 0.07, zeby obrot byl mniej wiecej o srodek sprite'a
{        
    if (czyNaHaczyku == false) {
        if (!kierunek)
        {
            rybaSprite.setScale(sf::Vector2f(-3, 3));

            switch (type)
            {
            case 0:
                setPos(x + rybaSprite.getTexture()->getSize().x * 2, y);
                break;
            case 1:
                setPos(x + rybaSprite.getTexture()->getSize().x * 2, y);
                break;
            case 2:
                setPos(x + rybaSprite.getTexture()->getSize().x * 2, y);
                break;
            }
        }
        else
        {
            rybaSprite.setScale(sf::Vector2f(3, 3));
            switch (type)
            {
            case 0:
                setPos(x + rybaSprite.getTexture()->getSize().x * -0.3, y);
                break;
            case 1:
                setPos(x + rybaSprite.getTexture()->getSize().x * -0.3, y);
                break;
            case 2:
                setPos(x + rybaSprite.getTexture()->getSize().x * -0.3, y);
                break;
            }
        }
    }
}


void Ryba::update() 
{
    if(czyNaHaczyku == false){
    currentFrame++;
    if (rand() % 1501 == 1500 && x < 1550)  // szansa na obrocenie sie kierunku plyniecia ryby
    {
        kierunek = !kierunek;
        obrot();
    }

    if (rand() % 1501 == 1500)              // szansa na plyniecie do gory / na dol
    {
        if (rand() % 2 == 0)
            gora_dol = 0;
        else
            gora_dol = 2;
        licznik_gora_dol = rand() % 100 + 100;  // ile klatek plynie do gory / na dol
    }

    float _x, _y;

    _y = y;

    if (licznik_gora_dol > 0)               // ryby plyna gora dol, gora_dol = 0-plyna w gore; 1-plyna tylko poziomo; 2-plyna w dol
    {
        if (gora_dol == 0)
            _y = y + 0.5*szybk_ryb;
        else if (gora_dol == 2)
            _y = y - 0.5 * szybk_ryb;
        licznik_gora_dol--;
        if (_y >= 850)                      // maksymalne wspolrzedne do kiedy plyna w gore / dol
        {
            _y = y;
            gora_dol = 2;
        }
        if (_y <= 600)
        {
            _y = y;
            gora_dol = 0;
        }
    }

    if (kierunek)                           // w ktora strone plyna ryby, w zaleznosci od wspolrzednych wielkosci wody (kiedy w lewo i kiedy w prawo)
    {
        _x = x - szybk_ryb;
    }
    else
    {
        _x = x + szybk_ryb;
    }
    setPos(_x, _y);

    if (x < 150)
    {
        kierunek = false;
        obrot();
    }
    else if (x > 1540 && !kierunek)
    {
        kierunek = true;
        obrot();
    }
    }
}

void Ryba::lapanie() {
    if (kierunek) { rybaSprite.setRotation(90); }
    else { rybaSprite.setRotation(270); }

}

void Ryba::kill(Ryba ryba) {
    
    int x1 = rand() % 30 + 1650; 
    int y1 = rand() % 230 + 610;

    int r = (rand() % 255 + 0);     
    int g = (rand() % 255 + 0);
    int b = (rand() % 255 + 0);
    rybaSprite.setColor(sf::Color(r, g, b, 255));
    //ryba.x = x1;
    //ryba.y = y1;
    ryba.setPos(x1, y1);
    rybaSprite.setRotation(0);
}