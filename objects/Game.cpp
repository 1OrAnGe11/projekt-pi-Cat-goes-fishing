#include "Game.h"

Game::Game()
{
    srand(time(NULL));
    initWoda();
    initFala(woda.getPosition().x, powierzchniaWody - 50);
    initFala(woda.getPosition().x + 600, powierzchniaWody - 50);
    initFala(woda.getPosition().x + 1200, powierzchniaWody - 50);
    initWindow();
    initPlayer();
    initHaczyk();
    initRyby();

    linka.setFillColor(sf::Color(128, 128, 128)); // Szary kolor 
    linka.setSize(sf::Vector2f(5.0f, 5.0f)); // Pogrubienie linii (szerokoœæ)

}

void Game::initWindow()   //rozmiar okna itp
{
    window.create(sf::VideoMode(1600, 900), "Zmien nazwe");
    window.setFramerateLimit(60);
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

void Game::initWêdka() {
    if (!wedkaTexture.loadFromFile("obrazy/player3.png"))
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
    }
    wedkaSprite.setTexture(wedkaTexture);
}

void Game::initRyby() {

    ryby = {};
    if (!rybaTexture.loadFromFile("obrazy/ryba.png", sf::IntRect(0, 0, 515, 256)))
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
    falaKlatki = 2; // Ustaw ca³kowit¹ liczbê klatek 
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

void Game::initHaczyk()       //koniec wêdki (haczyk)
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

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)//ci¹gniêcie  
            {
                if (rzut == false && zarzucanie == false) {
                    promien -= 3;
                    if (haczyk.getPosition().x < player.getPosition().x + 50) //bo inaczej nie da sie wci¹gaæ gdy koliduje z brzegiem
                    {

                        //float y = player.getPosition().y + player.getSize().y / 2 + promien * sin(angle);
                        //opcja wy¿ej jest lepsza ale pobugowana
                        float y = haczyk.getPosition().y - 5;
                        haczyk.setPosition(haczyk.getPosition().x, y);
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E && zarzucanie == false && rzut == false && czyTrzyma) {//zarzuæ wêdke (bind do zmiany)
                zarzucanie = true;
                rzut = true;
                czyTrzyma = false;
            }

        }
        update(sf::seconds(1.f / 60.f)); render();
    }
}

void Game::update(sf::Time deltaTime)
{

    klatka++;

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
    
    if (haczyk.getPosition().y <= powierzchniaWody && rzut == true) {  //zarzucenie wêdki
        if (zarzucanie == true) {  //animacja zamachu do ty³u wêdk¹
            if (haczyk.getPosition().x > player.getPosition().x)
            {
                float x = haczyk.getPosition().x - 2;
                float y = haczyk.getPosition().y - 0.15;
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
    } else {
        rzut = false;
    }
    if (haczyk.getPosition().x < player.getPosition().x + 60 && haczyk.getPosition().y >player.getPosition().y && haczyk.getPosition().y <= player.getPosition().y + 80 && zarzucanie == false) {  //³apanie haczyka
        czyTrzyma = true;
        haczyk.setPosition(player.getPosition().x + ConstHaczykInitX, player.getPosition().y - ConstHaczykInitY);
        speedY = ConstSpeedY;
    }


    // Aktualizacja linki 

    if (zarzucanie == false) {
        float dx = haczyk.getPosition().x - (player.getPosition().x + ConstHaczykInitX);
        float dy = haczyk.getPosition().y - (player.getPosition().y - ConstHaczykInitY);
        float length = std::sqrt(dx * dx + dy * dy);
        linka.setSize(sf::Vector2f(length, 3.0f)); // 3.0f to gruboœæ linki 
        linka.setPosition(player.getPosition().x + ConstHaczykInitX, player.getPosition().y - ConstHaczykInitY);
        linka.setRotation(std::atan2(dy, dx) * 180 / M_PI);
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

    //animacja wêdki
    /*if (zarzucanie == true) {
        float dx = ;
        float dy = haczyk.getPosition().y - (player.getPosition().y - ConstHaczykInitY);
        linka.setRotation(std::atan2(dy, dx) * 180 / M_PI);
    }*/

    if (klatka % 10 == 0 && ryby.size() <= 25 && rand() % 3 == 0)   // spawnuje ryby co 10 klatek, maksymalnie 25 ryb na raz
    {
        int x1 = rand() % 30 + 1650;    // losowe wspolrzedne ryb (takie, ze nie wychodza poza wode)
        int y1 = rand() % 270 + 600;

        int r = (rand() % 255 + 0);     // losowe kolory ryb
        int g = (rand() % 255 + 0);
        int b = (rand() % 255 + 0);
        ryby.push_back(Ryba(x1, y1, sf::Color(r, g, b, 255), 2, rybaTexture));
    }

    for (auto& ryba : ryby) {
        ryba.update();
    }

    if (klatka > 10000) { //bo inaczej wyjdzie poza zakres int 
        klatka = 0;
    }
}

void Game::render()
{
    window.clear();
    window.draw(woda);
    for (const auto& falaSprite : falaSprites) { window.draw(falaSprite); }
    window.draw(playerSprite);
    window.draw(haczyk);
    window.draw(linka);
    for (auto& ryba : ryby) {
        window.draw(ryba.rybaSprite);
    }

    window.display();
}
