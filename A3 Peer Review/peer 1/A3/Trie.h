/**
 * @file Trie.h
 * @brief header for trie that constructs a trie out of words given by user
 * @version A3
 * @class CS3505 Spring 2022
 * 
 */
#ifndef TRIE_H
#define TRIE_H

#include "Node.h"

class Trie
{
    Node *Root;
   void getWords(Node*, vector<string> *, string); 
   
public:
    // constructors
    Trie();
    Trie(const Trie &);
    // deconstructor
    ~Trie();
    // overload
    Trie &operator=(Trie);
    // methods
    void addAWord(string);
    bool isAWord(string);
    vector<string> allWordsStartingWithPrefix(string);
};
#endif