#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

struct piece {
    int x, y, col, row, kind, match, alpha;
    piece();
};

enum class GameState {
    StartScreen,
    Playing,
    HighScoreScreen,
    GameOver,
    ChallengeMode
};

extern piece grid[10][10];
extern int ts;
extern sf::Vector2i offset;

void initGrid();
bool hasInitialMatch();
void swap(piece& p1, piece& p2);
void startChallengeMode();
void updateChallengeMode(float time, int &totalScore, int &remainingMoves);

#endif // GAME_H
