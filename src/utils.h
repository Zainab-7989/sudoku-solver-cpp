#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

class Utils {
public:
    static void printWelcomeMessage();
    static bool isDigitsOnly(const std::string& str);
    static std::vector<std::vector<int>> generateRandomPuzzle();
    static int getDifficultyLevel();
    static void clearScreen();
};

#endif