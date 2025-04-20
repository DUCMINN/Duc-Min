#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using namespace sf;

struct piece {
  struct piece {
    int x, y, col, row, kind, match, alpha;
    piece() : match(0), alpha(255) {}
};

class Game {
private:
    piece grid[10][10]; // <-- để trong class
}
public:
    Game();
    void initGrid();
    bool hasInitialMatch();
    void update(float deltaTime);
    void render(RenderWindow& app);
    void handleEvents(Event& e, RenderWindow& app);
    void swap(piece& p1, piece& p2);
    void saveHighScore(const std::string& filename, int score);
    std::vector<int> loadHighScores(const std::string& filename);

private:
    int ts;
    Vector2i offset;
    int timeLimit;
    int totalScore;
    Clock clock;
    sf::Music music;
    sf::Texture backgroundTex, gemTex, hudTex, startTex;
    sf::Sprite background, gems, hud, startBackground;
    sf::Font font;
    sf::Text timeText, scoreText, titleText, startBtn, highScoreBtn;
    enum class GameState {
        StartScreen,
        Playing,
        HighScoreScreen,
        GameOver
    };
    GameState gameState;
};

#endif
