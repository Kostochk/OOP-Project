#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "WordBank.h"
#include "Difficulty.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Game {
    Player player;
    string wordToGuess;
    string guessedWord;
    char* wrongGuesses;
    int wrongGuessCount;
    int attemptsLeft;
    WordBank<string>& wordBank;

public:
    explicit Game(WordBank<string>& bank, const Player& p, Difficulty& difficulty);
    ~Game();
    void guessLetter(char letter);
    bool isGameOver() const;
    bool isWin() const;
    void displayState() const;
    string getWordToGuess() const;
    void saveGame(const string& filename) const;
    void loadGame(const string& filename);
};

#endif // GAME_H
