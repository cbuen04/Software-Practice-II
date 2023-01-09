/*
* CS 3505 Assignment 3: 
*   Practice the C++ by implementing by design the trie.
* Trie.cpp Description:
*     The Trie class should have a root node, 
*        where nodes have internal storage for branches of the Trie 
*       and a flag determining whether or not that node represents the end of a valid word.
*
* Author: Wenlin Li
*/
#include <vector>
#include <string>
#include "Trie.h"

Trie::~Trie()
{
    delete root;
}

Trie::Trie(const Trie &other)
{
    root = nullptr;
    root = new Node(*(other.root));
}
Trie::Trie()
{
}
Trie &Trie::operator=(Trie other)
{
    std::swap(root, other.root);
    return *this;
}
void Trie::addAWord(std::string word)
{
    Node* current = root;
	for (int  i = 0; i < word.length(); i++)
	{       
		if (current->children[(int)(word[i] - (int)'a')] == nullptr)
			current->children[(int)(word[i] - (int)'a')] = new Node();

		current = current->children[(int)(word[i] - (int)'a')];
	}
	current->isWord = true;
    
    current = nullptr;
}

bool Trie::isAWord(std::string word)
{
	Node* current = root;
	for (int i = 0; i < word.length(); i++)
	{
		if (current->children[(int)(word[i] - 'a')] == nullptr)
			return false;
		current = current->children[(int)(word[i] - 'a')];
	}

	return current->isWord;
    current = nullptr;
}

std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string prefix)
{

    std::vector<std::string> wordVector;
    Node* current = root;
    for(int i = 0; i < prefix.length(); i++)
	{   
		if (current->children[(int)(prefix[i] - 'a')] == nullptr)
			{
            current = nullptr;
            break;
            }
		current = current->children[(int)(prefix[i] - 'a')];
	}

    if (!current)
    {
        return wordVector;
    }
    if (current->isWord)
    {
        wordVector.push_back(prefix);
    }

    for (unsigned int i = 0; i < alphabet.length(); i++)
    {   
        std::string wordString = "";
        std::string newWordString = "";
        Node *childrenNode = current->children[i];
        if (childrenNode)
        {
        recursion(prefix, childrenNode, wordVector, wordString + alphabet[i]);           
        }
    }
    return wordVector;
}

void Trie::recursion(std::string &prefix, Node *childrenNode, std::vector<std::string> &wordVector, std::string wordString)
{
    if (childrenNode->isWord)
    {
        wordVector.push_back(prefix + wordString);
    }

    for (unsigned int i = 0; i < alphabet.length(); i++)
    {
        Node *newChildern = childrenNode->children[i];
        if (newChildern)
        {
            recursion(prefix, newChildern, wordVector, wordString + alphabet[i]);
        }
    }
}


