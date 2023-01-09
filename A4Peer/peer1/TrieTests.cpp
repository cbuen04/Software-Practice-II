#include "gtest/gtest.h"
#include "Trie.h"
#include <vector>

TEST(TrieTest, AddAWord) {
    Trie t;
    std::string n("cat");
    t.addAWord(n);
    ASSERT_TRUE(t.isAWord(n));
}

TEST(TrieTest, IsAWord) {
    Trie t;
    std::string n("cat");
    t.addAWord(n);
    ASSERT_FALSE(t.isAWord("cats"));
}

TEST(TrieTest, PrefixBasicCase) {
    Trie t;
    std::string n("cat");
    t.addAWord(n);
    std::vector<std::string> vector;
    vector.push_back(n);
    ASSERT_EQ(vector, t.allWordsStartingWithPrefix("cat"));
}

TEST(TrieTest, PrefixEdgeCase) {
    Trie t;
    std::string n("cat");
    std::string a("craft");
    t.addAWord(n);
    t.addAWord(a);
    std::vector<std::string> vector;
    vector.push_back(n);
    vector.push_back(a);
    ASSERT_EQ(vector, t.allWordsStartingWithPrefix("c"));
}

TEST(TrieTest, PrefixEmpty) {
    Trie t;
    std::string n("cat");
    std::string a("craft");
    t.addAWord(n);
    t.addAWord(a);
    std::vector<std::string> vector;
    vector.push_back(n);
    vector.push_back(a);
    ASSERT_EQ(vector, t.allWordsStartingWithPrefix(""));
}

TEST(TrieTest, TrieCopyingBasic) {
    Trie oldTrie;
    std::string n("cat");
    oldTrie.addAWord(n);
    Trie newTrie;
    std::string a("adam");
    newTrie.addAWord(a);
    newTrie = oldTrie;
    ASSERT_TRUE(newTrie.isAWord(n));
    ASSERT_FALSE(newTrie.isAWord(a));
}

TEST(TrieTest, TrieCopying) {
    Trie oldTrie;
    std::string n("cat");
    oldTrie.addAWord(n);
    Trie newTrie;
    std::string a("adam");
    newTrie.addAWord(a);
    newTrie = oldTrie;
    newTrie.addAWord("diamond");
    std::vector<std::string> vec;
    vec.push_back("diamond");
    ASSERT_EQ(vec, newTrie.allWordsStartingWithPrefix("d"));
}

TEST(TrieTest, TrieCopyingReferences) {
    Trie oldTrie;
    std::string n("cat");
    oldTrie.addAWord(n);
    Trie newTrie;
    std::string a("adam");
    newTrie.addAWord(a);
    newTrie = oldTrie;
    ASSERT_FALSE(&newTrie == &oldTrie);
}