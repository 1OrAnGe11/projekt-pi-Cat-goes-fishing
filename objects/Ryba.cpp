#include "Ryba.h"

Ryba::Ryba(const std::string& textureFile, int frameWidth, int frameHeight, int frameCount, float frameDuration) {
    if (!texture.loadFromFile(textureFile))
    {
        std::cerr << "Blad wczytywania tekstury ryby!" << std::endl;
    }
    sprite.setTexture(texture);
    frameRect = sf::IntRect(0, 0, frameWidth, frameHeight);
    sprite.setTextureRect(frameRect); this->frameCount = frameCount; this->frameDuration = frameDuration;
    currentFrame = 0;
    elapsedTime = 0.0f;
}