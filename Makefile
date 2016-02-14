CC = g++
CFLAGS = -std=c++11 -Wall -Wextra

SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)/*.h)

all: ./program-generator
	
program-generator: $(SOURCES) $(HEADERS) 
	$(CC) $(CFLAGS) $(SOURCES) -o $@
	./$@ test.cpp

check: test.cpp
	$(CC) $(CFLAGS) $< -o generated-program
	./generated-program

