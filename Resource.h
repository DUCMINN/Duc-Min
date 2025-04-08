#pragma once
#include <SFML/Graphics.hpp>
#include <string>

bool loadTexture(sf::Texture& texture, const std::string& filepath);
bool loadFont(sf::Font& font, const std::string& filepath);
