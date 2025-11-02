#obj files
OBJS = build/point.o build/circle.o build/node.o build/list.o

#compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I src -I test

#exe
MAIN_BIN = build/main
TEST_BIN = build/test

#default target
all: $(MAIN_BIN) $(TEST_BIN)

#build the main program
$(MAIN_BIN): $(OBJS) build/main.o
	$(CXX) $(CXXFLAGS) -o $(MAIN_BIN) $(OBJS) build/main.o

#build the test program
$(TEST_BIN): $(OBJS) build/test.o
	$(CXX) $(CXXFLAGS) -o $(TEST_BIN) $(OBJS) build/test.o

#compile source files to object files
build/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o build/main.o

build/test.o: test/test.cpp
	$(CXX) $(CXXFLAGS) -c test/test.cpp -o build/test.o

build/point.o: src/point.cpp src/point.hpp
	$(CXX) $(CXXFLAGS) -c src/point.cpp -o build/point.o

build/circle.o: src/circle.cpp src/circle.hpp
	$(CXX) $(CXXFLAGS) -c src/circle.cpp -o build/circle.o

build/node.o: src/node.cpp src/node.hpp
	$(CXX) $(CXXFLAGS) -c src/node.cpp -o build/node.o

build/list.o: src/list.cpp src/list.hpp
	$(CXX) $(CXXFLAGS) -c src/list.cpp -o build/list.o

#clean up build files
.PHONY: clean
clean:
	rm -rf build/*
