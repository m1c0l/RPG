CC = g++
CFLAGS = -std=c++11 -Wall -Wextra

all: src/main.cpp
	$(CC) $(CFLAGS) $< -o program-generator
	./program-generator test.cpp

check: test.cpp
	$(CC) $(CFLAGS) $< -o generated-program
	./generated-program

