#include <iostream>
#include "Trie-1.h"
#include "Node-1.h"

/*  
    CS3505
    A4: Refactoring and Testing 
    This class contains methods that build and search through a trie using a map*/

Trie::Trie() {
}

/*This method loops through each letter of the word passed in and adds each letter to the trie creating a word*/
void Trie::addAWord(std::string word) {
    Node* currNode = &rootNode;
    for(unsigned int i = 0; i < word.length(); i++) {
        //The key we want to check for in the map
        char key = word[i];
        if(currNode->branches.count(key)==0) {
            Node node;
            currNode->branches[key] = node;
            currNode = &currNode->branches[key];
        }
        else {
            currNode = &currNode->branches[key];
        }
    }
    currNode->isWord = true;
}

/*This method returns true if the word is found in the trie. It loops through the word as it goes down the trie*/
bool Trie::isAWord(std::string word) {
    Node* currNode = &rootNode;
    for(unsigned int i = 0; i < word.length(); i++) {
        char key = word[i];
        int sizeOfWord = word.length()-1;
        if(currNode->branches.count(key)==0) {
            return false;
        }
        //Returns true if we're at the end of the word rather than somewhere in the middle
        else if(currNode->branches[key].isWord && (i == sizeOfWord)) {
            return true;
        }
        currNode = &currNode->branches[key];
    }
    return false;
}

/*This method recurses down the trie looking for all words that start with the given prefix*/
std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string prefix) {
    std::vector<std::string> vectorOfWords;
    Node* currNode = &rootNode;
    std::string word = prefix;
    //This loops takes care of checking the prefix before recursion starts
    for(unsigned int i = 0; i < word.length(); i++) {
        char key = word[i];
        if(currNode->branches.count(key)==0) 
            return vectorOfWords;
        else {
            currNode = &currNode->branches[key];
            if(currNode->isWord)
                vectorOfWords.push_back(word);   
        }
    }
    allWordsStartingPrefixHelper(currNode, word, vectorOfWords);
    return vectorOfWords;
}

//Helper method to finish recursing down the trie after the prefix is completed
void Trie::allWordsStartingPrefixHelper(Node* currNode, std::string word, std::vector<std::string>& wordsWithPrefix) {
    std::map<char, Node>::iterator iter;
    for(iter = currNode->branches.begin(); iter != currNode->branches.end(); iter++) {
        char key = iter->first;
        //Used to update the word and still keep original word passed in
        std::string currentWord = word;
        //Used to traverse down while still keeping the correct current node
        Node* currNodeTemp = currNode;
        if(currNode->branches.count(key)==1) {
            currNodeTemp = &currNode->branches[key];
            //key holds the letter we need to update our word with
            currentWord += key;
            if(currNodeTemp->isWord) 
                wordsWithPrefix.push_back(currentWord);
            allWordsStartingPrefixHelper(currNodeTemp, currentWord, wordsWithPrefix);
        }
    }
}

