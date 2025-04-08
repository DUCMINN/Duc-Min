#include "Resources.h"
#include <iostream>

bool loadTexture(sf::Texture& texture, const std::string& filepath) {
    if (!texture.loadFromFile(filepath)) {
        std::cerr << "Khong the tai anh: " << filepath << "\n";
        return false;
    }
    return true;
}

bool loadFont(sf::Font& font, const std::string& filepath) {
    if (!font.loadFromFile(filepath)) {
        std::cerr << "Khong the tai font: " << filepath << "\n";
        return false;
    }
    return true;
}
