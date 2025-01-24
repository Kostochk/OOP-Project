#ifndef UI_H
#define UI_H

#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

class UI {
public:
    static void showWelcomeMessage();
    static string getPlayerName();
    static char getUserInput();
    static void showGameResult(const Game& game);
};

#endif // UI_H
