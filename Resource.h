// Resources.h
#ifndef RESOURCES_H
#define RESOURCES_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>

class Resources {
public:
    static void load();  // Gọi một lần khi khởi tạo
    static const sf::Texture& getTexture(const std::string& name);
    static const sf::Font& getFont(const std::string& name);
    static const sf::SoundBuffer& getSound(const std::string& name);

private:
    static std::map<std::string, sf::Texture> textures;
    static std::map<std::string, sf::Font> fonts;
    static std::map<std::string, sf::SoundBuffer> sounds;
};

#endif
