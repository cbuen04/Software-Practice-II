#include<vector>
#include<string>
#include "Node-1.h"
#ifndef Trie_H
#define Trie_H

/*  Author: Adrianna Jones
    CS3505
    A4: Refactoring and Testing */

class Trie {

    Node rootNode;

    public:
        Trie();

        void addAWord(std::string word);

        bool isAWord(std::string word);

        std::vector<std::string> allWordsStartingWithPrefix(std::string);

        void allWordsStartingPrefixHelper(Node* currNode, std::string word, std::vector<std::string>& vect);
};

#endif