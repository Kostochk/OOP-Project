#ifndef WORDBANK_H
#define WORDBANK_H


#include <stdexcept>

using namespace std;

template<typename T>
class WordBank {
    T* words;
    size_t size;

public:
    explicit WordBank(T* wordList, size_t wordCount);
    T getRandomWord() const;
};

template<typename T>
WordBank<T>::WordBank(T* wordList, size_t wordCount) : words(wordList), size(wordCount) {}

template<typename T>
T WordBank<T>::getRandomWord() const {
    if (size == 0) throw runtime_error("Word bank is empty.");
    return words[rand() % size];
}

#endif // WORDBANK_H
