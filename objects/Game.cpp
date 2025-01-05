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
    initDrewno();

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
    promien = 100.0f;
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
        std::cout << "duypa" << alpha << std::endl;
    }
    alpha += fadeSpeed * deltaTime.asSeconds();
    if (alpha > 256) {
        alpha = 0;
        czyPrzejscie = false;
        if (LokalizacjaRyby == true) {
            player.setPosition(RozmiarOknaX - 150.0f, 475.0f);
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
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && (screen == 1 || screen == 2))//zatrzymanie gry
            {
                screen_gra_pomoc = screen;
                screen = 8;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && LokalizacjaRyby == true)//ci�gni�cie  
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

            if ( (screen == 1 || screen == 2) && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q && czyPrzejscie == false) {

                czyPrzejscie = true;
            }
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D) && czyPrzejscie == false && LokalizacjaRyby == false) {
                if (player.getPosition().x + predkosc > 10 && player.getPosition().x + predkosc < RozmiarOknaX - 10) {
                    predkosc = ConstPlayerSpeed;
                }
                if (event.key.code == sf::Keyboard::A) {
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
            if (event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)) {
                predkosc = 0;
            }
            switch (screen)
            {
            case 0:     //menu
                if (start_button.clicked(event))
                    screen = 6;
                if (options_button.clicked(event))
                {
                    screen_options_pomoc = 0;
                    screen = 3;
                }
                if (quit_button.clicked(event))
                    screen = 4;
                break;
            case 1:     //gra
                break;
            case 3:     //opcje
                if (sterowanie_button.clicked(event))
                    screen = 5;
                if (options_back_button.clicked(event))
                    screen = screen_options_pomoc;
                break;
            case 4:     //wyjscie
                break;
            case 5:     //zmiana sterowania
                bind_rzucanie = (sf::Keyboard::Key)bind_rzucanie_wedka_button.key_bind(event);
                std::cout << (sf::Keyboard::Key)bind_rzucanie_wedka_button.key_bind(event) << std::endl;
                if (sterowanie_back_button.clicked(event))
                    screen = 3;
                break;
            case 6:     //wybor konta
                if (gosc_button.clicked(event))
                    screen = screen_gra_pomoc;
                if (logowanie_button.clicked(event))
                    screen = 7;
                if (start_back_button.clicked(event))
                    screen = 0;
            case 7:     //logowanie do konta
                nazwa_button.wpisywanie(event);
                haslo_button.wpisywanie(event);
                if (zaloguj_sie_button.clicked(event))
                    std::cout << "Jeszce nie dziala lol" << std::endl;
                if (logowanie_back_button.clicked(event))
                    screen = 6;
                break;
            case 8:     //zatrzymanie (escape podczas gry)
                czyPrzejscie = false;
                zanikanie.setFillColor(sf::Color(0, 0, 0, 0));
                if (wznow_button.clicked(event))
                {
                    screen = screen_gra_pomoc;
                    pomoc_przejscie = true;
                }
                if (options_button.clicked(event))
                {
                    screen_options_pomoc = 8;
                    screen = 3;
                }
                if (gra_back_button.clicked(event))
                {
                    pomoc_przejscie = true;
                    screen = 0;
                }
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

    //char_bind_rzucanie = wpisywanie_bind_rzucanie_wedka.wypisz()

    float predkoscKatowa = predkoscLiniowa / promien;

    if (czyPrzejscie) {
        przejscie(deltaTime);
    }
    switch (screen)
    {
    case 0:
        break;
    case 1:
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
                linka.setPosition(deltaX + 1, deltaY + 7);
                dx = haczyk.getPosition().x - (deltaX + 1);
                dy = haczyk.getPosition().y - (deltaY + 7);
                length = std::sqrt(dx * dx + dy * dy);
                linka.setSize(sf::Vector2f(length, 3.0f));
            }
            linka.setRotation(std::atan2(dy, dx) * 180 / M_PI);
        }



        if (klatka % 10 == 0 && ryby.size() <= 25 && rand() % 3 == 0)   // spawnuje ryby co 10 klatek, maksymalnie 25 ryb na raz
        {
            int x1 = rand() % 30 + 1650;    // losowe wspolrzedne ryb (takie, ze nie wychodza poza wode)
            int y1 = rand() % 230 + 610;

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
        break;
    case 2: //sklepy
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

            std::cout << playerFrameRect.left << " " << playerKlatki << " " << czas << std::endl;
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
        options_button.render();
        window.draw(options_button.text);
        quit_button.render();
        window.draw(quit_button.text);
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
        for (auto& ryba : ryby) {
            window.draw(ryba.rybaSprite);
        }
        break;
    case 2:     //sklepy
        window.draw(sklepy_backgroundSprite);
        window.draw(playerSprite);
        break;
    case 3:     // opcje
        window.draw(options_backgroundSprite);
        sterowanie_button.render();
        window.draw(sterowanie_button.text);
        options_back_button.render();
        window.draw(options_back_button.text);
        break;
    case 4:     // wyjscie
        window.close();
    case 5:     // zmiana sterowania
        window.draw(sterowanie_backgroundSprite);
        rzucanie_wedka_button.render();
        window.draw(rzucanie_wedka_button.text);
        bind_rzucanie_wedka_button.render();
        window.draw(bind_rzucanie_wedka_button.text);
        sterowanie_back_button.render();
        window.draw(sterowanie_back_button.text);
        break;
    case 6:     //wybor konta
        window.draw(sterowanie_backgroundSprite);
        gosc_button.render();
        window.draw(gosc_button.text);
        logowanie_button.render();
        window.draw(logowanie_button.text);
        start_back_button.render();
        window.draw(start_back_button.text);
        break;
    case 7:     //logowanie
        window.draw(sterowanie_backgroundSprite);
        nazwa_button.render();
        window.draw(nazwa_button.text);
        haslo_button.render();
        window.draw(haslo_button.text);
        zaloguj_sie_button.render();
        window.draw(zaloguj_sie_button.text);
        logowanie_back_button.render();
        window.draw(logowanie_back_button.text);
        break;
    case 8:     //zatrzymanie (escape podczas gry)
        window.draw(sterowanie_backgroundSprite);
        wznow_button.render();
        window.draw(wznow_button.text);
        options_button.render();
        window.draw(options_button.text);
        gra_back_button.render();
        window.draw(gra_back_button.text);
        break;
    }
    window.draw(zanikanie);
    
    window.display();
}