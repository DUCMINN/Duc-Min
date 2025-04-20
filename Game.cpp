#include "Game.h"
#include <iostream>
#include <cstdlib>

int ts = 54;
sf::Vector2i offset(48, 28);
piece grid[10][10];

piece::piece() {
    match = 0;
    alpha = 255;
}

void initGrid() {
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++) {
            grid[i][j].kind = rand() % 7;
            grid[i][j].col = j;
            grid[i][j].row = i;
            grid[i][j].x = j * ts;
            grid[i][j].y = i * ts;
            grid[i][j].match = 0;
            grid[i][j].alpha = 255;
        }
}

bool hasInitialMatch() {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            int kind = grid[i][j].kind;
            if (kind == grid[i + 1][j].kind && kind == grid[i - 1][j].kind)
                return true;
            if (kind == grid[i][j + 1].kind && kind == grid[i][j - 1].kind)
                return true;
        }
    }
    return false;
}

void swap(piece& p1, piece& p2) {
    std::swap(p1.col, p2.col);
    std::swap(p1.row, p2.row);
    std::swap(grid[p1.row][p1.col], grid[p2.row][p2.col]);
}

void startChallengeMode() {
    // Setup challenge mode with a specific time limit and move limit
    // Example: 60 seconds and 15 moves.
}

void updateChallengeMode(float time, int &totalScore, int &remainingMoves) {
    // Logic to update the score and remaining moves based on challenge mode rules.
}
