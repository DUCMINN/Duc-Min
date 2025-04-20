#include "Game.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Game::Game() {
    ts = 54;
    offset = Vector2i(48, 28);
    gameState = GameState::StartScreen;
    timeLimit = 90;
    totalScore = 0;
    if (!music.openFromFile("D:/nhacgame.ogg.ogg")) {
        std::cerr << "Không thể mở file nhạc.\n";
        exit(-1);
    }
    music.setLoop(true);
    music.setVolume(50);
    music.play();
    
    // Tải ảnh
    if (!backgroundTex.loadFromFile("D:/bg game.jpg") ||
        !gemTex.loadFromFile("D:/game/Data/Texture/gems.png") ||
        !hudTex.loadFromFile("D:/hud.png") ||
        !startTex.loadFromFile("D:/start1.jpg")) {
        std::cerr << "Không thể tải ảnh.\n";
        exit(-1);
    }
    
    background.setTexture(backgroundTex);
    gems.setTexture(gemTex);
    hud.setTexture(hudTex);
    startBackground.setTexture(startTex);
    hud.setPosition(520, 0);
    hud.setColor(Color(10, 10, 10, 150));

    if (!font.loadFromFile("C:/Windows/Fonts/Verdana.ttf")) {
        std::cerr << "Không thể tải font.\n";
        exit(-1);
    }

    timeText.setFont(font);
    timeText.setCharacterSize(24);
    timeText.setFillColor(Color::White);
    timeText.setPosition(550, 15);
    
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(550, 55);
    
    titleText.setFont(font);
    titleText.setString("GAME KIM CUONG");
    titleText.setCharacterSize(40);
    titleText.setFillColor(Color::Yellow);
    titleText.setPosition(180, 100);
    
    startBtn.setFont(font);
    startBtn.setString("Start");
    startBtn.setCharacterSize(36);
    startBtn.setFillColor(Color::Green);
    startBtn.setPosition(270, 250);
    
    highScoreBtn.setFont(font);
    highScoreBtn.setString("High Score");
    highScoreBtn.setCharacterSize(32);
    highScoreBtn.setFillColor(Color::Blue);
    highScoreBtn.setPosition(260, 320);
}

void Game::initGrid() {
    for (int i = 1; i <= 8; i++) {
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
}

bool Game::hasInitialMatch() {
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

void Game::saveHighScore(const std::string& filename, int score) {
    std::ofstream out(filename, std::ios::app);
    if (out) out << score << "\n";
}

std::vector<int> Game::loadHighScores(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> scores;
    int score;
    while (file >> score) scores.push_back(score);
    std::sort(scores.rbegin(), scores.rend());
    return scores;
}

// Các chức năng khác như update, render và handleEvents sẽ được viết ở đây...
