INCLUDE = ./carlib/include
CC = g++
CFLAGS = -Wall

car: main.o car.o
	$(CC) $(CFLAGS) -o car main.o car.o

main.o: main.cpp $(INCLUDE)/car.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c main.cpp

car.o: car.cpp $(INCLUDE)/car.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c car.cpp

clean:
	rm -f car *.o *.a
