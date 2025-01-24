#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
public:
    explicit Player(const string& playerName);
    string name;
    int score;
};

#endif // PLAYER_H
