#pragma once
void runGame();


// Game.cpp
#include "Game.h"
#include "Piece.h"
#include "Resources.h"
#include "ScoreManager.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
using namespace sf;

int ts = 54;
Vector2i offset(48, 28);
piece grid[10][10];

enum class GameState {
    StartScreen,
    Playing,
    HighScoreScreen,
    GameOver
};

void swap(piece& p1, piece& p2) {
    std::swap(p1.col, p2.col);
    std::swap(p1.row, p2.row);
    std::swap(grid[p1.row][p1.col], grid[p2.row][p2.col]);
}

void runGame() {
    srand(time(0));
    RenderWindow app(VideoMode(720, 480), "Game Kim Cuong", Style::Close);
    app.setVerticalSyncEnabled(true);
    app.setFramerateLimit(120);

    Texture backgroundTex, gemTex, hudTex, startTex;
    if (!loadTexture(backgroundTex, "assets/background.png") ||
        !loadTexture(gemTex, "assets/gems.png") ||
        !loadTexture(hudTex, "assets/hud.png") ||
        !loadTexture(startTex, "assets/start.jpg")) {
        return;
    }

    Sprite background(backgroundTex), gems(gemTex), hud(hudTex), startBackground(startTex);
    hud.setPosition(520, 0);
    hud.setColor(Color(10, 10, 10, 150));

    Font font;
    if (!loadFont(font, "C:/Windows/Fonts/Verdana.ttf")) return;

    Text timeText("", font, 24), scoreText("", font, 24);
    timeText.setFillColor(Color::White);
    timeText.setPosition(550, 15);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(550, 55);

    Text titleText("GAME KIM CUONG", font, 40);
    titleText.setFillColor(Color::Yellow);
    titleText.setPosition(180, 100);

    Text startBtn("Start", font, 36);
    startBtn.setFillColor(Color::Green);
    startBtn.setPosition(270, 250);

    Text highScoreBtn("High Score", font, 32);
    highScoreBtn.setFillColor(Color::Blue);
    highScoreBtn.setPosition(260, 320);

    GameState gameState = GameState::StartScreen;
    int timeLimit = 90;
    int totalScore = 0;
    Clock clock;

    auto initGrid = []() {
        for (int i = 1; i <= 8; i++)
            for (int j = 1; j <= 8; j++) {
                grid[i][j].kind = rand() % 7;
                grid[i][j].col = j;
                grid[i][j].row = i;
                grid[i][j].x = j * ts;
                grid[i][j].y = i * ts;
            }
    };

    initGrid();

    int x0, y0, x, y, click = 0;
    Vector2i pos;
    bool isSwap = false, isMoving = false;

    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed) app.close();

            if (gameState == GameState::StartScreen) {
                if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(app);
                    if (startBtn.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y)) {
                        gameState = GameState::Playing;
                        clock.restart();
                        totalScore = 0;
                        initGrid();
                        click = 0;
                        isSwap = false;
                        isMoving = false;

                        for (int i = 1; i <= 8; i++)
                            for (int j = 1; j <= 8; j++) {
                                grid[i][j].match = 0;
                                grid[i][j].alpha = 255;
                            }
                    }
                    else if (highScoreBtn.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y)) {
                        gameState = GameState::HighScoreScreen;
                    }
                }
            }

            if (gameState == GameState::Playing && e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left) {
                if (!isSwap && !isMoving && (timeLimit - clock.getElapsedTime().asSeconds() > 0)) {
                    click++;
                    pos = Mouse::getPosition(app) - offset;
                }
            }

            if (gameState == GameState::HighScoreScreen || gameState == GameState::GameOver) {
                if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left) {
                    gameState = GameState::StartScreen;
                }
            }
        }

        app.clear();

        if (gameState == GameState::StartScreen) {
            app.draw(startBackground);
            app.draw(titleText);
            app.draw(startBtn);
            app.draw(highScoreBtn);
        }
        else if (gameState == GameState::HighScoreScreen) {
            app.draw(startBackground);
            Text hsTitle("HIGH SCORES", font, 40);
            hsTitle.setFillColor(Color::Yellow);
            hsTitle.setPosition(200, 60);
            app.draw(hsTitle);

            std::vector<int> scores = loadHighScores("assets/highscores.txt");
            for (size_t i = 0; i < std::min(scores.size(), size_t(5)); i++) {
                Text scoreText(std::to_string(i + 1) + ". " + std::to_string(scores[i]), font, 28);
                scoreText.setFillColor(Color::White);
                scoreText.setPosition(250, 130 + i * 40);
                app.draw(scoreText);
            }

            Text backText("Click anywhere to go back", font, 20);
            backText.setFillColor(Color::Cyan);
            backText.setPosition(200, 400);
            app.draw(backText);
        }
        else if (gameState == GameState::Playing) {
            // ... phần Playing giữ nguyên như bạn đã viết
        }
        else if (gameState == GameState::GameOver) {
            app.draw(background);
            Text endText("HET GIO!", font, 48);
            endText.setFillColor(Color::Red);
            endText.setStyle(Text::Bold);
            endText.setPosition(250, 200);
            app.draw(endText);

            Text retryText("Click to return", font, 24);
            retryText.setFillColor(Color::White);
            retryText.setPosition(260, 280);
            app.draw(retryText);
        }

        app.display();
    }
}
