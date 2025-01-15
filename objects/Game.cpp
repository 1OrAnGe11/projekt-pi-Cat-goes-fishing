﻿#include "Game.h"

Game::Game()
{
    srand(time(NULL));
    initBackground();
    initWoda();
    initFala(woda.getPosition().x, powierzchniaWody - 50);
    initFala(woda.getPosition().x + 600, powierzchniaWody - 50);
    initFala(woda.getPosition().x + 1200, powierzchniaWody - 50);
    initWindow();
    initWedka();
    initPlayer();
    initHaczyk();
    initRyby();
    initZanikanie();
    initDrewno();
    initButton();
    initItems();
    initCzapki();

    linka.setFillColor(sf::Color(128, 128, 128)); // Szary kolor 
    linka.setSize(sf::Vector2f(5.0f, 5.0f)); // Pogrubienie linii (szeroko��)

}



void Game::initWindow()   //rozmiar okna itp
{
    window.create(sf::VideoMode(RozmiarOknaX, RozmiarOknaY), "Zmien nazwe");
    window.setFramerateLimit(60);
}

void Game::initBackground()
{
    if (!menu_backgroundTexture.loadFromFile("obrazy/menu_background.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    menu_backgroundSprite.setTexture(menu_backgroundTexture);
    menu_backgroundSprite.setPosition(0, 0);

    if (!options_backgroundTexture.loadFromFile("obrazy/options_background.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    options_backgroundSprite.setTexture(options_backgroundTexture);
    options_backgroundSprite.setPosition(0, 0);

    if (!sterowanie_backgroundTexture.loadFromFile("obrazy/sterowanie_background.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    sterowanie_backgroundSprite.setTexture(sterowanie_backgroundTexture);
    sterowanie_backgroundSprite.setPosition(0, 0);

    if (!sklepy_backgroundTexture.loadFromFile("obrazy/sklepy_background.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    sklepy_backgroundSprite.setTexture(sklepy_backgroundTexture);
    sklepy_backgroundSprite.setPosition(0, 0);

    if (!tloTexture.loadFromFile("obrazy/tlo5.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    tloSprite.setTexture(tloTexture);
    tloSprite.setPosition(0, 0);

    if (!sklep1Texture.loadFromFile("obrazy/sklep1_background.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    sklep1Sprite.setTexture(sklep1Texture);
    sklep1Sprite.setPosition(0, 0);

    if (!sklep2Texture.loadFromFile("obrazy/sklep2_background.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    sklep2Sprite.setTexture(sklep2Texture);
    sklep2Sprite.setPosition(0, 0);

    if (!domTexture.loadFromFile("obrazy/dom_background.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    domSprite.setTexture(domTexture);
    domSprite.setPosition(0, 0);

    if (!ceny_1Texture.loadFromFile("obrazy/ceny_sklep1.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    ceny_1Sprite.setTexture(ceny_1Texture);
    ceny_1Sprite.setPosition(0, 0);

    if (!ceny_2Texture.loadFromFile("obrazy/ceny_sklep2.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    ceny_2Sprite.setTexture(ceny_2Texture);
    ceny_2Sprite.setPosition(0, 0);
}

void Game::initDrewno()
{
    if (!drewnoTexture.loadFromFile("obrazy/drewno.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    drewnoSprite.setTexture(drewnoTexture);
    drewnoSprite.setPosition(-70, player.getPosition().y + 80);
}

void Game::initPlayer()       //do ustawienia pozycji i sprite
{
    if (!playerTexture.loadFromFile("obrazy/player spritesheet pelny.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    player.setPosition(75.0f, 475.0f);
    playerSprite.setPosition(75.0f, 475.0f);
    playerSprite.setTexture(playerTexture);
    playerFrameRect = sf::IntRect(0, 0, 100, 100); // 2 pierwsze to x,y , 2 ostatnie to wymiary 
    playerSprite.setTextureRect(playerFrameRect);
    playerKlatkiSuma = 2; // Ustaw ca�kowit� liczb� klatek 
    dlugoscKlatkiPlayer = 0.3f; // Czas trwania jednej klatki w sekundach (jednak chyba nie w sekundach)
    playerKlatki = 0;
    czas = 0.0f;
    playerFrameRect.left = 300;
    playerSprite.setTextureRect(playerFrameRect);

    if (!dom_playerTexture.loadFromFile("obrazy/player_bezkasy.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    dom_playerSprite.setScale(sf::Vector2f(6, 6));
    dom_playerSprite.setPosition(610, 200);
    dom_playerSprite.setTexture(dom_playerTexture);
    dom_playerFrameRect = sf::IntRect(0, 0, 64, 100);
    dom_playerSprite.setTextureRect(dom_playerFrameRect);
}

void Game::initWedka() {
    if (!wedkaTexture.loadFromFile("obrazy/wedka.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    wedkaSprite.setTexture(wedkaTexture);
    wedkaSprite.setPosition(ConstWedkaInitX, ConstWedkaInitY);
    wedkaSprite.setRotation(-45);
}


void Game::initRyby() {

    ryby = {};
 
    if (!rybaTexture3.loadFromFile("obrazy/ryba3.png", sf::IntRect(0, 0, 23, 12)))
    {
        std::cerr << "Blad wczytywania tekstury ryby!" << std::endl;
    }
       
    if (!rybaTexture2.loadFromFile("obrazy/ryba2.png", sf::IntRect(0, 0, 21, 11)))
    {
        std::cerr << "Blad wczytywania tekstury ryby!" << std::endl;
    }
        
    if (!rybaTexture1.loadFromFile("obrazy/ryba1.png", sf::IntRect(0, 0, 18, 10)))
    {
        std::cerr << "Blad wczytywania tekstury ryby!" << std::endl;
    }

    while (ryby.size() < 25)   // spawnuje ryby co 10 klatek, maksymalnie 25 ryb na raz
    {
        int x1 = rand() % 1390 + 150;    // losowe wspolrzedne ryb (takie, ze nie wychodza poza wode)
        //int x1 = rand() % 30 + 1650;    // losowe wspolrzedne ryb (takie, ze nie wychodza poza wode)
        int y1 = rand() % 230 + 610;

        int r = (rand() % 255 + 0);     // losowe kolory ryb
        int g = (rand() % 255 + 0);
        int b = (rand() % 255 + 0);
        ryby.push_back(Ryba(x1, y1, sf::Color(r, g, b, 255), 2, rybaTexture1, rybaTexture2, rybaTexture3));
    }
 }


void Game::initWoda() {
    woda.setSize(sf::Vector2f(10000.0f, 10000.0f));
    woda.setFillColor(sf::Color(0, 0, 128, 128));
    woda.setPosition(0, powierzchniaWody + 50);//player.getPosition().x + 123
}

void Game::initFala(float x, float y) {
    if (!falaTexture.loadFromFile("obrazy/FALAspritesheet.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    falaSprite.setTexture(falaTexture);
    falaFrameRect = sf::IntRect(0, 0, 600, 100); // 2 pierwsze to x,y , 2 ostatnie to wymiary 
    falaSprite.setTextureRect(falaFrameRect);
    falaSprite.setPosition(x, y);
    falaKlatki = 2; // Ustaw ca�kowit� liczb� klatek 
    dlugoscKlatki = 0.2f; // Czas trwania jednej klatki w sekundach (jednak chyba nie w sekundach)
    klatka = 0;
    czas = 0.0f;
    for (int i = 0; i < 5; ++i) {
        sf::Sprite falaSprite; falaSprite.setTexture(falaTexture);
        falaSprite.setTextureRect(falaFrameRect);
        falaSprite.setPosition(75.0f + i * 550.0f, 475.0f);
        falaSprite.setColor(sf::Color(0, 0, 128, 255));
        falaSprites.push_back(falaSprite);
    }

}

void Game::initHaczyk()       //koniec w�dki (haczyk)
{
    haczyk.setRadius(10.0f);
    haczyk.setFillColor(sf::Color::Red);
    angle = 0.0f;
    isKeyPressed = false;
    //pozycja(do zmiany)
    float xInit = player.getPosition().x + ConstHaczykInitX;
    float yInit = player.getPosition().y - ConstHaczykInitY;
    haczyk.setPosition(xInit, yInit);
}

void Game::initZanikanie() {
    zanikanie.setSize(sf::Vector2f(RozmiarOknaX, RozmiarOknaY));
    zanikanie.setFillColor(sf::Color(0, 0, 0, 0));
}
void Game::przejscie(sf::Time deltaTime)
{
    static float alpha = 0; // Aktualna przezroczystość 
    const float fadeSpeed = 100.0f; // Szybkość przejścia (zmiana przezroczystości na sekundę) 

    if (pomoc_przejscie)
    {
        alpha = 0;
    }
    alpha += fadeSpeed * deltaTime.asSeconds();
    if (alpha > 256) {
        alpha = 0;
        czyPrzejscie = false;
        if (LokalizacjaRyby == true) {
            player.setPosition(RozmiarOknaX - 150.0f, 600.0f);
            screen = 2;
            LokalizacjaRyby = false; 
            playerSprite.setScale(-1.f, 1.f); // Odbicie poziome
            playerSprite.setPosition(playerSprite.getGlobalBounds().width, 0);
            skierowanyWprawo = false;
            screen_gra_pomoc = screen;
        }
        else {
            playerFrameRect.left = 300;
            playerSprite.setTextureRect(playerFrameRect);
            player.setPosition(75.0f, 475.0f);
            playerSprite.setPosition(75.0f, 475.0f);
            if (skierowanyWprawo == false) {
                playerSprite.setScale(1.f, 1.f);
                skierowanyWprawo = true;
            }
            screen = 1;
            LokalizacjaRyby = true;
            playerSprite.setTexture(playerTexture);
            screen_gra_pomoc = screen;
        }
    }


    zanikanie.setFillColor(sf::Color(0, 0, 0, static_cast<sf::Uint8>(alpha)));
    pomoc_przejscie = false;
}

void Game::zlowRybe(Ryba& ryba) {
    pomoc_lowienie = true;
    ryba.czyNaHaczyku = true;
    ryba.lapanie();
    std::cout << "zlapana" << std::endl;
}

void Game::ucieczkaRyby(Ryba& ryba)
{
    ryba.zerwana();
    std::cout << "ucieczka" << std::endl;
}

void Game::initButton()
{

    if (!menu_buttonTexture.loadFromFile("obrazy/menu_button.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }

    if (!krotki_menu_buttonTexture.loadFromFile("obrazy/menu_button_krotki.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }

    if (!dlugi_menu_buttonTexture.loadFromFile("obrazy/menu_button_dlugi.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }

    start_button_sprite.setTexture(menu_buttonTexture);
    start_button_sprite.setPosition((RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550));

    options_button_sprite.setTexture(menu_buttonTexture);
    options_button_sprite.setPosition((RozmiarOknaX - 300) / 2, (RozmiarOknaY - 350));

    quit_button_sprite.setTexture(menu_buttonTexture);
    quit_button_sprite.setPosition((RozmiarOknaX - 300) / 2, (RozmiarOknaY - 150));

    sterowanie_button_sprite.setTexture(menu_buttonTexture);
    sterowanie_button_sprite.setPosition((RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550));

    options_back_button_sprite.setTexture(menu_buttonTexture);
    options_back_button_sprite.setPosition((RozmiarOknaX - 300) / 2, (RozmiarOknaY - 350));

    rzucanie_wedka_button_sprite.setTexture(menu_buttonTexture);
    rzucanie_wedka_button_sprite.setPosition((RozmiarOknaX - 650) / 2, (RozmiarOknaY - 875));

    wciaganie_wedka_button_sprite.setTexture(menu_buttonTexture);
    wciaganie_wedka_button_sprite.setPosition((RozmiarOknaX - 650) / 2, (RozmiarOknaY - 725));

    przejscie_button_sprite.setTexture(menu_buttonTexture);
    przejscie_button_sprite.setPosition((RozmiarOknaX - 650) / 2, (RozmiarOknaY - 575));

    chodzenie_lewo_button_sprite.setTexture(menu_buttonTexture);
    chodzenie_lewo_button_sprite.setPosition((RozmiarOknaX - 650) / 2, (RozmiarOknaY - 425));

    chodzenie_prawo_button_sprite.setTexture(menu_buttonTexture);
    chodzenie_prawo_button_sprite.setPosition((RozmiarOknaX - 650) / 2, (RozmiarOknaY - 275));

    sterowanie_back_button_sprite.setTexture(menu_buttonTexture);
    sterowanie_back_button_sprite.setPosition((RozmiarOknaX - 300) / 2, (RozmiarOknaY - 125));

    logowanie_button_sprite.setTexture(menu_buttonTexture);
    logowanie_button_sprite.setPosition((RozmiarOknaX + 150) / 2, (RozmiarOknaY - 550));

    gosc_button_sprite.setTexture(menu_buttonTexture);
    gosc_button_sprite.setPosition((RozmiarOknaX - 750) / 2, (RozmiarOknaY - 550));

    start_back_button_sprite.setTexture(menu_buttonTexture);
    start_back_button_sprite.setPosition((RozmiarOknaX - 300) / 2, (RozmiarOknaY - 350));

    zaloguj_sie_button_sprite.setTexture(menu_buttonTexture);
    zaloguj_sie_button_sprite.setPosition((RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550));

    zarejestruj_sie_button_sprite.setTexture(menu_buttonTexture);
    zarejestruj_sie_button_sprite.setPosition((RozmiarOknaX - 300) / 2, (RozmiarOknaY - 350));

    logowanie_back_button_sprite.setTexture(menu_buttonTexture);
    logowanie_back_button_sprite.setPosition((RozmiarOknaX - 300) / 2, (RozmiarOknaY - 150));

    wznow_button_sprite.setTexture(menu_buttonTexture);
    wznow_button_sprite.setPosition((RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550));

    gra_back_button_sprite.setTexture(dlugi_menu_buttonTexture);
    gra_back_button_sprite.setPosition((RozmiarOknaX - 400) / 2, (RozmiarOknaY - 150));

    dodaj_button_sprite.setTexture(menu_buttonTexture);
    dodaj_button_sprite.setPosition((RozmiarOknaX - 300) / 2, (RozmiarOknaY - 550));

    dodawanie_back_button_sprite.setTexture(menu_buttonTexture);
    dodawanie_back_button_sprite.setPosition((RozmiarOknaX - 300) / 2, (RozmiarOknaY - 150));

    nazwa_button_sprite.setTexture(menu_buttonTexture);
    nazwa_button_sprite.setPosition((RozmiarOknaX - 800) / 2, (RozmiarOknaY - 750));

    haslo_button_sprite.setTexture(menu_buttonTexture);
    haslo_button_sprite.setPosition((RozmiarOknaX + 200) / 2, (RozmiarOknaY - 750));

    dodawanie_nazwa_button_sprite.setTexture(menu_buttonTexture);
    dodawanie_nazwa_button_sprite.setPosition((RozmiarOknaX - 800) / 2, (RozmiarOknaY - 750));

    dodawanie_haslo_button_sprite.setTexture(menu_buttonTexture);
    dodawanie_haslo_button_sprite.setPosition((RozmiarOknaX + 200) / 2, (RozmiarOknaY - 750));

    bind_rzucanie_wedka_button_sprite.setTexture(krotki_menu_buttonTexture);
    bind_rzucanie_wedka_button_sprite.setPosition((RozmiarOknaX + 60) / 2, (RozmiarOknaY - 875));

    bind_wciaganie_wedka_button_sprite.setTexture(krotki_menu_buttonTexture);
    bind_wciaganie_wedka_button_sprite.setPosition((RozmiarOknaX + 60) / 2, (RozmiarOknaY - 725));

    bind_przejscie_button_sprite.setTexture(krotki_menu_buttonTexture);
    bind_przejscie_button_sprite.setPosition((RozmiarOknaX + 60) / 2, (RozmiarOknaY - 575));

    bind_chodzenie_lewo_button_sprite.setTexture(krotki_menu_buttonTexture);
    bind_chodzenie_lewo_button_sprite.setPosition((RozmiarOknaX + 60) / 2, (RozmiarOknaY - 425));

    bind_chodzenie_prawo_button_sprite.setTexture(krotki_menu_buttonTexture);
    bind_chodzenie_prawo_button_sprite.setPosition((RozmiarOknaX + 60) / 2, (RozmiarOknaY - 275));
}

void Game::initCzapki()
{
    if (!czapka1Texture.loadFromFile("obrazy/czapa1.png"))          //czapa 1
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    czapka1Sprite.setTexture(czapka1Texture);
    czapka1Sprite.setScale(sf::Vector2f(1.5, 1.5));
    czapka1Sprite.setPosition(170, 37);

    if (!czapka2Texture.loadFromFile("obrazy/czapa2.png"))          //czapa 2
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    czapka2Sprite.setTexture(czapka2Texture);
    czapka2Sprite.setScale(sf::Vector2f(1.5, 1.5));
    czapka2Sprite.setPosition(170, 192);

    if (!czapka3Texture.loadFromFile("obrazy/czapa3.png"))          //czapa 3
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    czapka3Sprite.setTexture(czapka3Texture);
    czapka3Sprite.setScale(sf::Vector2f(1.5, 1.5));
    czapka3Sprite.setPosition(170, 347);

    if (!czapka4Texture.loadFromFile("obrazy/czapa4.png"))          //czapa 4
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    czapka4Sprite.setTexture(czapka4Texture);
    czapka4Sprite.setScale(sf::Vector2f(1.5, 1.5));
    czapka4Sprite.setPosition(1160, 37);

    if (!czapka5Texture.loadFromFile("obrazy/czapa5.png"))          //czapa 5
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    czapka5Sprite.setTexture(czapka5Texture);
    czapka5Sprite.setScale(sf::Vector2f(1.5, 1.5));
    czapka5Sprite.setPosition(1160, 192);

    if (!czapka6Texture.loadFromFile("obrazy/czapa6.png"))          //czapa 6
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    czapka6Sprite.setTexture(czapka6Texture);
    czapka6Sprite.setScale(sf::Vector2f(1.5, 1.5));
    czapka6Sprite.setPosition(1160, 347);
}

void Game::initItems()
{
    if (!itemTexture.loadFromFile("obrazy/item.png"))          //czapa 1
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    itemSprite.setTexture(itemTexture);
    itemSprite.setScale(sf::Vector2f(1.5, 1.5));
    itemSprite.setPosition(170, 37);
}

void Game::wczytajDaneGracza() 
{

}

void Game::run() {
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1)  //dodawanie kasy, do testowania
            {
                cala_kasa += 100;
                kasa_wartosc_napis.render("", kasa_wartosc_napis.wartosc);
            }

            if (event.type == sf::Event::Closed)//zamknij okno
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && (screen == 1 || screen == 2))  //zatrzymanie gry
            {
                screen_gra_pomoc = screen;
                screen = 8;
            }

            //if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && screen == 8)   // wznowienie gry za pomoca przycisku Escape
            //{
            //    screen = screen_gra_pomoc;
            //}

            if (pomoc_lowienie)
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == bind_wciaganie && screen == 1 /*&& pomoc_lowienie3*/)//ciagniecie z ryba
                {
                    //pomoc_lowienie3 = false;
                    lowienie_czas_klikniecie = lowienie_czas;
                    czas_pekania++;
                    kolor_linki_R += int(127 / ilosc_klik_pekniecie);
                    kolor_linki_G_B -= int(127 / ilosc_klik_pekniecie);
                    linka.setFillColor(sf::Color(kolor_linki_R, kolor_linki_G_B, kolor_linki_G_B));
                    if (rzut == false && zarzucanie == false) {
                        promien_x -= szybkoscWciagania;
                        promien_y -= szybkoscWciagania;
                        //if (haczyk.getPosition().y > 474) //bo inaczej nie da sie wci�ga� gdy koliduje z brzegiem
                        //{
                        //    //float y = player.getPosition().y + player.getSize().y / 2 + promien * sin(angle);
                        //    //opcja wyzej jest lepsza ale pobugowana
                        //    float y = haczyk.getPosition().y - szybkoscWciagania;
                        //    //if()
                        //    float x = haczyk.getPosition().x - szybkoscWciagania;
                        //    haczyk.setPosition(x, y);
                        //}
                    }
                }

                /*if (event.type == sf::Event::KeyReleased && event.key.code == bind_wciaganie && screen == 1)
                {
                    pomoc_lowienie3 = true;
                }*/

                if (czas_pekania == ilosc_klik_pekniecie) //ile klikniec do pekniecia
                {
                    float ucieczka_popup_x = haczyk.getPosition().x;
                    float ucieczka_popup_y = haczyk.getPosition().y;
                    ucieczka_napis.zmien_nazwe_miejsce(ucieczka_popup_x, ucieczka_popup_y, -1);
                    ucieczka_napis.pomoc_popup = true;
                    czas_pekania = 0;
                    pomoc_lowienie2 = true;
                    pomoc_lowienie = false;
                    kolor_linki_R = 128;
                    kolor_linki_G_B = 128;
                    linka.setFillColor(sf::Color(kolor_linki_R, kolor_linki_G_B, kolor_linki_G_B));
                }
            }
            else
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == bind_wciaganie && screen == 1)//ciagniecie bez ryby  
                {
                    if (rzut == false && zarzucanie == false) {
                        promien_x -= szybkoscWciagania;
                        promien_y -= szybkoscWciagania;
                        //if (haczyk.getPosition().y > 474) //bo inaczej nie da sie wci�ga� gdy koliduje z brzegiem
                        //{
                        //    //float y = player.getPosition().y + player.getSize().y / 2 + promien * sin(angle);
                        //    //opcja wyzej jest lepsza ale pobugowana
                        //    float y = haczyk.getPosition().y - szybkoscWciagania;
                        //    float x = haczyk.getPosition().x - szybkoscWciagania;
                        //    haczyk.setPosition(x, y);
                        //}
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == bind_rzucanie && zarzucanie == false && rzut == false && czyTrzyma && screen == 1) {//zarzu� w�dke (bind do zmiany)
                zarzucanie = true;
                rzut = true;
                czyTrzyma = false;
                rybyNaHaczyku = 0;
            }

            if ( (screen == 1 || screen == 2) && event.type == sf::Event::KeyPressed && event.key.code == bind_przejscie && czyPrzejscie == false) {

                czyPrzejscie = true;
            }
            if (event.type == sf::Event::KeyPressed && (event.key.code == bind_chodzenie_lewo || event.key.code == bind_chodzenie_prawo) && czyPrzejscie == false && LokalizacjaRyby == false) {
                if (player.getPosition().x + predkosc > 10 && player.getPosition().x + predkosc < RozmiarOknaX - 10) {
                    predkosc = ConstPlayerSpeed;
                }
                if (event.key.code == bind_chodzenie_lewo) {
                    predkosc *= -1;
                    if (skierowanyWprawo == true) {
                        playerSprite.setScale(-1.f, 1.f); // lustrzane odbicie poziome
                        playerSprite.setPosition(playerSprite.getGlobalBounds().width, 0);
                        skierowanyWprawo = false;
                    }

                }
                else if (skierowanyWprawo == false) {
                    playerSprite.setScale(1.f, 1.f);
                    playerSprite.setPosition(playerSprite.getGlobalBounds().width, 0);
                    skierowanyWprawo = true;
                }
            }
            if (event.type == sf::Event::KeyReleased && (event.key.code == bind_chodzenie_lewo || event.key.code == bind_chodzenie_prawo)) {
                predkosc = 0;
            }


            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && (screen == 10 || screen == 11 || screen == 12))
            {
                screen = 2;         //wychodzenie ze sklepu po nacisnieciu Escape
            }
            switch (screen)
            {
            case 0:     //menu
                if (start_button.clicked(event))
                {
                    screen = 6;
                    continue;
                }
                if (options_button.clicked(event))
                {
                    screen_options_pomoc = 0;
                    screen = 3;
                    continue;
                }
                if (quit_button.clicked(event))
                {
                    screen = 4;
                    continue;
                }
                break;
            case 1:     //gra
                kasa_wartosc_napis.wartosc = cala_kasa;
                kasa_wartosc_napis.render("", kasa_wartosc_napis.wartosc);
                break;
            case 2:     //sklepy
                kasa_wartosc_napis.wartosc = cala_kasa;
                kasa_wartosc_napis.render("", kasa_wartosc_napis.wartosc);

                //sklep 1 (prawy)
                if (player.getPosition().x >= 1270 && player.getPosition().x <= 1365 && event.type == sf::Event::KeyPressed 
                    && event.key.code == sf::Keyboard::F && skierowanyWprawo)       //obrocony w prawo
                {
                    screen = 10;    
                    continue;
                }

                if (player.getPosition().x >= 1330 && player.getPosition().x <= 1410 && event.type == sf::Event::KeyPressed
                    && event.key.code == sf::Keyboard::F && !skierowanyWprawo)       //obrocony w lewo
                {
                    screen = 10;    
                    continue;
                }

                //sklep 2 (lewy)
                if (player.getPosition().x >= 190 && player.getPosition().x <= 285 && event.type == sf::Event::KeyPressed
                    && event.key.code == sf::Keyboard::F && skierowanyWprawo)       //obrocony w prawo
                {
                    screen = 11;
                    continue;
                }

                if (player.getPosition().x >= 240 && player.getPosition().x <= 335 && event.type == sf::Event::KeyPressed
                    && event.key.code == sf::Keyboard::F && !skierowanyWprawo)       //obrocony w lewo
                {
                    screen = 11;
                    continue;
                }

                //dom/garderoba
                if (player.getPosition().x >= 720 && player.getPosition().x <= 815 && event.type == sf::Event::KeyPressed
                    && event.key.code == sf::Keyboard::F && skierowanyWprawo)       //obrocony w prawo
                {
                    screen = 12;
                    continue;
                }

                if (player.getPosition().x >= 775 && player.getPosition().x <= 875 && event.type == sf::Event::KeyPressed
                    && event.key.code == sf::Keyboard::F && !skierowanyWprawo)       //obrocony w lewo
                {
                    screen = 12;
                    continue;
                }

                break;
            case 3:     //opcje
                if (sterowanie_button.clicked(event))
                {
                    screen = 5;
                    continue;
                }
                if (options_back_button.clicked(event))
                    screen = screen_options_pomoc;
                break;
            case 4:     //wyjscie
                break;
            case 5:     //zmiana sterowania
                bind_rzucanie_wedka_button.key_bind(event);
                bind_rzucanie = bind_rzucanie_wedka_button.bind;
                if (bind_rzucanie == 0)
                    bind_rzucanie = sf::Keyboard::E;

                bind_wciaganie_wedka_button.key_bind(event);
                bind_wciaganie = bind_wciaganie_wedka_button.bind;
                if (bind_wciaganie == 0)
                    bind_wciaganie = sf::Keyboard::Space;

                bind_przejscie_button.key_bind(event);
                bind_przejscie = bind_przejscie_button.bind;
                if (bind_przejscie == 0)
                    bind_przejscie = sf::Keyboard::Q;

                bind_chodzenie_lewo_button.key_bind(event);
                bind_chodzenie_lewo = bind_chodzenie_lewo_button.bind;
                if (bind_chodzenie_lewo == 0)
                    bind_chodzenie_lewo = sf::Keyboard::A;

                bind_chodzenie_prawo_button.key_bind(event);
                bind_chodzenie_prawo = bind_chodzenie_prawo_button.bind;
                if (bind_chodzenie_prawo == 0)
                    bind_chodzenie_prawo = sf::Keyboard::D;

                if (sterowanie_back_button.clicked(event))
                {
                    screen = 3;
                    continue;
                }
                break;
            case 6:     //wybor konta
                if (gosc_button.clicked(event))
                {
                    screen = screen_gra_pomoc;
                    continue;
                }
                if (logowanie_button.clicked(event))
                {
                    screen = 7;
                    continue;
                }
                if (start_back_button.clicked(event))
                {
                    screen = 0;
                    continue;
                }
            case 7:     //logowanie do konta
                if (nazwa_button.clicked(event))
                {
                    nazwa_button.pomoc = true;
                    continue;
                }

                if (haslo_button.clicked(event))
                {
                    haslo_button.pomoc = true;
                    continue;
                }

                haslo_button.wpisywanie(event);
                nazwa_button.wpisywanie(event);

                if (zaloguj_sie_button.clicked(event))
                {
                    odczyt.open("konta.txt", std::ios::in);

                    std::string konto_string;
                    std::string ss;
                    std::vector<std::string> seglist;
                    while (getline(odczyt, konto_string))
                    {
                        std::stringstream s(konto_string);
                        while (getline(s, ss, ';'))
                        {
                            seglist.push_back(ss);
                        }
                        if (nazwa_button.input == seglist[0] && haslo_button.input == seglist[1])
                        {
                            screen = 1;
                            nazwa1 = nazwa_button.input;
                            haslo1 = haslo_button.input;
                            wczytajDaneGracza();
                            continue;
                        }
                        else
                        {
                            zaloguj_sie_button.zmien_nazwe("   Konto\nnie istnieje");
                        }
                        seglist.clear();
                    }

                    odczyt.close();
                    continue;
                }
                if (nazwa_button.clicked(event) || haslo_button.clicked(event))
                {
                    zaloguj_sie_button.zmien_nazwe("Zaloguj sie");
                    continue;
                }
                if (zarejestruj_sie_button.clicked(event))
                {
                    screen = 9;
                    continue;
                }
                if (logowanie_back_button.clicked(event))
                {
                    screen = 6;
                    continue;
                }
                break;
            case 8:     //zatrzymanie (escape podczas gry)
                czyPrzejscie = false;
                zanikanie.setFillColor(sf::Color(0, 0, 0, 0));
                if (wznow_button.clicked(event))
                {
                    screen = screen_gra_pomoc;
                    pomoc_przejscie = true;
                    continue;
                }
                if (options_button.clicked(event))
                {
                    screen_options_pomoc = 8;
                    screen = 3;
                    continue;
                }
                if (gra_back_button.clicked(event))
                {
                    pomoc_przejscie = true;
                    screen = 0;
                    continue;
                }
                break;
            case 9:     //dodawanie konta

                if (dodawanie_nazwa_button.clicked(event))
                {
                    dodawanie_nazwa_button.pomoc = true;
                    continue;
                }

                if (dodawanie_haslo_button.clicked(event))
                {
                    dodawanie_haslo_button.pomoc = true;
                    continue;
                }

                dodawanie_haslo_button.wpisywanie(event);
                dodawanie_nazwa_button.wpisywanie(event);

                if (dodaj_button.clicked(event))
                {
                    odczyt.open("konta.txt", std::ios::in);

                    std::string konto_string;
                    std::string ss;
                    std::vector<std::string> seglist;
                    bool pomoc_konta = false;

                    odczyt.seekp(0, std::ios::end);
                    size_t size = odczyt.tellg();

                    odczyt.clear();  // Resetuje flagi błędu EOF
                    odczyt.seekg(0, std::ios::beg);  // Ustawia wskaźnik odczytu na początek pliku


                    if (size == 0)
                    {
                        pomoc_konta = true;
                    }
                    else
                    {
                        while (getline(odczyt, konto_string))
                        {
                            std::stringstream s(konto_string);
                            while (getline(s, ss, ';'))
                            {
                                seglist.push_back(ss);
                            }
                            if (dodawanie_nazwa_button.input == seglist[0])
                            {
                                dodaj_button.zmien_nazwe("   Juz\nistnieje");
                                pomoc_konta = false;
                                break;
                            }
                            else
                            {
                                pomoc_konta = true;
                                /*nazwa1 = nazwa_button.input;
                                std::cout << nazwa1 << std::endl;
                                nazwa1 += ".txt";
                                std::cout << nazwa1 <<std::endl;
                                zapis.open(nazwa1,std::ios::out);
                                zapis << 0 <<";" << maxRybyNaHaczyku << ";" << szybkoscWciagania << ";" << linkaResetUpgrade << ";" << ilosc_klik_pekniecie;
                                zapis.close();*/
                            }
                            seglist.clear();
                        }
                    }
                    odczyt.close();

                    if (pomoc_konta)
                    {
                        zapis.open("konta.txt", std::ios::out | std::ios::app);
                        zapis << dodawanie_nazwa_button.input << ";" << dodawanie_haslo_button.input << ";" << std::endl;
                        zapis.close();
                    }
                    continue;
                }

                if (dodawanie_nazwa_button.clicked(event) || dodawanie_haslo_button.clicked(event))
                {
                    dodaj_button.zmien_nazwe("Dodaj");
                    continue;
                }

                if (dodawanie_back_button.clicked(event))
                {
                    screen = 7;
                    continue;
                }
                break;
            case 10:        //sklep 1
                kasa_wartosc_napis.wartosc = cala_kasa;
                kasa_wartosc_napis.render("", kasa_wartosc_napis.wartosc);

                if (item.clicked(event) && cala_kasa >= 50)
                {
                    cala_kasa -= 50;
                    itemSprite.setPosition(0, -300);
                    continue;
                }

                break;
            case 11:        //sklep 2
                kasa_wartosc_napis.wartosc = cala_kasa;
                kasa_wartosc_napis.render("", kasa_wartosc_napis.wartosc);

                if (czapka1.clicked(event) && !czapka1_kupiona && cala_kasa >= 50)    //czapka 1
                {
                    cala_kasa -= 50;
                    czapka1_kupiona = true;
                    czapka1Sprite.setPosition(0, -300);
                    continue;
                }

                if (czapka2.clicked(event) && !czapka2_kupiona && cala_kasa >= 50)    //czapka 2
                {
                    cala_kasa -= 50;
                    czapka2_kupiona = true;
                    czapka2Sprite.setPosition(0, -300);
                    continue;
                }

                if (czapka3.clicked(event) && !czapka3_kupiona && cala_kasa >= 50)    //czapka 3
                {
                    cala_kasa -= 50;
                    czapka3_kupiona = true;
                    czapka3Sprite.setPosition(0, -300);
                    continue;
                }

                if (czapka4.clicked(event) && !czapka4_kupiona && cala_kasa >= 50)    //czapka 4
                {
                    cala_kasa -= 50;
                    czapka4_kupiona = true;
                    czapka4Sprite.setPosition(0, -300);
                    continue;
                }

                if (czapka5.clicked(event) && !czapka5_kupiona && cala_kasa >= 50)    //czapka 5
                {
                    cala_kasa -= 50;
                    czapka5_kupiona = true;
                    czapka5Sprite.setPosition(0, -300);
                    continue;
                }

                if (czapka6.clicked(event) && !czapka6_kupiona && cala_kasa >= 50)    //czapka 6
                {
                    cala_kasa -= 50;
                    czapka6_kupiona = true;
                    czapka6Sprite.setPosition(0, -300);
                    continue;
                }

                break;
            case 12:        //dom
                kasa_wartosc_napis.wartosc = cala_kasa;
                kasa_wartosc_napis.render("", kasa_wartosc_napis.wartosc);

                if (czapka1.clicked(event) && typ_czapki == 0 && czapka1_kupiona)    //czapka 1
                {
                    zalozona1_pierwszyraz = true;
                    typ_czapki = 1;
                    czapka1Sprite.setPosition(0, -300);
                    continue;
                }

                if (czapka1.clicked(event) && typ_czapki == 1)
                {
                    typ_czapki = 0;
                    czapka1Sprite.setPosition(170, 37);
                    continue;
                }

                if (czapka1_kupiona && !zalozona1_pierwszyraz)
                    czapka1Sprite.setPosition(170, 37);

                if (czapka2.clicked(event) && typ_czapki == 0 && czapka2_kupiona)    //czapka 2
                {
                    zalozona2_pierwszyraz = true;
                    typ_czapki = 2;
                    czapka2Sprite.setPosition(0, -300);
                    continue;
                }

                if (czapka2.clicked(event) && typ_czapki == 2)
                {
                    typ_czapki = 0;
                    czapka2Sprite.setPosition(170, 192);
                    continue;
                }

                if (czapka2_kupiona && !zalozona2_pierwszyraz)
                {
                    czapka2Sprite.setPosition(170, 192);
                }

                if (czapka3.clicked(event) && typ_czapki == 0 && czapka3_kupiona)    //czapka 3
                {
                    zalozona3_pierwszyraz = true;
                    typ_czapki = 3;
                    czapka3Sprite.setPosition(0, -300);
                    continue;
                }

                if (czapka3.clicked(event) && typ_czapki == 3)
                {
                    typ_czapki = 0;
                    czapka3Sprite.setPosition(170, 347);
                    continue;
                }

                if (czapka3_kupiona && !zalozona3_pierwszyraz)
                    czapka3Sprite.setPosition(170, 347);

                if (czapka4.clicked(event) && typ_czapki == 0 && czapka4_kupiona)    //czapka 4
                {
                    zalozona4_pierwszyraz = true;
                    typ_czapki = 4;
                    czapka4Sprite.setPosition(0, -300);
                    continue;
                }

                if (czapka4.clicked(event) && typ_czapki == 4)
                {
                    typ_czapki = 0;
                    czapka4Sprite.setPosition(1160, 37);
                    continue;
                }

                if (czapka4_kupiona && !zalozona4_pierwszyraz)
                    czapka4Sprite.setPosition(1160, 37);

                if (czapka5.clicked(event) && typ_czapki == 0 && czapka5_kupiona)    //czapka 5
                {
                    zalozona5_pierwszyraz = true;
                    typ_czapki = 5;
                    czapka5Sprite.setPosition(0, -300);
                    continue;
                }

                if (czapka5.clicked(event) && typ_czapki == 5)
                {
                    typ_czapki = 0;
                    czapka5Sprite.setPosition(1160, 192);
                    continue;
                }

                if (czapka5_kupiona && !zalozona5_pierwszyraz)
                    czapka5Sprite.setPosition(1160, 192);

                if (czapka6.clicked(event) && typ_czapki == 0 && czapka6_kupiona)    //czapka 6
                {
                    zalozona6_pierwszyraz = true;
                    typ_czapki = 6;
                    czapka6Sprite.setPosition(0, -300);
                    continue;
                }

                if (czapka6.clicked(event) && typ_czapki == 6)
                {
                    typ_czapki = 0;
                    czapka6Sprite.setPosition(1160, 347);
                    continue;
                }

                if (czapka6_kupiona && !zalozona6_pierwszyraz)
                    czapka6Sprite.setPosition(1160, 347);
                break;
            }

        }
        update(sf::seconds(1.f / 60.f)); 
        render();
    }
}

void Game::update(sf::Time deltaTime)
{

    klatka++;

    float predkoscKatowa = predkoscLiniowa / ((promien_y + promien_x) / 2);

    if (czyPrzejscie) {
        przejscie(deltaTime);
    }
    switch (screen)
    {
    case 0:
        break;
    case 1:

        if (pomoc_lowienie)
        {
            lowienie_czas++;
        }

        if (lowienie_czas - lowienie_czas_klikniecie > linkaResetUpgrade && czas_pekania != 0)     // linkaResetUpgrade - odpowiada za czas, podczas ktorego nie mozna klikac, zeby linka sie zresetowala
        {
            czas_pekania--;
            kolor_linki_R -= int(127 / ilosc_klik_pekniecie);
            kolor_linki_G_B += int(127 / ilosc_klik_pekniecie);
            linka.setFillColor(sf::Color(kolor_linki_R, kolor_linki_G_B, kolor_linki_G_B));
        }
        // Aktualizacja pozycji haczyka

        if (player.getPosition().x + player.getSize().x / 2 + promien_x * cos(angle) > player.getPosition().x + ConstHaczykInitX)
            angle += predkoscKatowa;
        if (angle > 2 * M_PI)
            angle -= 2 * M_PI;

        if (rzut == false && czyTrzyma == false) {    //spadanie haczyka
            float x = player.getPosition().x + player.getSize().x / 2 + promien_x * cos(angle);
            if (x <= player.getPosition().x + ConstHaczykInitX) {
                x = player.getPosition().x + ConstHaczykInitX;
            }
            float y = player.getPosition().y + player.getSize().y / 2 + promien_y  * sin(angle) + poprawka_ladowanie_haczyka;

            //(RozmiarOknaY - powierzchniaWody)
            haczyk.setPosition(x, y);
        }

        if (haczyk.getPosition().y <= powierzchniaWody + poprawka_ladowanie_haczyka && rzut == true) {  //zarzucenie wedki
            if (zarzucanie == true) {  //animacja zamachu do tylu wedka
                if (haczyk.getPosition().x > player.getPosition().x)
                {
                    float x = haczyk.getPosition().x - 4;  //szybkosc animacji zarzucania
                    float y = haczyk.getPosition().y - 1.3; //szybkosc animacji zarzucania
                    haczyk.setPosition(x, y);
                }
                else {
                    zarzucanie = false;

                }
            }
            else if (zarzucanie == false)//rzut
            {
                float x = haczyk.getPosition().x + ConstSpeedX;
                float y = haczyk.getPosition().y - speedY;
                speedY -= odleglosc_rzutu; //odleglosc rzutu
                haczyk.setPosition(x, y);
            }
            czyTrzyma = false;
            promien_x = sqrt((haczyk.getPosition().x - player.getPosition().x) * (haczyk.getPosition().x - player.getPosition().x) + (haczyk.getPosition().y - player.getPosition().y) * (haczyk.getPosition().y - player.getPosition().y));
            promien_y = RozmiarOknaY - powierzchniaWody;
            angle = atan2(haczyk.getPosition().y - player.getPosition().y, haczyk.getPosition().x - player.getPosition().x);
        }
        else {
            rzut = false;
        }
        if (promien_y < 20 && zarzucanie == false) {  //lapanie haczyka
            czyTrzyma = true;
            haczyk.setPosition(player.getPosition().x + ConstHaczykInitX, player.getPosition().y - ConstHaczykInitY);
            speedY = ConstSpeedY;

            kolor_linki_R = 128;
            kolor_linki_G_B = 128;
            linka.setFillColor(sf::Color(kolor_linki_R, kolor_linki_G_B, kolor_linki_G_B));
            pomoc_lowienie2 = false;
            pomoc_lowienie = false;
            czas_pekania = 0;
            cena_ryby_napis.pomoc_popup = true;
            rybyNaHaczyku--;
            kasa_wartosc_napis.wartosc = cala_kasa;
            kasa_wartosc_napis.render("", kasa_wartosc_napis.wartosc);  //dupa

            //dla ryb
            for (auto& ryba : ryby) {
                if (ryba.czyNaHaczyku) {
                    
                    cena_ryby_napis.zmien_nazwe_miejsce(200, 380, ryba.cena);
                    cala_kasa += ryba.cena;
                    ryba.kill();
                }
            }
        }

        czas += deltaTime.asSeconds();
        if (czas >= dlugoscKlatki) {    //animacja fali
            czas = 0.0f;
            falaKlatki++;
            if (falaKlatki > 3) {
                falaKlatki = 0;
            }
            if (falaKlatki < 3) {
                falaFrameRect.left = falaKlatki * 600;
            }
            else {
                falaFrameRect.left = 600;
            }
            for (auto& falaSprite : falaSprites) { falaSprite.setTextureRect(falaFrameRect); }
        }

        //animacja wędki

        if (zarzucanie == true) {
            float dx = ConstWedkaInitX - haczyk.getPosition().x;
            float dy = ConstWedkaInitY - haczyk.getPosition().y;
            wedkaSprite.setRotation(std::atan2(dy, dx) * 180 / M_PI - 180);
            animacjaWedka2 = true;
            katWedki = std::atan2(dy, dx) * 180 / M_PI - 180 * -1;
            //std::cout << katWedki << std::endl;
        }
        else if (animacjaWedka2 == true && katWedki <= 319.0) {//&& std::atan2(wedkaSprite.getPosition().y, wedkaSprite.getPosition().x) != -M_PI / 4) {
            //std::cout << atan2(wedkaSprite.getPosition().y, wedkaSprite.getPosition().x)<<" "<< wedkaSprite.getPosition().y <<" " << wedkaSprite.getPosition().x << std::endl;
            float dx = ConstWedkaInitX - haczyk.getPosition().x;
            float dy = ConstWedkaInitY - haczyk.getPosition().y;
            wedkaSprite.setRotation(std::atan2(dy, dx) * 180 / M_PI - 180 * -1);
            katWedki = std::atan2(dy, dx) * 180 / M_PI - 180 * -1;
            //std::cout << katWedki << std::endl;
            //float endX = ConstWedkaInitX + 100 / (std::cos(katWedki*M_PI/180));
            //float endY = ConstWedkaInitY + 100 / (std::sin(katWedki * M_PI / 180));
            //float endX = player.getPosition().x + ConstWedkaInitX * std::cos(katWedki * M_PI / 180) - ConstWedkaInitY * std::sin(katWedki * M_PI / 180);
            //float endY = player.getPosition().y + ConstWedkaInitX * std::sin(katWedki * M_PI / 180) + ConstWedkaInitY * std::cos(katWedki * M_PI / 180);


        }
        else
        {
            animacjaWedka2 = false;
        }
        //std::cout << animacjaWedka2 << std::endl;

        // Aktualizacja linki 

        if (zarzucanie == false) {
            float dx = haczyk.getPosition().x - (player.getPosition().x + ConstHaczykInitX);
            float dy = haczyk.getPosition().y - (player.getPosition().y - ConstHaczykInitY);
            float length = std::sqrt(dx * dx + dy * dy);
            linka.setSize(sf::Vector2f(length, 3.0f)); // 3.0f to grubosc linki 
            if (animacjaWedka2 == false) {
                linka.setPosition(player.getPosition().x + ConstHaczykInitX, player.getPosition().y - ConstHaczykInitY);
            }
            else {
                float deltaX = 100 * (std::cos(katWedki * (M_PI / 180)));
                float deltaY = 100 * (std::sin(katWedki * (M_PI / 180)));
                deltaX += ConstWedkaInitX;
                deltaY += ConstWedkaInitY;
                linka.setPosition(deltaX + 1, deltaY + 7);
                dx = haczyk.getPosition().x - (deltaX + 1);
                dy = haczyk.getPosition().y - (deltaY + 7);
                length = std::sqrt(dx * dx + dy * dy);
                linka.setSize(sf::Vector2f(length, 3.0f));
            }
            linka.setRotation(std::atan2(dy, dx) * 180 / M_PI);
        }

        for (auto& ryba : ryby) {
            ryba.update();
        }

        if (klatka > 10000) { //bo inaczej wyjdzie poza zakres int 
            klatka = 0;
        }

        //łowienie ryby

        for (auto& ryba : ryby) {
            float haczykX = haczyk.getPosition().x;
            float haczykY = haczyk.getPosition().y;
            float rybaX = ryba.x + ((ryba.rybaSprite.getTexture()->getSize().x / 2) * 0.7 * ryba.rybaSprite.getScale().x);
            float rybaY = ryba.y + (ryba.rybaSprite.getTexture()->getSize().y / 2 * ryba.rybaSprite.getScale().y);
            float odleglosc = sqrt(pow(rybaX - haczykX, 2) + pow(rybaY - haczykY, 2));
            if (odleglosc <= 12 && ryba.czyNaHaczyku == false && haczyk.getPosition().y > powierzchniaWody && rzut == false) {
                if (rybyNaHaczyku < maxRybyNaHaczyku)
                {
                    zlowRybe(ryba);
                    rybyNaHaczyku++;
                }
            }
            if (ryba.czyNaHaczyku == true) {
                if(ryba.kierunek)
                    ryba.setPos(haczyk.getPosition().x + (26 + ryba.poprawka_wspolrzednych), haczyk.getPosition().y);
                else
                    ryba.setPos(haczyk.getPosition().x - (6 + ryba.poprawka_wspolrzednych), haczyk.getPosition().y);

                if (pomoc_lowienie2 && rybyNaHaczyku > 0)
                {
                    ucieczkaRyby(ryba);
                    rybyNaHaczyku--;
                    czyTrzyma = true;
                    haczyk.setPosition(player.getPosition().x + ConstHaczykInitX, player.getPosition().y - ConstHaczykInitY);
                    speedY = ConstSpeedY;
                    pomoc_lowienie2 = false;
                }
            }
            
            //std::cout << ryba.czyNaHaczyku << " ";
        }   //std::cout << std::endl;

        break;
    case 2: //sklepy
            //std::cout << player.getPosition().x << std::endl;
        if ((player.getPosition().x + predkosc) > 20 && (player.getPosition().x + predkosc) < RozmiarOknaX - 110) {
            player.setPosition(player.getPosition().x + predkosc, player.getPosition().y);
            playerSprite.setPosition(player.getPosition().x + predkosc, player.getPosition().y);
        }
        
        czas += deltaTime.asSeconds();
        if (predkosc != 0) {    //animacja chodzenia

            if (czas >= dlugoscKlatki) {
                czas = 0.0f;
                playerKlatki++;
                if (playerKlatki > 1) {
                    playerKlatki = 0;
                }

                playerFrameRect.left = playerKlatki * 100;
            }

            //std::cout << playerFrameRect.left << " " << playerKlatki << " " << czas << std::endl;
            playerSprite.setTextureRect(playerFrameRect);

        }
        else {
            playerFrameRect.left = 200; //lub 300 ale nie wiem które lepsze
            playerSprite.setTextureRect(playerFrameRect);
        }
        break;


    case 3: //opcje
        break;
    case 4: //wyjscie
        break;
    case 5: //zmiana sterowania
        break;
    case 6: //wybor konta
        break;
    case 7: //zaloguj sie
        break;
    case 8: //zatrzymanie (escape podczas gry)
        break;
    case 9: //dodawanie konta
        break;
    case 10: //sklep 1
        break;
    case 11: //sklep 2
        break;
    case 12: //dom/garderoba
        break;
    }
}

void Game::render()
{   //wazna kolejnosc bo tworza się warstwy
    window.clear();
    
    switch (screen)
    {
    case 0:
        window.draw(menu_backgroundSprite);

        window.draw(start_button_sprite);
        window.draw(start_button.text); // tekst

        window.draw(options_button_sprite);
        window.draw(options_button.text); // tekst

        window.draw(quit_button_sprite);
        window.draw(quit_button.text); // tekst

        break;
    case 1:      //ryby woda itp
        window.draw(tloSprite);
        window.draw(woda);
        for (const auto& falaSprite : falaSprites) { window.draw(falaSprite); }
        window.draw(drewnoSprite);
        window.draw(playerSprite);
        window.draw(wedkaSprite);
        window.draw(haczyk);
        window.draw(linka);
        for (auto& ryba : ryby)
        {
            window.draw(ryba.rybaSprite);
        }

        if (cena_ryby_napis.pomoc_popup)
        {
            cena_ryby_napis.render();
        }

        window.draw(kasa_napis.text);
        window.draw(kasa_wartosc_napis.text);

        if (ucieczka_napis.pomoc_popup)
        {
            ucieczka_napis.render();
        }

        break;
    case 2:     //sklepy
        window.draw(sklepy_backgroundSprite);
        window.draw(playerSprite);

        window.draw(kasa_napis.text);
        window.draw(kasa_wartosc_napis.text);
        break;
    case 3:     // opcje
        window.draw(options_backgroundSprite);

        window.draw(sterowanie_button_sprite);
        window.draw(sterowanie_button.text); // tekst

        window.draw(options_back_button_sprite);
        window.draw(options_back_button.text); // tekst
        break;
    case 4:     // wyjscie
        window.close();
    case 5:     // zmiana sterowania
        window.draw(sterowanie_backgroundSprite);

        window.draw(rzucanie_wedka_button_sprite);
        window.draw(rzucanie_wedka_button.text); // tekst
        window.draw(bind_rzucanie_wedka_button_sprite);
        window.draw(bind_rzucanie_wedka_button.text); // tekst

        window.draw(wciaganie_wedka_button_sprite);
        window.draw(wciaganie_wedka_button.text); // tekst
        window.draw(bind_wciaganie_wedka_button_sprite);
        window.draw(bind_wciaganie_wedka_button.text); // tekst

        window.draw(przejscie_button_sprite);
        window.draw(przejscie_button.text); // tekst
        window.draw(bind_przejscie_button_sprite);
        window.draw(bind_przejscie_button.text); // tekst

        window.draw(chodzenie_lewo_button_sprite);
        window.draw(chodzenie_lewo_button.text); // tekst
        window.draw(bind_chodzenie_lewo_button_sprite);
        window.draw(bind_chodzenie_lewo_button.text); // tekst

        window.draw(chodzenie_prawo_button_sprite);
        window.draw(chodzenie_prawo_button.text); // tekst
        window.draw(bind_chodzenie_prawo_button_sprite);
        window.draw(bind_chodzenie_prawo_button.text); // tekst

        window.draw(sterowanie_back_button_sprite);
        window.draw(sterowanie_back_button.text); // tekst
        break;
    case 6:     //wybor konta
        window.draw(sterowanie_backgroundSprite);

        window.draw(gosc_button_sprite);
        window.draw(gosc_button.text); // tekst

        window.draw(logowanie_button_sprite);
        window.draw(logowanie_button.text); // tekst

        window.draw(start_back_button_sprite);
        window.draw(start_back_button.text); // tekst
        break;
    case 7:     //logowanie
        window.draw(sterowanie_backgroundSprite);

        window.draw(nazwa_button_sprite);
        window.draw(nazwa_button.text); // tekst

        window.draw(haslo_button_sprite);
        window.draw(haslo_button.text); // tekst

        window.draw(zaloguj_sie_button_sprite);
        window.draw(zaloguj_sie_button.text); // tekst

        window.draw(zarejestruj_sie_button_sprite);
        window.draw(zarejestruj_sie_button.text); // tekst

        window.draw(logowanie_back_button_sprite);
        window.draw(logowanie_back_button.text); // tekst
        break;
    case 8:     //zatrzymanie (escape podczas gry)
        window.draw(sterowanie_backgroundSprite);

        window.draw(wznow_button_sprite);
        window.draw(wznow_button.text); // tekst

        window.draw(options_button_sprite);
        window.draw(options_button.text); // tekst

        window.draw(gra_back_button_sprite);
        window.draw(gra_back_button.text); // tekst
        break;
    case 9:     //dodawanie konta
        window.draw(sterowanie_backgroundSprite);

        window.draw(dodawanie_nazwa_button_sprite);
        window.draw(dodawanie_nazwa_button.text); // tekst

        window.draw(dodawanie_haslo_button_sprite);
        window.draw(dodawanie_haslo_button.text); // tekst

        window.draw(dodaj_button_sprite);
        window.draw(dodaj_button.text); // tekst

        window.draw(dodawanie_back_button_sprite);
        window.draw(dodawanie_back_button.text); // tekst
        break;
    case 10:        //sklep 1
        window.draw(sklep1Sprite);
        window.draw(ceny_1Sprite);
        window.draw(itemSprite);

        window.draw(kasa_napis.text);
        window.draw(kasa_wartosc_napis.text);
        break;
    case 11:        //sklep 2
        window.draw(sklep2Sprite);

        if (!czapka1_kupiona)
            window.draw(czapka1Sprite);
        if (!czapka2_kupiona)
            window.draw(czapka2Sprite);
        if (!czapka3_kupiona)
            window.draw(czapka3Sprite);
        if (!czapka4_kupiona)
            window.draw(czapka4Sprite);
        if (!czapka5_kupiona)
            window.draw(czapka5Sprite);
        if (!czapka6_kupiona)
            window.draw(czapka6Sprite);

        window.draw(ceny_2Sprite);

        window.draw(kasa_napis.text);
        window.draw(kasa_wartosc_napis.text);
        break;
    case 12:        //dom
        window.draw(domSprite);
        window.draw(dom_playerSprite);

        if(czapka1_kupiona)
            window.draw(czapka1Sprite);
        if (czapka2_kupiona)
            window.draw(czapka2Sprite);
        if (czapka3_kupiona)
            window.draw(czapka3Sprite);
        if (czapka4_kupiona)
            window.draw(czapka4Sprite);
        if (czapka5_kupiona)
            window.draw(czapka5Sprite);
        if (czapka6_kupiona)
            window.draw(czapka6Sprite);

        switch (typ_czapki)
        {
        case 0:
            if (!playerTexture.loadFromFile("obrazy/player spritesheet pelny.png"))
            {
                std::cout << "Blad wczytywania tekstury!" << std::endl;
            }
            dom_playerTexture.loadFromFile("obrazy/player_bezkasy.png");
            playerFrameRect = sf::IntRect(0, 0, 100, 100); // 2 pierwsze to x,y , 2 ostatnie to wymiary 
            dom_playerFrameRect = sf::IntRect(0, 0, 64, 100);
            dom_playerSprite.setPosition(610, 200);

            break;
        case 1:
            if (!playerTexture.loadFromFile("obrazy/player spritesheet pelny1.png"))
            {
                std::cout << "Blad wczytywania tekstury!" << std::endl;
            }
            dom_playerTexture.loadFromFile("obrazy/player_bezkasy1.png");
            break;
        case 2:
            if (!playerTexture.loadFromFile("obrazy/player spritesheet pelny2.png"))
            {
                std::cout << "Blad wczytywania tekstury!" << std::endl;
            }
            dom_playerTexture.loadFromFile("obrazy/player_bezkasy2.png");
            break;
        case 3:
            if (!playerTexture.loadFromFile("obrazy/player spritesheet pelny.png"))
            {
                std::cout << "Blad wczytywania tekstury!" << std::endl;
            }
            break;
        case 4:
            if (!playerTexture.loadFromFile("obrazy/player spritesheet pelny.png"))
            {
                std::cout << "Blad wczytywania tekstury!" << std::endl;
            }
            break;
        case 5:
            if (!playerTexture.loadFromFile("obrazy/player spritesheet pelny.png"))
            {
                std::cout << "Blad wczytywania tekstury!" << std::endl;
            }
            break;
        case 6:
            if (!playerTexture.loadFromFile("obrazy/player spritesheet pelny.png"))
            {
                std::cout << "Blad wczytywania tekstury!" << std::endl;
            }
            break;
        }
        if (typ_czapki != 0)
        {
            playerFrameRect = sf::IntRect(0, 0, 100, 108); // 2 pierwsze to x,y , 2 ostatnie to wymiary 
            dom_playerFrameRect = sf::IntRect(0, 0, 64, 107);
            dom_playerSprite.setPosition(610, 158);
        }
        dom_playerSprite.setTextureRect(dom_playerFrameRect);
        dom_playerSprite.setTexture(dom_playerTexture);
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(playerFrameRect);
        window.draw(kasa_napis.text);
        window.draw(kasa_wartosc_napis.text);
        break;
    }

    window.draw(zanikanie);
    
    window.display();
}