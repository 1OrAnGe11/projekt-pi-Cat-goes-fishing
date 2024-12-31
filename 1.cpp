#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846
#define ConstSpeedY 4
#define ConstSpeedX 3
#define ConstHaczykInitX 80 //pozycja pocz�tkowa haczyka (gdzie trzyma)
#define ConstHaczykInitY 30
//class ryby  //jeszcze nie dzia�a
//{
//public:
//    float x;
//    float y;
//    sf::Sprite sprite; 
//    sf::Texture texture;
//    sf::IntRect frameRect; int frameCount; int currentFrame; float frameDuration; float elapsedTime; 
//    ryby(const std::string& textureFile, int frameWidth, int frameHeight, int frameCount, float frameDuration) {
//        if (!texture.loadFromFile(textureFile))
//        {
//            std::cerr << "Blad wczytywania tekstury ryby!" << std::endl;
//        }
//        sprite.setTexture(texture);
//        frameRect = sf::IntRect(0, 0, frameWidth, frameHeight);
//        sprite.setTextureRect(frameRect); this->frameCount = frameCount; this->frameDuration = frameDuration;
//        currentFrame = 0;
//        elapsedTime = 0.0f;
//        
//        }
//    };

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
        //
    float angle;
    float promien;
    bool isKeyPressed;
    bool rzut = false;  //�eby podczas zarzucania w�dki nie spada� haczyk i nie da�o si� wci�ga�
    bool czyTrzyma = true;
    bool zarzucanie = false;    //animacja zamachu do ty�u w�dk�
    float speedY = ConstSpeedY;
    float powierzchniaWody = 525.0; //pozycja powierzchni wody (Y)
    int klatka = 0;     //do sprawdzania kt�ra klatka jest aktualnie wy�wietlana(operacje takie jak co 120 klatek zr�b cos)
    float predkoscLiniowa = 0.03; //predkosc haczyka
    
    void initWindow()   //rozmiar okna itp
    {
        window.create(sf::VideoMode(1600, 900), "Zmien nazwe");
    }

    void initPlayer()       //do ustawienia pozycji i sprite
    {
        
        if (!playerTexture.loadFromFile("obrazy/player3.png"))
        {
            std::cout << "Blad wczytywania tekstury!" << std::endl;
        }
        playerSprite.setTexture(playerTexture);
        player.setPosition(75.0f, 475.0f);
        playerSprite.setPosition(75.0f, 475.0f);
    }
    void initW�dka() {
        if (!wedkaTexture.loadFromFile("obrazy/player3.png"))
        {
            std::cout << "Blad wczytywania tekstury!" << std::endl;
        }
        wedkaSprite.setTexture(wedkaTexture);
    }
    void initRyby() {
        
    }
    void initWoda() {
        woda.setSize(sf::Vector2f(10000.0f, 10000.0f));
        woda.setFillColor(sf::Color(0 , 0 ,128, 128));
        woda.setPosition(player.getPosition().x + 123, powierzchniaWody+50);
    }

    void initFala(float x, float y) {
        if (!falaTexture.loadFromFile("obrazy/FALAspritesheet.png"))
        { std::cout << "Blad wczytywania tekstury!" << std::endl; 
        } 
        falaSprite.setTexture(falaTexture);
        falaFrameRect = sf::IntRect(0, 0, 600, 100); // 2 pierwsze to x,y , 2 ostatnie to wymiary 
        falaSprite.setTextureRect(falaFrameRect);
        falaSprite.setPosition(x, y);
        falaKlatki = 2; // Ustaw ca�kowit� liczb� klatek 
        dlugoscKlatki = 30.2f; // Czas trwania jednej klatki w sekundach (jednak chyba nie w sekundach)
        klatka = 0; 
        czas = 0.0f;
        for (int i = 0; i < 5; ++i) {
            sf::Sprite falaSprite; falaSprite.setTexture(falaTexture); 
            falaSprite.setTextureRect(falaFrameRect); 
            falaSprite.setPosition(75.0f + i * 550.0f, 475.0f); 
            falaSprite.setColor(sf::Color(0, 0, 80, 128));
            falaSprites.push_back(falaSprite); }
        
    }

    void initHaczyk()       //koniec w�dki (haczyk)
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

