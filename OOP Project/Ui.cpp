#include "UI.h"

void UI::showWelcomeMessage() {
    cout << "Welcome to Hangman! Try to guess the word before you run out of attempts.\n";
}

string UI::getPlayerName() {
    cout << "Enter your name: ";
    string name;
    cin >> name;
    return name;
}

char UI::getUserInput() {
    cout << "Enter a letter: ";
    char letter;
    cin >> letter;
    return tolower(letter);
}

void UI::showGameResult(const Game& game) {
    if (game.isWin()) {
        cout << "\nCongratulations! You guessed the word: " << game.getWordToGuess() << "\n";
    }
    else {
        cout << "\nGame Over! The word was: " << game.getWordToGuess() << "\n";
    }
}
