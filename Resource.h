#ifndef RESOURCES_H
#define RESOURCES_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

bool loadTexture(sf::Texture& texture, const std::string& filepath);
bool loadFont(sf::Font& font, const std::string& filepath);
std::vector<int> loadHighScores(const std::string& filename);
void saveHighScore(const std::string& filename, int score);

#endif // RESOURCES_H
