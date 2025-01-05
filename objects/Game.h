﻿#ifndef _GAME_
#define _GAME_

#include <SFML/Graphics.hpp>
#include "Ryba.h"
#include "Button.h"
#include "TextBox.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>

#define ConstHaczykInitX 122 //pozycja pocz�tkowa haczyka (gdzie trzyma)
#define ConstHaczykInitY 1
#define ConstWedkaInitX 125.0f
#define ConstWedkaInitY 530.0f
#define M_PI 3.14159265358979323846
#define ConstSpeedY 4
#define ConstSpeedX 3
#define RozmiarOknaX 1600
#define RozmiarOknaY 900
#define ConstPlayerSpeed 5

class Game
{
private:
    sf::RenderWindow window;
    sf::Texture menu_backgroundTexture;
    sf::Sprite menu_backgroundSprite;
    sf::Texture tloTexture;
    sf::Sprite tloSprite;
    sf::Texture drewnoTexture;
    sf::Sprite drewnoSprite;
    sf::Texture options_backgroundTexture;
    sf::Sprite options_backgroundSprite;
    sf::Texture sterowanie_backgroundTexture;
    sf::Sprite sterowanie_backgroundSprite;
    sf::Texture sklepy_backgroundTexture;
    sf::Sprite sklepy_backgroundSprite;
    Button start_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window, "Graj", 50);
    Button options_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 350), sf::Color(100, 100, 100, 255), &window, "Opcje", 50);
    Button quit_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 150), sf::Color(100, 100, 100, 255), &window, "Wyjdz", 50);
    Button sterowanie_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window, "Sterowanie", 50);
    Button options_back_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 350), sf::Color(100, 100, 100, 255), &window, "Cofnij", 50);
    Button rzucanie_wedka_button = Button(300, 100, (RozmiarOknaX - 590) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window,
        "Rzucanie\n   wedka", 50);
    TextBox bind_rzucanie_wedka_button = TextBox(270, 100, (RozmiarOknaX + 200 ) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window,
        "E", 50);
    Button sterowanie_back_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 350), sf::Color(100, 100, 100, 255), &window, "Cofnij", 50);

    int screen = 0;
    int options_screen = 0;
    sf::Keyboard::Key bind_rzucanie = sf::Keyboard::E;
    char char_bind_rzucanie;
    sf::Keyboard::Key bind_ciagniecie = sf::Keyboard::Space;
    sf::RectangleShape player;
    sf::CircleShape haczyk;
    sf::Texture texture;
    sf::RectangleShape linka; //linka ��cz�ca haczyk i koniec w�dki
    sf::RectangleShape woda;
    //animacja fali
    sf::Sprite falaSprite;
    sf::Texture falaTexture;
    sf::Texture rybaTexture1;
    sf::Texture rybaTexture2;
    sf::Texture rybaTexture3;
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

    //przejscie ekranu
    sf::RectangleShape zanikanie;
    bool czyPrzejscie = false;
    sf::Clock clock;
    sf::Time elapsed = sf::Time::Zero;

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
    bool LokalizacjaRyby = true; //czy u ryb czy w sklepach
    int predkosc = 0;
    bool skierowanyWprawo = true;

    void initTlo();
    void initWindow();
    void initPlayer();
    void initDrewno();
    void initWedka();
    void initRyby();
    void initWoda();
    void initFala(float x, float y);
    void initHaczyk();
    void initBackground();
    void initZanikanie();
    void przejscie(sf::Time deltaTime);

public:
    Game();
    void run();
    void update(sf::Time deltaTime);
    void render();
};
#endif