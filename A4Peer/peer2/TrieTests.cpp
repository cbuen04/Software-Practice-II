// Emily Best and Vista Marston CS 3505 A4 Spring 2022
#include "gtest/gtest.h"
#include "Trie.h"

// Tests for Rule of Three

TEST(TrieTests, CopyContructorReferenceMatching) {
    Trie testerTrie;
    testerTrie.addAWord("happy");
    Trie copyTrie(testerTrie);
    // Ensuring references are not equal
    ASSERT_FALSE(&copyTrie == &testerTrie);
}

TEST(TrieTests, CopyContructorAddingDoesNotAffectEachOther) {
    Trie testerTrie;
    testerTrie.addAWord("happy");
    Trie copyTrie(testerTrie);
    copyTrie.addAWord("world");
    ASSERT_TRUE(copyTrie.isAWord("world"));
    ASSERT_FALSE(testerTrie.isAWord("world"));
}

TEST(TrieTests, CopyConstructorContentsEmptyTrie) {
    Trie testerTrie;
    Trie copyTrie(testerTrie);
    for(int i = 0; i < 26; i++){
        char letter = i + 'a';
        std::string letterStr(1, letter);
        ASSERT_FALSE(testerTrie.isAWord(letterStr));
        ASSERT_FALSE(copyTrie.isAWord(letterStr));
    }
}

TEST(TrieTests, CopyConstructorContentsSmallTrie) {
    Trie testerTrie;
    testerTrie.addAWord("hello");
    testerTrie.addAWord("world");
    testerTrie.addAWord("hey");
    testerTrie.addAWord("word");
    testerTrie.addAWord("help");
    testerTrie.addAWord("worry");

    Trie copyTrie(testerTrie);

    ASSERT_TRUE(copyTrie.isAWord("hello"));
    ASSERT_TRUE(copyTrie.isAWord("world"));
    ASSERT_TRUE(copyTrie.isAWord("hey"));
    ASSERT_TRUE(copyTrie.isAWord("word"));
    ASSERT_TRUE(copyTrie.isAWord("help"));
    ASSERT_TRUE(copyTrie.isAWord("worry"));
}

TEST(TrieTests, AssignmentOperatorReferenceMatching) {
    Trie testerTrie;
    testerTrie.addAWord("happy");
    Trie copyTrie = testerTrie;
    // Ensuring references are not equal
    ASSERT_FALSE(&copyTrie == &testerTrie);
}

TEST(TrieTests, AssignmentOperatorContentsEmptyTrie) {
    Trie testerTrie;
    Trie copyTrie = testerTrie;
    for(int i = 0; i < 26; i++){
        char letter = i + 'a';
        std::string letterStr(1, letter);
        ASSERT_FALSE(testerTrie.isAWord(letterStr));
        ASSERT_FALSE(copyTrie.isAWord(letterStr));
    }
}

TEST(TrieTests, AssignmentOperatorContentsSmallTrie) {
    Trie testerTrie;
    testerTrie.addAWord("hello");
    testerTrie.addAWord("world");
    testerTrie.addAWord("hey");
    testerTrie.addAWord("word");
    testerTrie.addAWord("help");
    testerTrie.addAWord("worry");

    Trie copyTrie = testerTrie;

    ASSERT_TRUE(copyTrie.isAWord("hello"));
    ASSERT_TRUE(copyTrie.isAWord("world"));
    ASSERT_TRUE(copyTrie.isAWord("hey"));
    ASSERT_TRUE(copyTrie.isAWord("word"));
    ASSERT_TRUE(copyTrie.isAWord("help"));
    ASSERT_TRUE(copyTrie.isAWord("worry"));
}

TEST(TrieTests, DestructorDeletesCopyConstructorCopyCheckReferences) {
    try {
        Trie testerTrie;
        testerTrie.addAWord("hello");
        Trie copyTrie(testerTrie);
    } catch (...) {
        FAIL() << "The destructor threw - the tries have the same reference.";
    }

    SUCCEED();
}