public:
    Game()
    {   initWoda();
        initFala(woda.getPosition().x , powierzchniaWody-50);
        initFala(woda.getPosition().x+600, powierzchniaWody - 50);
        initFala(woda.getPosition().x + 1200, powierzchniaWody - 50);
        initWindow();
        initPlayer();
        initHaczyk();
        
        linka.setFillColor(sf::Color(128, 128, 128)); // Szary kolor 
        linka.setSize(sf::Vector2f(5.0f, 5.0f)); // Pogrubienie linii (szeroko��)
        
    }

    void run() { 
        while (window.isOpen()) 
        { 
        sf::Event event; 
        while (window.pollEvent(event)) 
        { 
            if (event.type == sf::Event::Closed)//zamknij okno
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)//ci�gni�cie  
            { 
                if(rzut == false && zarzucanie==false){
                promien-=3; 
                if (haczyk.getPosition().x < player.getPosition().x + 50) //bo inaczej nie da sie wci�ga� gdy koliduje z brzegiem
                {
                    
                    //float y = player.getPosition().y + player.getSize().y / 2 + promien * sin(angle);
                    //opcja wy�ej jest lepsza ale pobugowana
                    float y = haczyk.getPosition().y - 5;
                    haczyk.setPosition(haczyk.getPosition().x, y);
                } 
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E && zarzucanie==false &&rzut==false && czyTrzyma) {//zarzu� w�dke (bind do zmiany)
                zarzucanie = true;
                rzut = true;
                czyTrzyma = false;
            }
        } 
         update(sf::seconds(1.f / 60.f)); render();
        } 
    }

    void update(sf::Time deltaTime)
    {   

        klatka++;
        
        float predkoscKatowa = predkoscLiniowa/promien;

        // Aktualizacja pozycji haczyka
            angle += predkoscKatowa;
        if (angle > 2 * M_PI)
            angle -= 2 * M_PI;

        if(rzut==false&&czyTrzyma==false){    //spadanie
        if(klatka%10==0 && haczyk.getPosition().x > player.getPosition().x + 50) {
        float x = player.getPosition().x + player.getSize().x / 2 + promien * cos(angle);
        float y = player.getPosition().y + player.getSize().y / 2 + promien * sin(angle);
        haczyk.setPosition(x, y); 
        }
        }
        //
        if (haczyk.getPosition().y <= powierzchniaWody && rzut == true) {  //zarzucenie w�dki
            if (zarzucanie == true ) {  //animacja zamachu do ty�u w�dk�
                if(klatka % 200 == 0){
                    if(haczyk.getPosition().x > player.getPosition().x)
                    {
                         float x = haczyk.getPosition().x - 4;
                         float y = haczyk.getPosition().y-0.3;
                         haczyk.setPosition(x,y);
                    }
                    else {
                    zarzucanie = false;
                    
                    }
                }
            }    
            else if(klatka%200==0 && zarzucanie ==false)//rzut
            {  
            float x = haczyk.getPosition().x+ConstSpeedX;
            float y = haczyk.getPosition().y-speedY;
            speedY -= 0.1;
            haczyk.setPosition(x, y);
            }
            czyTrzyma = false;
            promien = sqrt((haczyk.getPosition().x - player.getPosition().x) * (haczyk.getPosition().x - player.getPosition().x) + (haczyk.getPosition().y - player.getPosition().y) * (haczyk.getPosition().y - player.getPosition().y));
            angle = atan2(haczyk.getPosition().y - player.getPosition().y, haczyk.getPosition().x - player.getPosition().x);
        }
        else {
            rzut = false;
        }
        if (klatka > 10000) { //bo inaczej wyjdzie poza zakres int 
            klatka = 0;
        }
        if (haczyk.getPosition().x < player.getPosition().x + 60  && haczyk.getPosition().y >player.getPosition().y && haczyk.getPosition().y <= player.getPosition().y + 80 && zarzucanie == false) {  //�apanie haczyka
            czyTrzyma = true;
            haczyk.setPosition(player.getPosition().x + ConstHaczykInitX, player.getPosition().y - ConstHaczykInitY);
            speedY = ConstSpeedY;
        }


        // Aktualizacja linki 

        if(zarzucanie == false){
        float dx = haczyk.getPosition().x - (player.getPosition().x + ConstHaczykInitX); 
        float dy = haczyk.getPosition().y - (player.getPosition().y - ConstHaczykInitY); 
        float length = std::sqrt(dx * dx + dy * dy); 
        linka.setSize(sf::Vector2f(length, 3.0f)); // 3.0f to grubo�� linki 
        linka.setPosition(player.getPosition().x + ConstHaczykInitX, player.getPosition().y - ConstHaczykInitY); 
        linka.setRotation(std::atan2(dy, dx) * 180 / M_PI); }
    
    
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

        //animacja w�dki
        /*if (zarzucanie == true) {
            float dx = ;
            float dy = haczyk.getPosition().y - (player.getPosition().y - ConstHaczykInitY);
            linka.setRotation(std::atan2(dy, dx) * 180 / M_PI);
        }*/

    }

    void render()
    {
        window.clear();
        window.draw(woda);
        for (const auto& falaSprite : falaSprites) { window.draw(falaSprite); }
        window.draw(playerSprite);
        window.draw(haczyk);
        window.draw(linka);
        
        window.display();
    }
};

int main()
{
    Game game;
    game.run();
    return 0;
}
