#ifndef Node_H
#define Node_H
#include <map>

class Node {
    public:
    std::map<char, Node> branches;
    bool isWord;

    Node();
};

#endif