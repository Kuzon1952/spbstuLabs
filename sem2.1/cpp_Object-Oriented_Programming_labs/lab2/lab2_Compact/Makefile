# =========================
#   Lab 2 - C++ Project
# =========================

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Folders
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/object_files

# Files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
EXEC = $(BUILD_DIR)/lab2

# Default target
all: $(EXEC)

# Link step
$(EXEC): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJECTS) -o $(EXEC)
	@echo " Build complete: $(EXEC)"

# Compile each .cpp into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean compiled files
clean:
	rm -rf $(BUILD_DIR)
	@echo " Cleaned build files."

# Run program
run: all
	@echo "\n Running program:\n"
	@./$(EXEC)
