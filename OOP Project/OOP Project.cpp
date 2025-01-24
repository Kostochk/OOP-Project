#include <iostream>
#include "Player.h"
#include "WordBank.h"
#include "Difficulty.h"
#include "HardDifficulty.h"
#include "Game.h"
#include "UI.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ukrainian");
    srand(time(0));

    // Инициализация банков слов
    string englishWords[] = { "programming", "hangman", "object", "inheritance", "polymorphism" };
    string russianWords[] = { "программирование", "виселица", "объект", "наследование", "полиморфизм" };
    string ukrainianWords[] = { "програмування", "вішалка", "об'єкт", "успадкування", "поліморфізм" };

    // Выбор языка
    cout << "Choose language (1 - English, 2 - Russian, 3 - Ukrainian): ";
    int languageChoice;
    cin >> languageChoice;

    WordBank<string>* wordBank;
    switch (languageChoice) {
    case 1:
        wordBank = new WordBank<string>(englishWords, 5);
        break;
    case 2:
        wordBank = new WordBank<string>(russianWords, 5);
        break;
    case 3:
        wordBank = new WordBank<string>(ukrainianWords, 5);
        break;
    default:
        cout << "Invalid choice. Defaulting to English.\n";
        wordBank = new WordBank<string>(englishWords, 5);
    }

    // Выбор уровня сложности
    Difficulty* difficulty;
    cout << "Choose difficulty (1 - Easy, 2 - Hard): ";
    int difficultyChoice;
    cin >> difficultyChoice;

    if (difficultyChoice == 2) {
        difficulty = new HardDifficulty();
    }
    else {
        difficulty = new Difficulty();
    }

    // Инициализация игры
    UI::showWelcomeMessage();
    string playerName = UI::getPlayerName();
    Player player(playerName);
    Game game(*wordBank, player, *difficulty);

    // Загрузка сохраненной игры (если необходимо)
    cout << "Do you want to load a saved game? (y/n): ";
    char loadChoice;
    cin >> loadChoice;

    if (loadChoice == 'y') {
        try {
            game.loadGame("saved_game.txt");
            cout << "Game loaded successfully.\n";
        }
        catch (const exception& e) {
            cout << "Error loading game: " << e.what() << "\nStarting a new game.\n";
        }
    }

    // Игровой цикл
    while (!game.isGameOver()) {
        game.displayState();

        try {
            char guess = UI::getUserInput();
            game.guessLetter(guess);

            // Сохранение игры после каждого шага
            game.saveGame("saved_game.txt");
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }
    }

    game.displayState();
    UI::showGameResult(game);

    delete wordBank;
    delete difficulty;
    return 0;
}
