# ========= Makefile for Lab2 =========

#compiler
CXX = g++
CXXFLAGS = -g -Wall -std=c++17

#object files
OBJS = build/lab2.o build/basefile.o build/base32file.o build/base32file2.o build/rlefile.o build/rlefile2.o build/mystring.o

#test object files
TEST_OBJS = build/test_base32file.o build/basefile.o build/base32file.o

#target executable
build/lab2.out: $(OBJS)
	$(CXX) $(CXXFLAGS) -o build/lab2.out $(OBJS)

#compilation rules
build/lab2.o: src/lab2.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/basefile.o: src/basefile.cpp src/basefile.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/base32file.o: src/base32file.cpp src/base32file.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/base32file2.o: src/base32file2.cpp src/base32file2.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/rlefile.o: src/rlefile.cpp src/rlefile.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/rlefile2.o: src/rlefile2.cpp src/rlefile2.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/mystring.o: src/mystring.cpp src/mystring.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#memory leak detection build
build/leaks.out: $(OBJS)
	$(CXX) $(CXXFLAGS) -fsanitize=address -o build/leaks.out $(OBJS)

#running memory leak check
.PHONY: leaks
leaks: build/leaks.out
	./build/leaks.out

#clean build directory
.PHONY: clean
clean:
	rm -rf build/*

#test build 
build/test_base32file.o: tests/test_base32file.cpp src/base32file.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#test executable
build/test.out: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o build/test.out $(TEST_OBJS)

#run
.PHONY: run_test
run_test: build/test.out
	./build/test.out
