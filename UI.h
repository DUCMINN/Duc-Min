#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

void drawStartScreen(sf::RenderWindow& app, const sf::Font& font);
void drawHighScoresScreen(sf::RenderWindow& app, const sf::Font& font);
void drawGameOverScreen(sf::RenderWindow& app, const sf::Font& font, int totalScore);

#endif // UI_H
