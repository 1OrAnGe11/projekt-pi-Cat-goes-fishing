#ifndef _GAME_
#define _GAME_

#include <SFML/Graphics.hpp>
#include "Ryba.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>

#define ConstHaczykInitX 80 //pozycja pocz�tkowa haczyka (gdzie trzyma)
#define ConstHaczykInitY 30
#define ConstWedkaInitX 125.0f
#define ConstWedkaInitY 530.0f
#define M_PI 3.14159265358979323846
#define ConstSpeedY 4
#define ConstSpeedX 3

class Game
{
private:

    sf::RenderWindow window;
    sf::RectangleShape player;
    sf::CircleShape haczyk;
    sf::Texture texture;
    sf::RectangleShape linka; //linka ��cz�ca haczyk i koniec w�dki
    sf::RectangleShape woda;
    //animacja fali
    sf::Sprite falaSprite;
    sf::Texture falaTexture;
    sf::Texture rybaTexture;
    sf::IntRect falaFrameRect;
    int falaKlatkiSuma;
    int falaKlatki;
    float dlugoscKlatki;
    float czas;
    std::vector<sf::Sprite> falaSprites;
    //animacja rybaka
    sf::Sprite playerSprite;
    sf::Texture playerTexture;
    sf::IntRect playerFrameRect;
    int playerKlatkiSuma;
    int playerKlatki;
    float dlugoscKlatkiPlayer;
    //w�dka
    sf::Sprite wedkaSprite;
    sf::Texture wedkaTexture;
    bool animacjaWedka2 = false;
    float katWedki; //do animacji rzutu
    //ryby
    std::vector<Ryba> ryby;

    float angle;
    float promien;
    bool isKeyPressed;
    bool rzut = false;  //�eby podczas zarzucania w�dki nie spada� haczyk i nie da�o si� wci�ga�
    bool czyTrzyma = true;
    bool zarzucanie = false;    //animacja zamachu do ty�u w�dk�
    float speedY = ConstSpeedY;
    float powierzchniaWody = 525.0; //pozycja powierzchni wody (Y)
    int klatka = 0;     //do sprawdzania kt�ra klatka jest aktualnie wy�wietlana(operacje takie jak co 120 klatek zr�b cos)
    float predkoscLiniowa = 1.0; //predkosc haczyka

    void initWindow();
    void initPlayer();
    void initWedka();
    void initRyby();
    void initWoda();
    void initFala(float x, float y);
    void initHaczyk();

public:
    Game();
    void run();
    void update(sf::Time deltaTime);
    void render();
};
#endif