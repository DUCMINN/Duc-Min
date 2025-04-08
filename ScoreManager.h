#pragma once
#include <vector>
#include <string>

std::vector<int> loadHighScores(const std::string& filename);
void saveHighScore(const std::string& filename, int score);
