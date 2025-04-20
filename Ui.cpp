#include "UI.h"

void renderUI(sf::RenderWindow& app, sf::Sprite& hud, sf::Text& timeText, sf::Text& scoreText) {
    app.draw(hud);
    app.draw(timeText);
    app.draw(scoreText);
}
