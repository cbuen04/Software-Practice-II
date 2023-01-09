/*
    Vista Marston and Emily Best
    A4: Refactoring and GoogleTests
    Description: This function is used to represent the Trie Data
        Structure implementing the necessary Trie Interface.
*/

#include "Trie-1.h"
#include <string>
#include <vector>
#include <iostream>
#include <utility>
using std::vector;
using std::string;
using std::map;
using std::pair;

/**
 * @brief Construct a new Trie:: Trie object
 */
Trie::Trie() {
    isWord = false;
}

/**
 * @brief Adds a word to the Trie Object
 * 
 * @param word The word that needs to be added
 */
void Trie::addAWord(string word){
    if(word == "")
        return;

    Trie* temp = this;

    for(char& letter : word) {
        if(!temp->charBranches.count(letter)){
            Trie newNode;
            temp->charBranches[letter] = newNode;
        }
        temp = &(temp->charBranches[letter]);
    }
    temp->isWord = true;
}

/**
 * @brief Checks to see if the word is within the Trie Data Structure
 * 
 * @param word The word being checked
 * @return true If the word is in the Trie Data Structure
 * @return false If the word is not in the Trie Data Structure
 */
bool Trie::isAWord(string word){
    Trie* temp = this;

    for(char& letter : word) {
        if(!temp->charBranches.count(letter))
            return false;
        temp = &(temp->charBranches[letter]);
    }

    return temp->isWord;    
}

/**
 * @brief Grabs all of the words starting with the given prefix inclusive
 * 
 * @param prefix The starting of words being looked for
 * @return vector<string> All the words that start with the prefix
 */
vector<string> Trie::allWordsStartingWithPrefix(string prefix){
    vector<string> allWordsWithPrefix;
    Trie* temp = this; 

    // Check if prefix is in the trie
    for(char& letter : prefix) {
        if(temp->charBranches.count(letter))
            temp = &(temp->charBranches[letter]);
        else
            return allWordsWithPrefix;
    }

    temp->grabRemainingWords(prefix, allWordsWithPrefix);  
    return allWordsWithPrefix;
}

/**
 * @brief A helper recursive method that recursively finds all of the words 
 * from a given starting point.
 * 
 * @param currentWord The current word under consideration
 * @param allWordsWithPrefix The reference to the main list of words
 */
void Trie::grabRemainingWords(string currentWord, vector<string>& allWordsWithPrefix) {
    if(isWord)
        allWordsWithPrefix.push_back(currentWord);

    for(auto &pair : charBranches)
        pair.second.grabRemainingWords(currentWord + pair.first, allWordsWithPrefix);
}
