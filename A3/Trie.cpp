#include "Trie.h"
using namespace std;

/**
 * @brief this is a trie class. This trie takes in words from a client and
 * adds them to the structure, the trie can also be queried to determine if the word
 * exists or not, as well as find all the words associated with a given prefix
 * @author Charly Bueno
 * @version 02/11/2022
 * CS-3505
 */
// A destructor, copy constructor, and an assignment= operator using the approaches
// from the Rule-Of-Three slides. As an implementation note: if you have a wrapper Trie
// class with a helper Node class, then a default destructor, copy, and assignment may be
// fine for the Trie class, but the Node class likely needs the Rule-Of-Three implementations.

// A default constructor.
Trie::Trie()
{
    for (int i = 0; i < 26; i++)
    {
        letters[i] = nullptr;
    }
}

/**
 * @brief Destroy the Trie:: Trie object
 *
 */
Trie::~Trie()
{
    for (int i = 0; i < 26; i++)
    {
        delete letters[i];
    }
}

/**
 * @brief Construct a new Trie:: Trie object
 *
 * @param other - trie object to construct from
 */
Trie::Trie(const Trie &other)
{
    for (int i = 0; i < 26; i++)
    {
        letters[i] = nullptr;
        if (other.letters[i])
        {
            letters[i] = new Trie(*(other.letters[i]));
        }
    }
    isWord = other.isWord;
}

/**
 * @brief overriding assignment operator which changes
 * the current trie for the other trie
 *
 * @param other
 * @return Trie&
 */
Trie &Trie::operator=(Trie &other)
{
    // for (int i = 0; i < 26; i++)
    // {
    //     swap(letters[i], other.letters[i]);
    //     swap(letters[i]->isWord, other.letters[i]->isWord);
    // }
    swap(isWord, other.isWord);
    swap(letters, other.letters);
    // swap is word boolean
    return *this;
}

/**
 * @brief
 * A method addAWord that accepts a std::string and returns void. The word passed into the method
 * should be added to the Trie object. Duplicate adds should not change the Trie. You may assume
 * that the word is only made up of lower-case characters from a-z.
 *
 * @param word
 */
void Trie::addAWord(std::string word)
{

    int index = word[0] - 'a';
    if (!(letters[index]))
    {
        letters[index] = new Trie();
    }
    if (word.length() == 1) // changed this from 0
    {
        letters[index]->isWord = true;
        return;
    }
    letters[index]->addAWord(word.substr(1));
}

/**
 * @brief
 * A method isAWord that accepts a std::string and returns bool. The argument is a string assumed
 * to be made up of characters 'a'-'z'. If the word is found in the Trie, the method should return
 * true, otherwise return false.  A Trie should report that an empty string is not in the Trie.
 *
 * @param word
 * @return true
 * @return false
 */
bool Trie::isAWord(std::string word)
{
    int index = word[0] - 'a';
    if ((letters[index]) && word.length() == 1)
    {
        return letters[index]->isWord;
    }

    if (!letters[index])
    {
        return false;
    }

    return letters[index]->isAWord(word.substr(1));
}

/**
 * @brief helper method that determines if a given string exists in the trie
 * with out it necessarily being a defined word
 *
 * @param word
 * @return true
 * @return false
 */
bool Trie::stringExistsInTrie(string word)
{

    int index = word[0] - 'a';

    if ((letters[index]) && word.length() == 1)
    {
        return true;
    }

    if (!letters[index] || word.length() == 0)
    {
        return false;
    }

    return letters[index]->stringExistsInTrie(word.substr(1));
}

/**
 * @brief A method allWordsStartingWithPrefix that accepts a std::string and returns a vector<std::string>
 * that contains all the words in the Trie that start with the passed in argument prefix string.
 * If the prefix is a word, that should be included. An empty prefix should return all words in the Trie.
 *
 * @param word
 * @return vector<string>
 */
vector<string> Trie::allWordsStartingWithPrefix(string word)
{

    vector<string> list;

    if (!stringExistsInTrie(word))
    {
        return list;
    }

    // case where string is empty, every defined word will be returned
    if (word.length() == 0)
    {
        collectWordsWithPrefix(word, list);
    }
    else
    {
        Trie *start = prefixStartingPoint(word);

        // if prefix is a word, added to list.
        if (isAWord(word))
        {
            list.push_back(word);
        }

        start->collectWordsWithPrefix(word, list);
    }

    return list;
}

/**
 * @brief helper method that traverses the trie from the prefix
 * and returns the point where the recursion should begin.
 *
 * @param word - prefix
 * @return Trie*
 */
Trie *Trie::prefixStartingPoint(string word)
{
    int index = word[0] - 'a';

    if (word.length() == 1)
    {
        return letters[index];
    }

    return letters[index]->prefixStartingPoint(word.substr(1));
}

/**
 * @brief helper recursive method that finds all the words defined in the tru=ie
 * at a specific point.
 *
 * @param prefix
 * @param list - list of words found in trie
 */
void Trie::collectWordsWithPrefix(string prefix, vector<string> &list)
{
    // append prefix to string of words found along recursive step

    // call recursive step on all letters in the trie using for loop

    for (int i = 0; i < 26; i++)
    {
        if (letters[i])
        {
            char insert = i + 'a';
            if (letters[i]->isWord)
            {
                list.push_back(prefix + insert);
            }
            letters[i]->collectWordsWithPrefix(prefix + insert, list);
        }
    }
}