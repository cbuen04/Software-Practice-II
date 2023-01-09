/**
 * @file Trie.h
 * @author Charly Bueno
 * @brief header file for Trie.cpp
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TRIE_H
#define TRIE_H
#include <string>
#include <vector>
#include <iostream>
class Trie
{

private:
    Trie *letters[26];
    bool isWord = false;

public:
    Trie();

    ~Trie();

    Trie(const Trie &other);

    Trie &operator=(Trie& other);

    void addAWord(std::string word);

    bool isAWord(std::string word);

    bool stringExistsInTrie(std::string word);

    std::vector<std::string> allWordsStartingWithPrefix(std::string word);

    Trie *prefixStartingPoint(std::string word);

    void collectWordsWithPrefix(std::string prefix, std::vector<std::string> &list);
};
#endif