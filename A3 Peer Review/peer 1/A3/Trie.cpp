/**
 * @file Trie.cpp
 * @brief constructs a trie out of words given by user
 * @version A3
 * @class CS3505 Spring 2022
 *
 *
 */
#include "Trie.h"
#include "Node.h"

//these are used throughout the whole program
const int ASCII_OFFSET = 97;
const int ALPHABET_SIZE = 26;

// Trie Implementations--------------------------------------------------------

/**
 * @brief Default: Construct a new Trie:: Trie object
 *
 */
Trie::Trie()
{
    Root = new Node();
}

/**
 * @brief Copy Constructor a new Trie:: Trie object
 *
 * @param other the node to copy
 */
Trie::Trie(const Trie &other)
{
    Root = new Node(*other.Root);
}

/**
 * @brief Destroy the Trie:: Trie object
 *
 */
Trie::~Trie()
{
    delete Root;
}

/**
 * @brief rule of three operator overload of the = to swap values of a Trie
 *
 * @param other the tree to swap with
 * @return Trie& a reference to the tree you implemented the operator on
 */
Trie &Trie::operator=(Trie other)
{
    Root = new Node(*other.Root);
    return *this;
}

/**
 * @brief adds a word to the binary trie starting at the head
 *
 * @param word the input word you're adding
 */
void Trie::addAWord(string word)
{
    Node * currNode = Root;
    for (int i = 0; i < word.size(); i++)
    { // if this is the last letter, mark true, else false
        if(i == word.size() - 1){
           currNode = currNode->addBranch(word.at(i), true);
        } else{
           currNode = currNode->addBranch(word.at(i), false); 
        }
    }
}

/**
 * @brief checks if the input word is a word and returns true or false
 *
 * @param word the word to look for in the trie
 * @return true if the word exists in the trie
 * @return false if the word does not exist in the trie
 */
bool Trie::isAWord(string word)
{
    Node *currNode = Root;
    int branchIndex;
    // if you passed an empty string
    if (word.size() == 0)
    {
        return false;
    }
    for (int i = 0; i < word.length(); i++)
    {
        // spaces aren't letters
        if (word.at(i) == ' ')
        {
            return false;
        }
        
        branchIndex = int(word.at(i)) - ASCII_OFFSET;
        //if the branch for this letter is null she isn't a word babez
        if (currNode->getBranch(branchIndex) == nullptr)
        {
            return false;
        }
        //else she's a word so make a copy and move it
        if(i <= word.size()-1)
        {
        currNode = currNode->getBranch(branchIndex);
        }
    }
    //when you're done currNode should be the last letter of the input word
    return currNode->isLastLetter();
}

/**
 * @brief input a prefix, output all words with prefix, including the prefix if necessary
 *
 * @param word the given prefix
 * @return vector<string> a vector of all the words starting with given prefix
 */
vector<string> Trie::allWordsStartingWithPrefix(string word)
{
    vector<string> words;
    Node *currNode = Root;
    int branchIndex;

    // if you passed an empty string
    if (word.size() == 0)
    {
        return words;
    }

    //Go letter by letter
    for (int i = 0; i < word.length(); i++)
    {
        // spaces aren't letters
        if (word.at(i) == ' ')
        {
            continue;
        }

        branchIndex = int(word.at(i)) - ASCII_OFFSET;

        if (currNode->getBranch(branchIndex) == nullptr)
        { //this means that the given word won't be a prefix so just return empty
            return words;
        }
        else
        {
            currNode = currNode->getBranch(branchIndex);
        }
    }
    // currNode is now the prefix node, now populate words
    getWords(currNode, &words, word);
    return words;
}

/**
 * @brief helper recursive method that populates the words array
 *
 * @param node the current node you're going through
 * @param words a pointer to the array of words you're adding to
 * @param prefix the prefix you're adding on to
 */
