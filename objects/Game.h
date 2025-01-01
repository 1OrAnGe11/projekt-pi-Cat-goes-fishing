#ifndef _GAME_
#define _GAME_

#include <SFML/Graphics.hpp>
#include "Ryba.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>

#define ConstHaczykInitX 80 //pozycja pocz¹tkowa haczyka (gdzie trzyma)
#define ConstHaczykInitY 30
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
    sf::RectangleShape linka; //linka ³¹cz¹ca haczyk i koniec wêdki
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
    //wêdka
    sf::Sprite wedkaSprite;
    sf::Texture wedkaTexture;
    //
    std::vector<Ryba> ryby;

    float angle;
    float promien;
    bool isKeyPressed;
    bool rzut = false;  //¿eby podczas zarzucania wêdki nie spada³ haczyk i nie da³o siê wci¹gaæ
    bool czyTrzyma = true;
    bool zarzucanie = false;    //animacja zamachu do ty³u wêdk¹
    float speedY = ConstSpeedY;
    float powierzchniaWody = 525.0; //pozycja powierzchni wody (Y)
    int klatka = 0;     //do sprawdzania która klatka jest aktualnie wyœwietlana(operacje takie jak co 120 klatek zrób cos)
    float predkoscLiniowa = 1.0; //predkosc haczyka

    void initWindow();
    void initPlayer();
    void initWêdka();
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