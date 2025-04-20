// Resources.cpp
#include "Resources.h"

std::map<std::string, sf::Texture> Resources::textures;
std::map<std::string, sf::Font> Resources::fonts;
std::map<std::string, sf::SoundBuffer> Resources::sounds;

void Resources::load() {
    sf::Texture tex;
    if (tex.loadFromFile("D:/bg game.jpg"))
        textures["tiles"] = tex;

    sf::Font font;
    if (font.loadFromFile("C:/Windows/Fonts/Verdana.ttf"))
        fonts["arial"] = font;

    sf::SoundBuffer buffer;
    if (buffer.loadFromFile("D:/nhacgame.ogg.ogg"))
        sounds["music"] = buffer;

    // Bạn có thể thêm các tài nguyên khác ở đây
}

const sf::Texture& Resources::getTexture(const std::string& name) {
    return textures.at(name);
}

const sf::Font& Resources::getFont(const std::string& name) {
    return fonts.at(name);
}

const sf::SoundBuffer& Resources::getSound(const std::string& name) {
    return sounds.at(name);
}
