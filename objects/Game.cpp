#include "Game.h"

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
}

void Game::initPlayer()       //do ustawienia pozycji i sprite
{

    if (!playerTexture.loadFromFile("obrazy/player3.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    playerSprite.setTexture(playerTexture);
    player.setPosition(75.0f, 475.0f);
    playerSprite.setPosition(75.0f, 475.0f);
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
}


void Game::initWoda() {
    woda.setSize(sf::Vector2f(10000.0f, 10000.0f));
    woda.setFillColor(sf::Color(0, 0, 128, 128));
    woda.setPosition(player.getPosition().x + 123, powierzchniaWody + 50);
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
        falaSprite.setColor(sf::Color(0, 0, 80, 128));
        falaSprites.push_back(falaSprite);
    }

}

void Game::initHaczyk()       //koniec w�dki (haczyk)
{
    haczyk.setRadius(10.0f);
    haczyk.setFillColor(sf::Color::Red);
    angle = 0.0f;
    promien = 100.0f;
    isKeyPressed = false;
    //pozycja(do zmiany)
    float xInit = player.getPosition().x + ConstHaczykInitX;
    float yInit = player.getPosition().y - ConstHaczykInitY;
    haczyk.setPosition(xInit, yInit);
}
void Game::initZanikanie(){
    zanikanie.setSize(sf::Vector2f(RozmiarOknaX, RozmiarOknaY));
    zanikanie.setFillColor(sf::Color(0, 0, 0, 0));
}
void Game::przejscie(sf::Time deltaTime)
{
    
    static float alpha = 0; // Aktualna przezroczystość 
    const float fadeSpeed = 100.0f; // Szybkość przejścia (zmiana przezroczystości na sekundę) 
        
    alpha += fadeSpeed * deltaTime.asSeconds(); 
    if (alpha > 256) {
        alpha = 0;
        czyPrzejscie = false;

        if (LokalizacjaRyby == true) {
            screen = 2;
            LokalizacjaRyby = false;
        }
        else {
            screen = 1;
            LokalizacjaRyby = true;
        }
    }
    
    
    zanikanie.setFillColor(sf::Color(0, 0, 0, static_cast<sf::Uint8>(alpha)));
}

void Game::run() {
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)//zamknij okno
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && LokalizacjaRyby==true)//ci�gni�cie  
            {
                if (rzut == false && zarzucanie == false) {
                    promien -= 3;
                    if (haczyk.getPosition().x < player.getPosition().x + 50) //bo inaczej nie da sie wci�ga� gdy koliduje z brzegiem
                    {

                        //float y = player.getPosition().y + player.getSize().y / 2 + promien * sin(angle);
                        //opcja wyzej jest lepsza ale pobugowana
                        float y = haczyk.getPosition().y - 5;
                        haczyk.setPosition(haczyk.getPosition().x, y);
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E && zarzucanie == false && rzut == false && czyTrzyma && LokalizacjaRyby == true) {//zarzu� w�dke (bind do zmiany)
                zarzucanie = true;
                rzut = true;
                czyTrzyma = false;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q&&czyPrzejscie==false) {
                
                    czyPrzejscie = true;
            }
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D) && czyPrzejscie == false && LokalizacjaRyby == false) {
                int predkosc = ConstPlayerSpeed;
                if (event.key.code == sf::Keyboard::A) {
                    predkosc *= -1;
                }
                if(player.getPosition().x + predkosc > 50 && player.getPosition().x + predkosc<RozmiarOknaX-50){
                playerSprite.setPosition(sf::Vector2f(player.getPosition().x + predkosc, player.getPosition().y));
                }
            }
        }
        update(sf::seconds(1.f / 60.f)); render();
    }
}

