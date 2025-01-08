#ifndef _GAME_
#define _GAME_

#include <SFML/Graphics.hpp>
#include "Ryba.h"
#include "Button.h"
#include "TextBox.h"
#include "TextBox_znak.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>

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
    //do zmiany !!!!! (bo czytane z pliku)
    int maxRybyNaHaczyku = 1;

    //
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

    sf::Keyboard::Key bind_rzucanie = sf::Keyboard::E;
    sf::Keyboard::Key bind_wciaganie = sf::Keyboard::Space;
    sf::Keyboard::Key bind_przejscie = sf::Keyboard::Q;
    sf::Keyboard::Key bind_chodzenie_lewo = sf::Keyboard::A;
    sf::Keyboard::Key bind_chodzenie_prawo = sf::Keyboard::D;

    TextBox_znak bind_rzucanie_wedka_button = TextBox_znak(270, 100, (RozmiarOknaX + 60) / 2, (RozmiarOknaY - 875), sf::Color(100, 100, 100, 255), &window, 
        bind_rzucanie, 50);
    Button rzucanie_wedka_button = Button(300, 100, (RozmiarOknaX - 650) / 2, (RozmiarOknaY - 875), sf::Color(100, 100, 100, 255), &window,
        "Rzucanie\n   wedki", 50);
    TextBox_znak bind_wciaganie_wedka_button = TextBox_znak(270, 100, (RozmiarOknaX + 60) / 2, (RozmiarOknaY - 725), sf::Color(100, 100, 100, 255), &window,
        bind_wciaganie, 50);
    Button wciaganie_wedka_button = Button(300, 100, (RozmiarOknaX - 650) / 2, (RozmiarOknaY - 725), sf::Color(100, 100, 100, 255), &window,
        "Wciaganie\n   wedki", 50);
    TextBox_znak bind_przejscie_button = TextBox_znak(270, 100, (RozmiarOknaX + 60) / 2, (RozmiarOknaY - 575), sf::Color(100, 100, 100, 255), &window,
        bind_przejscie, 50);
    Button przejscie_button = Button(300, 100, (RozmiarOknaX - 650) / 2, (RozmiarOknaY - 575), sf::Color(100, 100, 100, 255), &window,
        "Przejscie", 50);
    TextBox_znak bind_chodzenie_lewo_button = TextBox_znak(270, 100, (RozmiarOknaX + 60) / 2, (RozmiarOknaY - 425), sf::Color(100, 100, 100, 255), &window,
        bind_chodzenie_lewo, 50);
    Button chodzenie_lewo_button = Button(300, 100, (RozmiarOknaX - 650) / 2, (RozmiarOknaY - 425), sf::Color(100, 100, 100, 255), &window,
        "Chodzenie\n   w lewo", 50);
    TextBox_znak bind_chodzenie_prawo_button = TextBox_znak(270, 100, (RozmiarOknaX + 60) / 2, (RozmiarOknaY - 275), sf::Color(100, 100, 100, 255), &window,
        bind_chodzenie_prawo, 50);
    Button chodzenie_prawo_button = Button(300, 100, (RozmiarOknaX - 650) / 2, (RozmiarOknaY - 275), sf::Color(100, 100, 100, 255), &window,
        "Chodzenie\n  w prawo", 50);
    Button sterowanie_back_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 125), sf::Color(100, 100, 100, 255), &window, "Cofnij", 50);

    Button logowanie_button = Button(300, 100, (RozmiarOknaX + 150) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window, "Konto", 50);
    Button gosc_button = Button(300, 100, (RozmiarOknaX - 750) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window, "Gosc", 50);
    Button start_back_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 350), sf::Color(100, 100, 100, 255), &window, "Cofnij", 50);

    TextBox nazwa_button = TextBox(300, 100, (RozmiarOknaX - 800) / 2, (RozmiarOknaY - 750), sf::Color(100, 100, 100, 255), &window, "Nazwa", 50);
    TextBox haslo_button = TextBox(300, 100, (RozmiarOknaX + 200) / 2, (RozmiarOknaY - 750), sf::Color(100, 100, 100, 255), &window, "Haslo", 50);
    Button zaloguj_sie_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window, "Zaloguj sie", 50);
    Button zarejestruj_sie_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 350), sf::Color(100, 100, 100, 255), &window, "Zarejestruj sie", 50);
    Button logowanie_back_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 150), sf::Color(100, 100, 100, 255), &window, "Cofnij", 50);

    Button wznow_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window, "Wznow", 50);
    Button gra_back_button = Button(400, 100, (RozmiarOknaX - 400) / 2, (RozmiarOknaY - 150), sf::Color(100, 100, 100, 255), &window, "Wyjdz do menu", 50);

    TextBox dodawanie_nazwa_button = TextBox(300, 100, (RozmiarOknaX - 800) / 2, (RozmiarOknaY - 750), sf::Color(100, 100, 100, 255), &window, "Nazwa", 50);
    TextBox dodawanie_haslo_button = TextBox(300, 100, (RozmiarOknaX + 200) / 2, (RozmiarOknaY - 750), sf::Color(100, 100, 100, 255), &window, "Haslo", 50);
    Button dodaj_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window, "Dodaj", 50);
    Button dodawanie_back_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 150), sf::Color(100, 100, 100, 255), &window, "Cofnij", 50);

    int screen = 0;

    std::fstream zapis;
    std::fstream odczyt;
    std::string nazwa;
    std::string haslo;
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

    int rybyNaHaczyku = 0;
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
    bool pomoc_przejscie = false;
    int screen_options_pomoc;
    int screen_gra_pomoc = 1;
    bool escape_pomoc = true;


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
    void zlowRybe(Ryba& ryba);

public:
    Game();
    void run();
    void update(sf::Time deltaTime);
    void render();
};
#endif