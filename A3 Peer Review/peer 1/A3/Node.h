/**
 * @file Node.h
 * @brief internal node class header for trie
 * @version A3
 * @class CS3505 Spring 2022
 * 
 * 
 */
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <cstddef>
using std::string;
using std::vector;

class Node
{
    bool isWord;
    vector<Node*>* branches;
  
    public:
    Node();
    Node(const Node &);
    Node(bool);
    ~Node();

    Node &operator=(Node);
    Node *getBranch(int);
    Node *addBranch(char, bool);
    bool isLastLetter();
};
#endif