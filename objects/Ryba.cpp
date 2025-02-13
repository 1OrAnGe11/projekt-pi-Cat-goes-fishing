#include "Ryba.h"

Ryba::Ryba(float initialX, float initialY, sf::Color color, float size, sf::Texture& texture1, sf::Texture& texture2, sf::Texture& texture3)
{
    type = rand() % 3;

    
    rybaSprite.setScale(sf::Vector2f(0.3, 0.3));
    rybaSprite.setColor(color);

    switch (type)
    {
    case 0:             // wolne
        szybk_ryb = 1;
        cena = 20;
        poprawka_wspolrzednych = 10;
        rybaSprite.setTexture(texture3);
        break;
    case 1:             // srednie
        szybk_ryb = 1.5;
        cena = 15;
        poprawka_wspolrzednych = 5;
        rybaSprite.setTexture(texture2);
        break;
    case 2:             // szybkie
        szybk_ryb = 2;
        cena = 10;
        poprawka_wspolrzednych = 0;
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

void Ryba::obrot()          // obrot sprite'a ryby, obrot jest od lewego dolnego piksela wiec trzeba pomnozyc wartosc x, zeby obrot byl mniej wiecej o srodek sprite'a
{        
    if (czyNaHaczyku == false) {
        if (!kierunek)
        {
            rybaSprite.setScale(sf::Vector2f(-0.3, 0.3));

            switch (type)
            {
            case 0:
                setPos(x + rybaSprite.getTexture()->getSize().x * 0.3, y);
                break;
            case 1:
                setPos(x + rybaSprite.getTexture()->getSize().x * 0.3, y);
                break;
            case 2:
                setPos(x + rybaSprite.getTexture()->getSize().x * 0.3, y);
                break;
            }
        }
        else
        {
            rybaSprite.setScale(sf::Vector2f(0.3, 0.3));
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
    if (czyNaHaczyku == false) {
        currentFrame++;

        if (rand() % 751 == 750 && x < 1550)  // szansa na obrocenie sie kierunku plyniecia ryby
        {
            kierunek = !kierunek;
            obrot();
        }

        if (rand() % 751 == 750)              // szansa na plyniecie do gory / na dol
        {
            if (rand() % 2 == 0)
                gora_dol = 0;
            else
                gora_dol = 2;
            licznik_gora_dol = rand() % 100 + 100;  // ile klatek plynie do gory / na dol
        }

        float _x, _y;

        _y = y;

        /*if (_y > 840)
        {
            _y = y - 0.5 * szybk_ryb;
        }*/

        if (licznik_gora_dol > 0)               // ryby plyna gora dol, gora_dol = 0-plyna w gore; 1-plyna tylko poziomo; 2-plyna w dol
        {
            if (gora_dol == 0)
                _y = y + 0.5 * szybk_ryb;
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


        if (y < 600)        //jezeli linka peknie kiedy ryba bedzie poza woda
        {
            y = 601;
            setPos(x, y);
        }
    }
}

void Ryba::lapanie() {
    if (kierunek) 
    {
        rybaSprite.setRotation(90);
    }
    else 
    {
        rybaSprite.setRotation(270);
    }

}

void Ryba::kill() {

    czyNaHaczyku = false;
    type = rand() % 3;
    int x1 = rand() % 30 + 1650;
    int y1 = rand() % 230 + 610;
    int r = (rand() % 255 + 0);
    int g = (rand() % 255 + 0);
    int b = (rand() % 255 + 0);
    rybaSprite.setColor(sf::Color(r, g, b, 255));
    //ryba.x = x1;
    //ryba.y = y1;
    rybaSprite.setRotation(0);
    setPos(x1, y1);
}

void Ryba::zerwana() {
    czyNaHaczyku = false;
    kierunek = false; //plyna w prawo
    obrot();
    rybaSprite.setRotation(0);
    setPos(x+50, y);
}