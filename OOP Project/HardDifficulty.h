#ifndef HARD_DIFFICULTY_H
#define HARD_DIFFICULTY_H

#include "Difficulty.h"

class HardDifficulty : public Difficulty {
public:
    int getAttempts() const override;
};

#endif // HARD_DIFFICULTY_H
