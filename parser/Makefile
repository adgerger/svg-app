CFLAGS = -Wall -g -std=c11
BIN = ../
INC = include/
SRC = src/
XML_PATH = /usr/include/libxml2

# Standard common makefile
parser: $(BIN)libsvgparse.so

$(BIN)libsvgparse.so: SVGParser.o LinkedListAPI.o
	gcc -shared -o $(BIN)libsvgparse.so SVGParser.o LinkedListAPI.o -lxml2 -lm

SVGParser.o: $(SRC)SVGParser.c $(INC)LinkedListAPI.h $(INC)SVGParser.h
	gcc -c -fpic $(CFLAGS) -I$(XML_PATH) -I$(INC) $(SRC)SVGParser.c -o SVGParser.o

LinkedListAPI.o: $(SRC)LinkedListAPI.c $(INC)LinkedListAPI.h
	gcc -c -fpic $(CFLAGS) -I$(INC) $(SRC)LinkedListAPI.c -o LinkedListAPI.o

clean:
	rm *.o $(BIN)*.so

