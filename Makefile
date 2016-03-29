CC = g++
CFLAGS = -std=c++11 -g -Wall -Wextra

SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)/*.h)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

RPG = rpg

all: $(RPG)

$(RPG): $(OBJ_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(OPTIMIZE) -c $< -o $@


GENERATED = test.cpp
GENERATED_EXEC = $(GENERATED:%.cpp=%.out)
GENERATED_CFLAGS = -std=c++11

check: $(RPG)
	@# generate test program
	./$(RPG) $(GENERATED)
	@# compile test program
	$(CC) $(GENERATED_CFLAGS) $(GENERATED) -o $(GENERATED_EXEC)
	@# run test program
	./$(GENERATED_EXEC)

clean:
	rm -rf $(RPG) $(OBJ_DIR) $(GENERATED) $(GENERATED_EXEC)
