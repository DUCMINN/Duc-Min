#include "ScoreManager.h"
#include <fstream>
#include <algorithm>

std::vector<int> loadHighScores(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> scores;
    int score;
    while (file >> score) scores.push_back(score);
    std::sort(scores.rbegin(), scores.rend());
    return scores;
}

void saveHighScore(const std::string& filename, int score) {
    std::ofstream out(filename, std::ios::app);
    if (out) out << score << "\n";
}