void Trie::getWords(Node *node, vector<string> *words, string prefix)
{
    char letter;
    //base case
    if(node == nullptr){
        return;
    } else //add word to list
    if(node->isLastLetter()){
        words->push_back(prefix);
    }
    //go letter by letter
    for(int i = 0; i < ALPHABET_SIZE; i++){
        //convert int to char
        letter = ASCII_OFFSET + i;
        //recurse
        if(node->getBranch(i) != nullptr){
            getWords(node->getBranch(i),words, prefix + letter);
        } 
    }

}

// Node class implementations-----------------------------------------------

// constructors
/**
 * @brief Construct a new Trie:: Node:: Node object
 *
 */
Node::Node()
{
    isWord = false;
    branches = new vector<Node *>(ALPHABET_SIZE);
    // turn all branches into null pointers
    for (auto it = branches->begin(); it != branches->end(); it++)
    {
        *it = nullptr;
    }
}

/**
 * @brief Construct a new Trie:: Node:: Node object using an existing object
 * aka copy constructor but do not create a copy
 *
 * @param other the other node that must be copied
 */
Node::Node(const Node &other)
{
    isWord = other.isWord;
    branches = new vector<Node *>(ALPHABET_SIZE);
    //copy node pointer by node pointer
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {   
        if ((*other.branches)[i] != nullptr)
        {   //dereference and copy node
            (*branches)[i] = new Node(*(*other.branches)[i]);
        } else{
            //can't dereference a nullptr so just set to null right off the bat
            (*branches)[i] = nullptr;
        }
    }
}

/**
 * @brief Construct a new Node:: Node object but use a letter and a "word" boolean indicator to help construct it easier
 *
 * @param initLetter the character that you want to be the letter in the word
 * @param initWord the bool saying whether or not this is the end of a word
 */
Node::Node(bool initWord)
{
    isWord = initWord;
    branches = new vector<Node *>(ALPHABET_SIZE);
    // turn all branches into null pointers
    for (auto it = branches->begin(); it != branches->end(); it++)
    {
        *it = nullptr;
    }
}

// destructor

/**
 * @brief Destroy the Node::Node object branches pointers
 *
 */
Node::~Node()
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        delete (*branches)[i]; // no memory leaks allowed in this trie
    }
    delete branches;
}

// rule of threes baby

/**
 * @brief Overload the = operator such that you can use rule of 3 to swap all the values
 *
 * @param other the node to copy
 * @return Node& the reference to the original object such that n1 = n2 returns a modified n1
 */
Node &Node::operator=(Node other)
{
    std::swap(isWord, other.isWord);
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        delete (*branches)[i]; // no memory leaks allowed in this trie
        (*branches)[i]= nullptr;
    }
    std::swap(branches, other.branches);
    return *this;
}

// methods

/**
 * @brief if the node is the last letter of a word?
 *
 * @return true if it is the last letter of a word
 * @return false if not the last letter of a word
 */
bool Node::isLastLetter()
{
    return isWord;
}

/**
 * @brief adds a branch to the current node using the provided letter and "is a word" bool and if its already provided doesn't add a duplicate
 *
 * @param letter the letter you want to make the node of
 * @param word if the node is the last letter of a word then its true
 * @return Node* the node that you just added to the branches array or the one that already exists in the array
 */
Node *Node::addBranch(char letter, bool _isWord)
{
    int branchIndex = int(letter) - ASCII_OFFSET;
    // if the branch exists, update its word status
    if ((*branches)[branchIndex] != nullptr)
    {
        (*branches)[branchIndex]->isWord = _isWord;
    } else{
        //else make a new node
        (*branches)[branchIndex] =new Node(_isWord);
    }
    //return the node pointer at specified branch (helpful for recursion and iteration)
    return (*branches)[branchIndex];
}

/**
 * @brief return the node at a specified index
 * 
 * @param index the index at which you need to retieve the node pointer
 * @return Node* the node pointer at specified index
 */
Node *Node::getBranch(int index)
{
    return (*branches)[index];
}
