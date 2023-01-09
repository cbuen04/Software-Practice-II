# A3
# CS3505 Spring 2022
CC = g++
FLAGS = -Wall -g --std=c++11
TrieTest:TrieTest.cpp Trie.o
	$(CC) $(FLAGS) -o TrieTest Trie.o TrieTest.cpp
Trie.o: Trie.cpp Trie.h Node.h
	$(CC) $(FLAGS) -c Trie.cpp
clean:
	rm TrieTest *.o
test:
	./TrieTest "wrd.txt" "qry.txt"
test2:
	./TrieTest "wrd1.txt" "qry1.txt"