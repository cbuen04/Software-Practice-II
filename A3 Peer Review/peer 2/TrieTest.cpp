/*
* TrieTest.cpp: 
* Test the main methods in Trie class and Rule-of-Three of Trie.
*   
*
* Author: Wenlin Li
*/
#include <iostream>
#include <fstream>
#include <iterator>
#include "Trie.h"

int main(int argc, char **argv)
{   
    std::ifstream wordFile;
    std::ifstream queryFile;
    if (argc != 3)
    {
        std::cout << "Invaild input" << std::endl;
        std::cin.ignore();
        std::cin.get();
        exit(0);
    }
    
    wordFile.open(argv[1]);   

    if (!wordFile)
    {
        std::cout << "Can not find the file." << std::endl;
        std::cin.ignore();
        std::cin.get();
        exit(0);
    }


    queryFile.open(argv[2]);
    if (!queryFile)
    {
        std::cout << "Can not find the file." << std::endl;
        std::cin.ignore();
        std::cin.get();
        exit(0);
    }
    Trie *testTrie = new Trie();
    std::string testWord;

    while(wordFile >> testWord)
    {
        testTrie->addAWord(testWord);
    }
    wordFile.close();

    while(queryFile >> testWord)
    {
      if(testTrie->isAWord(testWord))
      {
      std::cout << testWord << " is found" << std::endl;
      }
      else{
      std::cout << testWord << " is not found, did you mean:" << std::endl;
      std::vector<std::string> v = testTrie->allWordsStartingWithPrefix(testWord);
      if(v.size())
      {
        for(unsigned int i = 0; i<v.size(); i++){
          std::cout << v.at(i) << std::endl;
        }
      }
      else
        {
          std::cout << "is not found" << std::endl;
        }
        }
    }
    queryFile.close();

    //Test for Rule of Three
    Trie trie;
    Trie other (trie);
    other = trie;

    return 0;
}

