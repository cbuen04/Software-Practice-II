/*
    Vista Marston and Emily Best
    A4: Refactoring and GoogleTests
    Description: This function is used as an interface for the Trie class. 
*/

#ifndef TRIE_H
#define TRIE_H
#include <string>
#include <vector>
#include <map>

class Trie
{
private:
    std::map<char, Trie> charBranches;
    bool isWord;
    void grabRemainingWords(std::string, std::vector<std::string>&);
    void addWordRecursive(std::string);
public:
    Trie(); 
    void addAWord(std::string);
    bool isAWord(std::string);
    std::vector<std::string> allWordsStartingWithPrefix(std::string);
};
#endif