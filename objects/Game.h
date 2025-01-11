#ifndef _GAME_
#define _GAME_

#include <SFML/Graphics.hpp>
#include "Ryba.h"
#include "Button.h"
#include "TextBox.h"
#include "TextBox_znak.h"
#include "Popup.h"
#include "Napis.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>

#define character_size_button 45
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
    Button start_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window, "Graj", character_size_button);
    Button options_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 350), sf::Color(100, 100, 100, 255), &window, "Opcje", character_size_button);
    Button quit_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 150), sf::Color(100, 100, 100, 255), &window, "Wyjdz", character_size_button);

    Button sterowanie_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window, "Sterowanie", character_size_button);
    Button options_back_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 350), sf::Color(100, 100, 100, 255), &window, "Cofnij", character_size_button);

    sf::Keyboard::Key bind_rzucanie = sf::Keyboard::E;
    sf::Keyboard::Key bind_wciaganie = sf::Keyboard::Space;
    sf::Keyboard::Key bind_przejscie = sf::Keyboard::Q;
    sf::Keyboard::Key bind_chodzenie_lewo = sf::Keyboard::A;
    sf::Keyboard::Key bind_chodzenie_prawo = sf::Keyboard::D;

    TextBox_znak bind_rzucanie_wedka_button = TextBox_znak(270, 100, (RozmiarOknaX + 60) / 2, (RozmiarOknaY - 875), sf::Color(100, 100, 100, 255), &window, 
        bind_rzucanie, character_size_button);
    Button rzucanie_wedka_button = Button(300, 100, (RozmiarOknaX - 650) / 2, (RozmiarOknaY - 875), sf::Color(100, 100, 100, 255), &window,
        "Rzucanie\n   wedki", character_size_button);
    TextBox_znak bind_wciaganie_wedka_button = TextBox_znak(270, 100, (RozmiarOknaX + 60) / 2, (RozmiarOknaY - 725), sf::Color(100, 100, 100, 255), &window,
        bind_wciaganie, character_size_button);
    Button wciaganie_wedka_button = Button(300, 100, (RozmiarOknaX - 650) / 2, (RozmiarOknaY - 725), sf::Color(100, 100, 100, 255), &window,
        "Wciaganie\n   wedki", character_size_button);
    TextBox_znak bind_przejscie_button = TextBox_znak(270, 100, (RozmiarOknaX + 60) / 2, (RozmiarOknaY - 575), sf::Color(100, 100, 100, 255), &window,
        bind_przejscie, character_size_button);
    Button przejscie_button = Button(300, 100, (RozmiarOknaX - 650) / 2, (RozmiarOknaY - 575), sf::Color(100, 100, 100, 255), &window,
        "Przejscie", character_size_button);
    TextBox_znak bind_chodzenie_lewo_button = TextBox_znak(270, 100, (RozmiarOknaX + 60) / 2, (RozmiarOknaY - 425), sf::Color(100, 100, 100, 255), &window,
        bind_chodzenie_lewo, character_size_button);
    Button chodzenie_lewo_button = Button(300, 100, (RozmiarOknaX - 650) / 2, (RozmiarOknaY - 425), sf::Color(100, 100, 100, 255), &window,
        "Chodzenie\n   w lewo", character_size_button);
    TextBox_znak bind_chodzenie_prawo_button = TextBox_znak(270, 100, (RozmiarOknaX + 60) / 2, (RozmiarOknaY - 275), sf::Color(100, 100, 100, 255), &window,
        bind_chodzenie_prawo, character_size_button);
    Button chodzenie_prawo_button = Button(300, 100, (RozmiarOknaX - 650) / 2, (RozmiarOknaY - 275), sf::Color(100, 100, 100, 255), &window,
        "Chodzenie\n  w prawo", character_size_button);
    Button sterowanie_back_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 125), sf::Color(100, 100, 100, 255), &window, "Cofnij", character_size_button);

    Button logowanie_button = Button(300, 100, (RozmiarOknaX + 150) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window, "Konto", character_size_button);
    Button gosc_button = Button(300, 100, (RozmiarOknaX - 750) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window, "Gosc", character_size_button);
    Button start_back_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 350), sf::Color(100, 100, 100, 255), &window, "Cofnij", character_size_button);

    TextBox nazwa_button = TextBox(300, 100, (RozmiarOknaX - 800) / 2, (RozmiarOknaY - 750), sf::Color(100, 100, 100, 255), &window, "Nazwa", character_size_button);
    TextBox haslo_button = TextBox(300, 100, (RozmiarOknaX + 200) / 2, (RozmiarOknaY - 750), sf::Color(100, 100, 100, 255), &window, "Haslo", character_size_button);
    Button zaloguj_sie_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window, "Zaloguj sie", character_size_button);
    Button zarejestruj_sie_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 350), sf::Color(100, 100, 100, 255), &window, "Zarejestruj sie", character_size_button);
    Button logowanie_back_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 150), sf::Color(100, 100, 100, 255), &window, "Cofnij", character_size_button);

    Button wznow_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window, "Wznow", character_size_button);
    Button gra_back_button = Button(400, 100, (RozmiarOknaX - 400) / 2, (RozmiarOknaY - 150), sf::Color(100, 100, 100, 255), &window, "Wyjdz do menu", character_size_button);

    TextBox dodawanie_nazwa_button = TextBox(300, 100, (RozmiarOknaX - 800) / 2, (RozmiarOknaY - 750), sf::Color(100, 100, 100, 255), &window, "Nazwa", character_size_button);
    TextBox dodawanie_haslo_button = TextBox(300, 100, (RozmiarOknaX + 200) / 2, (RozmiarOknaY - 750), sf::Color(100, 100, 100, 255), &window, "Haslo", character_size_button);
    Button dodaj_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550), sf::Color(100, 100, 100, 255), &window, "Dodaj", character_size_button);
    Button dodawanie_back_button = Button(300, 100, (RozmiarOknaX - 300) / 2, (RozmiarOknaY - 150), sf::Color(100, 100, 100, 255), &window, "Cofnij", character_size_button);

    int screen = 0;

    std::fstream zapis;
    std::fstream odczyt;
    std::string nazwa;
    std::string haslo;

    std::string cena_ryba;
    Popup cena_ryby_napis = Popup(&window, 200, 380, "", 20, sf::Color::Yellow, sf::Color::Red);

    Napis kasa_napis = Napis(&window, 1540, 20, "Pieniadze:", 20, sf::Color::Yellow, sf::Color::Red, -1);
    Napis kasa_wartosc_napis = Napis(&window, 1540, 45, "", 20, sf::Color::Yellow, sf::Color::Red, 0);
    int cala_kasa = 0;

    bool pomoc_lowienie = false;    //jak true to lowimy rybe, jak nie to pusty haczyk
    bool pomoc_lowienie2 = false;   //jak linka peknie to true
    bool pomoc_lowienie3 = false;   //do zrobienia klikania, a nie trzymania przycisku
    int czas_pekania = 0;     
    int lowienie_czas = 0;
    int lowienie_czas_klikniecie = 0;
    int kolor_linki_pekanie1 = 128;
    int kolor_linki_pekanie2_3 = 128;
    float ucieczka_popup_x;
    float ucieczka_popup_y;
    Popup ucieczka_napis = Popup(&window, ucieczka_popup_x, ucieczka_popup_y, "Linka zerwana", 20, sf::Color::Color(128, 128, 128), sf::Color::Black);

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
    void ucieczkaRyby(Ryba& ryba);

public:
    Game();
    void run();
    void update(sf::Time deltaTime);
    void render();
};
#endif