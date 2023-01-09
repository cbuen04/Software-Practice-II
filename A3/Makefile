CC = g++
CFLAGS = -Wall

test: TrieTest
	./TrieTest "testloadtrie.txt" "testtriequery.txt"

TrieTest: TrieTest.o Trie.o
	$(CC) $(CFLAGS) -o TrieTest TrieTest.o Trie.o 

TrieTest.o: TrieTest.cpp Trie.h
	$(CC) $(CFLAGS) -c TrieTest.cpp

Trie.o: Trie.cpp Trie.h
	$(CC) $(CFLAGS) -c Trie.cpp

clean:
	rm -f TrieTest *.o