// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include "Trie.h"
using namespace std;
/**
 * @brief this is a helper method that reads a file and loads the words into the Trie
 *
 * @param filename
 * @param trie
 */
void createTrie(string filename, Trie &trie)
{

    string line;

    ifstream myfile(filename);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            trie.addAWord(line);
            // cout << line << '\n';
        }
        myfile.close();
    }

    else
        cout << "Unable to open file";
}

/**
 * @brief this is a helper method that reads from a text file and
 * queries the trie and checks if a word exists or not.
 *
 * @param filename
 * @param trie
 */
void trieQueries(string filename, Trie &trie)
{

    string line;

    ifstream myfile(filename);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            // cout<< line << endl;
            if (trie.isAWord(line))
            {
                // cout << line << " is found" << endl;
            }
            else
            {
                vector<string> list = trie.allWordsStartingWithPrefix(line);
                if (list.empty())
                {
                    cout << "no alternatives found" << endl;
                }
                else
                {
                    cout << line << " was not found did you mean:";
                    for (string word : list)
                    {
                        cout << "\n"
                             << "   " << word;
                    }
                    cout << endl;
                }
            }
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";
}

int main(int argc, char **argv)
{
    string line;

    char *wordFile = argv[1];
    char *queryFile = argv[2];

    Trie t;
    createTrie(wordFile, t);
    trieQueries(queryFile, t);

    // test copy constructor
    Trie copyTest;
    copyTest.addAWord("test");
    copyTest.addAWord("copy");
    copyTest.addAWord("constructor");

    Trie copy(copyTest);

    if (copy.isAWord("test"))
    {
        if (copy.isAWord("copy"))
        {
            if (copy.isAWord("constructor"))
            {

                cout << "successfully copied" << endl;
            }
        }
    }

    // test assignment construtor
    Trie trie;
    Trie overRiddenTrie;

    trie.addAWord("overridden");
    overRiddenTrie.addAWord("exists");

    overRiddenTrie = trie;

    if (trie.isAWord("overridden"))
    {
        cout << "trie is still the same" << endl;
    }

    if (overRiddenTrie.isAWord("overridden") && !(overRiddenTrie.isAWord("exists")))
    {
        cout << "equals operater working successfully" << endl;
    }

    return 0;
}