TEST(TrieTests, DestructorDeletesAssignmentOperatorCopyCheckReferences) {
    try {
        Trie testerTrie;
        testerTrie.addAWord("hello");
        Trie copyTrie = testerTrie;
    } catch (...) {
        FAIL() << "The destructor threw - the tries have the same reference.";
    }

    SUCCEED();
}

// Tests for addAWord() 

TEST(TrieTests, AddingEmptyStringTest) {
    Trie testerTrie;
    testerTrie.addAWord("");
    ASSERT_FALSE(testerTrie.isAWord(""));
}

TEST(TrieTests, AddingSingleBranchEnsureOnlyOne) {
    Trie testerTrie;
    testerTrie.addAWord("a");
    ASSERT_TRUE(testerTrie.isAWord("a"));
    for(int i = 1; i < 26; i++){
        char letter = i + 'a';
        std::string letterStr(1, letter);
        ASSERT_FALSE(testerTrie.isAWord(letterStr));
    }
}

TEST(TrieTests, AddingDuplicatedLetterIndividualBranch){
    Trie testerTrie;
    testerTrie.addAWord("aa");
    ASSERT_TRUE(testerTrie.isAWord("aa"));
}

TEST(TrieTests, AddingRepeatedWordNoChange) {
    Trie testerTrie;
    testerTrie.addAWord("aa");
    testerTrie.addAWord("aa");
    
    for(int i = 0; i < 26; i++){
        char letter = i + 'a';
        std::string letterStr(1, letter);
        ASSERT_FALSE(testerTrie.isAWord(letterStr));
    }

    for(int i = 1; i < 26; i++){
        char letter = i + 'a';
        std::string letterStr(1, letter);
        ASSERT_FALSE(testerTrie.isAWord("a" + letterStr));
    }
}

TEST(TrieTests, AddingSingleLetterWords) {
    Trie testerTrie;
    testerTrie.addAWord("a");
    testerTrie.addAWord("b");
    testerTrie.addAWord("c");
    ASSERT_TRUE(testerTrie.isAWord("a"));
    ASSERT_TRUE(testerTrie.isAWord("b"));
    ASSERT_TRUE(testerTrie.isAWord("c"));
}

TEST(TrieTests, AddingSmallWords) {
    Trie testerTrie;
    testerTrie.addAWord("a");
    testerTrie.addAWord("at");
    testerTrie.addAWord("app");
    testerTrie.addAWord("apple");
    ASSERT_TRUE(testerTrie.isAWord("a"));
    ASSERT_TRUE(testerTrie.isAWord("at"));
    ASSERT_TRUE(testerTrie.isAWord("app"));
    ASSERT_TRUE(testerTrie.isAWord("apple"));
}

TEST(TrieTests, AddingLargerWords) {
    Trie testerTrie;
    testerTrie.addAWord("linen");
    testerTrie.addAWord("distortion");
    testerTrie.addAWord("document");
    testerTrie.addAWord("withdrawal");
    ASSERT_TRUE(testerTrie.isAWord("linen"));
    ASSERT_TRUE(testerTrie.isAWord("distortion"));
    ASSERT_TRUE(testerTrie.isAWord("document"));
    ASSERT_TRUE(testerTrie.isAWord("withdrawal"));
}

// Tests for isAWord()

TEST(TrieTests, EmptyStringNotWord) {
    Trie testerTrie;
    ASSERT_FALSE(testerTrie.isAWord(""));
}

TEST(TrieTests, RootNodeNotWord) {
    Trie testerTrie;
    testerTrie.addAWord("a");
    ASSERT_FALSE(testerTrie.isAWord(""));
}

TEST(TrieTests, SingleWordAsAWord) {
    Trie testerTrie;
    testerTrie.addAWord("a");
    ASSERT_TRUE(testerTrie.isAWord("a"));
    ASSERT_FALSE(testerTrie.isAWord("b"));
}

TEST(TrieTests, SingleWordNotAWord) {
    Trie testerTrie;
    ASSERT_FALSE(testerTrie.isAWord("bat"));
}

TEST(TrieTests, SmallWordsNotInTrieNotWords) {
    Trie testerTrie;
    testerTrie.addAWord("happy");
    testerTrie.addAWord("unicorn");
    ASSERT_FALSE(testerTrie.isAWord("missippippi"));
}