void Game::update(sf::Time deltaTime)
{

    klatka++;

    if (czyPrzejscie) {
        przejscie(deltaTime);
    }
    switch (screen)
    {
    case 0:
        if (start_button.clicked())
            screen = 1;
        break;
    case 1:{
        float predkoscKatowa = predkoscLiniowa / promien;
        // Aktualizacja pozycji haczyka
        angle += predkoscKatowa;
        if (angle > 2 * M_PI)
            angle -= 2 * M_PI;

        if (rzut == false && czyTrzyma == false) {    //spadanie haczyka
            if (haczyk.getPosition().x > player.getPosition().x + 50) {
                float x = player.getPosition().x + player.getSize().x / 2 + promien * cos(angle);
                float y = player.getPosition().y + player.getSize().y / 2 + promien * sin(angle);
                haczyk.setPosition(x, y);
            }
        }

        if (haczyk.getPosition().y <= powierzchniaWody && rzut == true) {  //zarzucenie w�dki
            if (zarzucanie == true) {  //animacja zamachu do ty�u w�dk�
                if (haczyk.getPosition().x > player.getPosition().x)
                {
                    float x = haczyk.getPosition().x - 2;
                    float y = haczyk.getPosition().y - 0.65;
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
                speedY -= 0.05;
                haczyk.setPosition(x, y);
            }
            czyTrzyma = false;
            promien = sqrt((haczyk.getPosition().x - player.getPosition().x) * (haczyk.getPosition().x - player.getPosition().x) + (haczyk.getPosition().y - player.getPosition().y) * (haczyk.getPosition().y - player.getPosition().y));
            angle = atan2(haczyk.getPosition().y - player.getPosition().y, haczyk.getPosition().x - player.getPosition().x);
        }
        else {
            rzut = false;
        }
        if (haczyk.getPosition().x < player.getPosition().x + 60 && haczyk.getPosition().y >player.getPosition().y && haczyk.getPosition().y <= player.getPosition().y + 80 && zarzucanie == false) {  //�apanie haczyka
            czyTrzyma = true;
            haczyk.setPosition(player.getPosition().x + ConstHaczykInitX, player.getPosition().y - ConstHaczykInitY);
            speedY = ConstSpeedY;
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
                linka.setPosition(deltaX+1, deltaY+7);
                dx = haczyk.getPosition().x - (deltaX+1);
                dy = haczyk.getPosition().y - (deltaY + 7);
                length = std::sqrt(dx * dx + dy * dy);
                linka.setSize(sf::Vector2f(length, 3.0f));
            }
            linka.setRotation(std::atan2(dy, dx) * 180 / M_PI);
        }



        if (klatka % 10 == 0 && ryby.size() <= 25 && rand() % 3 == 0)   // spawnuje ryby co 10 klatek, maksymalnie 25 ryb na raz
        {
            int x1 = rand() % 30 + 1650;    // losowe wspolrzedne ryb (takie, ze nie wychodza poza wode)
            int y1 = rand() % 270 + 600;

            int r = (rand() % 255 + 0);     // losowe kolory ryb
            int g = (rand() % 255 + 0);
            int b = (rand() % 255 + 0);
            ryby.push_back(Ryba(x1, y1, sf::Color(r, g, b, 255), 2, rybaTexture1, rybaTexture2, rybaTexture3));
        }

        for (auto& ryba : ryby) {
            ryba.update();
        }

        
        if (klatka > 10000) { //bo inaczej wyjdzie poza zakres int 
            klatka = 0;
        }
        //std::cout << screen <<" " <<LokalizacjaRyby<< std::endl;
        break; }
    case 2: //sklepy

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
        start_button.render();
        window.draw(start_button.text);
        break;
    case 1:     //ryby woda itp
        window.draw(woda);
        for (const auto& falaSprite : falaSprites) { window.draw(falaSprite); }
        window.draw(playerSprite);
        window.draw(wedkaSprite);
        window.draw(haczyk);
        window.draw(linka);
        for (auto& ryba : ryby) {
            window.draw(ryba.rybaSprite);
        }
        break;
    case 2:     //sklepy
        window.draw(playerSprite);
        break;
    }
    window.draw(zanikanie);
    window.display();
}