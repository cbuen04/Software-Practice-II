/**
 * @file TrieTest.cpp
 * @brief the tester for the trie class I constructed
 * @version A3
 * @class CS3505 Spring 2022
 *
 */
#include <iostream>
#include <fstream>
#include <vector>
#include "Trie.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Babez we need two filenames, try again" << endl;
        return 666;
    } 

    Trie tree;
    ifstream myfile;
    string currLine;
    // first open and load the tree
    string fileName = argv[1];
    if(fileName.substr(fileName.size()-4)!= ".txt")
    {
        cout<<"not the right kind of file, pass a txt file"<<endl;
        return 666;
    }
    myfile.open(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile, currLine))
        {
            tree.addAWord(currLine);
        }
    }
    else
    {
        cout << "Babez i'm not sure what went wrong but your file didn't get read right" << endl;
        return 666;
    }
    myfile.close();


    fileName = argv[2];
    if(fileName.substr(fileName.size()-4)!= ".txt")
    {
        cout<<"not the right kind of file, pass a txt file"<<endl;
        return 666;
    }
    // k now time to run the query file
    myfile.open(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile, currLine))
        {
            if (tree.isAWord(currLine))
            {
                cout << currLine << " is found" << endl;
            }
            else
            { // word isnt in the tree
                vector<string> alts = tree.allWordsStartingWithPrefix(currLine);
                cout << currLine << " is not found, did you mean:" << endl;
                // get alternatives to the word
                if (alts.size() != 0)
                {
                    for (int i = 0; i < alts.size(); i++)
                    {
                        cout << "\t"
                             << "\t" //these are indents
                             << "\t" << alts[i] << endl;
                    }
                }
                else
                {
                    cout << "\t"
                         << "\t"
                         << "\t" //these are indents
                            "no alternatives found"
                         << endl;
                }
            }
        }
    }
    else
    {
        cout << "Babez i'm not sure what went wrong but your file didn't get read right" << endl;
        return 666;
    }
    myfile.close();

    // rule of three
    Trie B;
    B.addAWord("testing");
    tree = B;
    if (tree.isAWord("testing")==0){
        cout << "Rule of Three isn't working"<< endl;
    } else{
       cout << "Rule of Three is working"<< endl; 
    }
}
