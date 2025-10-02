# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
LDFLAGS =

SRC_DIR = Source
OBJ_DIR = object
INCLUDE_DIR = include
BIN_DIR = .

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

EXECUTABLE = $(BIN_DIR)/a.out

# Default target
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(LDFLAGS) $^ -o $@
	@echo "Linking complete. Executable created at $(EXECUTABLE)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled $< into $@"

clean:
	@echo "Cleaning up..."
	rm -rf $(OBJ_DIR) $(EXECUTABLE)

.PHONY: all clean
