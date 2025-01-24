#include "Game.h"

Game::Game(WordBank<string>& bank, const Player& p, Difficulty& difficulty)
    : player(p), wordBank(bank), attemptsLeft(difficulty.getAttempts()),
    wordToGuess(bank.getRandomWord()), guessedWord(wordToGuess.size(), '_') {
    wrongGuesses = new char[26];
    wrongGuessCount = 0;
}

Game::~Game() {
    delete[] wrongGuesses;
}

void Game::guessLetter(char letter) {
    bool correct = false;
    for (size_t i = 0; i < wordToGuess.size(); ++i) {
        if (wordToGuess[i] == letter) {
            guessedWord[i] = letter;
            correct = true;
        }
    }

    if (!correct) {
        for (int i = 0; i < wrongGuessCount; ++i) {
            if (wrongGuesses[i] == letter) {
                throw invalid_argument("You already guessed this letter.");
            }
        }
        wrongGuesses[wrongGuessCount++] = letter;
        --attemptsLeft;
    }
}

bool Game::isGameOver() const {
    return attemptsLeft == 0 || guessedWord == wordToGuess;
}

bool Game::isWin() const {
    return guessedWord == wordToGuess;
}

void Game::displayState() const {
    cout << "Word: " << guessedWord << "\nWrong guesses: ";
    for (int i = 0; i < wrongGuessCount; ++i) cout << wrongGuesses[i] << " ";
    cout << "\nAttempts left: " << attemptsLeft << "\n";
}

string Game::getWordToGuess() const {
    return wordToGuess;
}

void Game::saveGame(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) throw runtime_error("Unable to open file for saving.");

    outFile << player.name << '\n' << player.score << '\n'
        << wordToGuess << '\n' << guessedWord << '\n'
        << wrongGuessCount << '\n' << attemptsLeft << '\n';

    for (int i = 0; i < wrongGuessCount; ++i) {
        outFile << wrongGuesses[i] << ' ';
    }

    outFile.close();
}

void Game::loadGame(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) throw runtime_error("Unable to open file for loading.");

    inFile >> player.name >> player.score
        >> wordToGuess >> guessedWord
        >> wrongGuessCount >> attemptsLeft;

    for (int i = 0; i < wrongGuessCount; ++i) {
        inFile >> wrongGuesses[i];
    }

    inFile.close();
}
