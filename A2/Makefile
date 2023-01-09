LIBHARU = ./libharu
CC = g++
CFLAGS = -Wall

test: spiralPDF
	./spiralPDF "hello i am making a test target, this is my sample spiral that implements haru pdf #justharuthings"

spiralPDF: spiralPDF.o Spiral.o HaruPDF.o
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -o spiralPDF spiralPDF.o Spiral.o HaruPDF.o -L$(LIBHARU)/src -lhpdfs -lz


spiralPDF.o: spiralPDF.cpp 
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -c spiralPDF.cpp

Spiral.o: Spiral.cpp Spiral.h
	$(CC) $(CFLAGS) -c Spiral.cpp

HaruPDF.o: HaruPDF.cpp HaruPDF.h
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -c HaruPDF.cpp


clean:
	rm -f spiralPDF *.o *.pdf