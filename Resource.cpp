#include "Resources.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool loadTexture(sf::Texture& texture, const std::string& filepath) {
    if (!texture.loadFromFile(filepath)) {
        std::cerr << "Không thể tải ảnh: " << filepath << "\n";
        return false;
    }
    return true;
}

bool loadFont(sf::Font& font, const std::string& filepath) {
    if (!font.loadFromFile(filepath)) {
        std::cerr << "Không thể tải font: " << filepath << "\n";
        return false;
    }
    return true;
}

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
