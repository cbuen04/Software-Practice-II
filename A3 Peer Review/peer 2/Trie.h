/*
* CS 3505 Assignment 3:
*   The head file for the Trie class.  
*
* Author: Wenlin Li
*/
#include <string>
#include <vector>


class Trie
{
    /*
    *   Node class for Trie
    */
    class Node
    {
    public:
        Node *children[26];
        bool isWord;

        // default constructor
        Node()
        {   
           isWord = false;
           for (unsigned int i = 0; i < 26; i++)
            {
               children[i] = nullptr;
            }
        }
        // '=' operator.
        Node &operator=(Node other)
        {
            for (unsigned int i = 0; i < 26; i++)
            {
                std::swap(children[i], other.children[i]);
            }
            std::swap(isWord, other.isWord);
            return *this;
        }
       
       //copy constructor
        Node(const Node &other)
        {
            for (unsigned int i = 0; i < 26; i++)
            {
               children[i] = nullptr;
            }

            for (unsigned int i = 0; i < 26; i++)
            {
                if (other.children[i])
                    this->children[i] = new Node(*(other.children[i]));
            }
            this->isWord = other.isWord;
        }

        // destructor
        ~Node()
        {
            for (unsigned int i = 0; i < 26; i++)
            {
                delete this->children[i];
            }
        }
    };

public:
    Node* root = new Node();
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    /**
     * Helper method for allWordsStartingWithPrefix to look for all the children node push into vector
     */
    void recursion(std::string &, Node *, std::vector<std::string> &, std::string);
    


public:
    Trie();
    Trie(const Trie &);
    ~Trie();
    Trie &operator=(Trie);
    /**
     * The word passed into the method should be added to the Trie object.
     */
    void addAWord(std::string);

    /**
     * If the word is found in the Trie, the method should return true, otherwise return false.
     */
    bool isAWord(std::string);
    /**
     * Returns a vector<std::string> that contains all the words in the Trie that start with the passed in argument prefix string. 
     */
    std::vector<std::string> allWordsStartingWithPrefix(std::string);
};