TEST(TrieTests, IntermediatePrefixNotWordsLeadingToWords) {
    Trie testerTrie;
    testerTrie.addAWord("a");
    testerTrie.addAWord("apple");
    ASSERT_TRUE(testerTrie.isAWord("a"));
    ASSERT_FALSE(testerTrie.isAWord("ap"));
    ASSERT_FALSE(testerTrie.isAWord("app"));
    ASSERT_FALSE(testerTrie.isAWord("appl"));
    ASSERT_TRUE(testerTrie.isAWord("apple"));
}

TEST(TrieTests, LargeWordsInTrieNotAWord) {
    Trie testerTrie;
    testerTrie.addAWord("extraterrestrial");
    testerTrie.addAWord("sympathetic");
    ASSERT_FALSE(testerTrie.isAWord("quicksilver"));
}

// Tests for allWordsStartingWithPrefix()

TEST(TrieTests, PrefixIsEmptyStringGetAllWords) {
    Trie testerTrie;
    testerTrie.addAWord("egg");
    testerTrie.addAWord("fruit");
    testerTrie.addAWord("bacon");
    testerTrie.addAWord("toast");
    std::vector<std::string> words = testerTrie.allWordsStartingWithPrefix("");
    for(auto word : words){
        bool word1 = word == "egg";
        bool word2 = word == "fruit";
        bool word3 = word == "bacon";
        bool word4 = word == "toast";
        ASSERT_TRUE(word1 | word2 | word3 | word4);
    }
}

TEST(TrieTests, SmallPrefixLengthGetsThatIndividualBranch) {
    Trie testerTrie;
    testerTrie.addAWord("extraterrestrial");
    testerTrie.addAWord("ex");
    testerTrie.addAWord("extra");
    testerTrie.addAWord("extraterr");
    testerTrie.addAWord("alien");
    std::vector<std::string> words = testerTrie.allWordsStartingWithPrefix("e");
    for(auto word : words){
        bool word1 = word == "extraterrestrial";
        bool word2 = word == "ex";
        bool word3 = word == "extra";
        bool word4 = word == "extraterr";
        ASSERT_TRUE(word1 | word2 | word3 | word4);
        ASSERT_FALSE(word == "alien");
    }
    // SUCCEED();
}

TEST(TrieTests, MediumPrefixLengthGetSmallerSizeOfWords) {
    Trie testerTrie;
    testerTrie.addAWord("extraterrestrial");
    testerTrie.addAWord("ex");
    testerTrie.addAWord("extra");
    testerTrie.addAWord("extraterr");
    testerTrie.addAWord("alien");
    std::vector<std::string> words = testerTrie.allWordsStartingWithPrefix("extra");
    for(auto word : words){
        bool word1 = word == "extraterrestrial";
        bool word3 = word == "extra";
        bool word4 = word == "extraterr";
        ASSERT_TRUE(word1 | word3 | word4);
        ASSERT_FALSE(word == "alien");
        ASSERT_FALSE(word == "ex");
    }
}

TEST(TrieTests, NoPrefixWordsInTrieReturnEmptyList) {
    Trie testerTrie;
    testerTrie.addAWord("extraterrestrial");
    testerTrie.addAWord("ex");
    testerTrie.addAWord("extra");
    testerTrie.addAWord("extraterr");
    testerTrie.addAWord("alien");
    std::vector<std::string> words = testerTrie.allWordsStartingWithPrefix("c");
    ASSERT_TRUE(words.size() == 0);
}

TEST(TrieTests, DoesIncludePrefixWhenReturnAllPrefixes) {
    Trie testerTrie;
    testerTrie.addAWord("e");
    testerTrie.addAWord("ex");
    testerTrie.addAWord("ext");
    testerTrie.addAWord("extr");
    testerTrie.addAWord("extra");
    std::vector<std::string> words = testerTrie.allWordsStartingWithPrefix("extra");
    ASSERT_TRUE(words.size() == 1);
    ASSERT_TRUE("extra" == *words.begin());
}