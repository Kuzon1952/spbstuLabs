#object files
OBJS = build/lab3.o build/matrix.o build/mystring.o build/shortarray.o build/workerdb.o build/workerinfo.o build/basefile.o build/boolarray.o

#compiler
CXX = g++
CXXFLAGS = -g -Wall -std=c++17 -Isrc  

#executable target
build/lab3.out: $(OBJS)
	$(CXX) $(CXXFLAGS) -o build/lab3.out $(OBJS)

#compile source files
build/lab3.o: src/lab3.cpp
	$(CXX) $(CXXFLAGS) -c src/lab3.cpp -o build/lab3.o

build/matrix.o: src/matrix.cpp src/matrix.hpp
	$(CXX) $(CXXFLAGS) -c src/matrix.cpp -o build/matrix.o

build/mystring.o: src/mystring.cpp src/mystring.hpp
	$(CXX) $(CXXFLAGS) -c src/mystring.cpp -o build/mystring.o

build/shortarray.o: src/shortarray.cpp src/shortarray.hpp
	$(CXX) $(CXXFLAGS) -c src/shortarray.cpp -o build/shortarray.o

build/workerdb.o: src/workerdb.cpp src/workerdb.hpp
	$(CXX) $(CXXFLAGS) -c src/workerdb.cpp -o build/workerdb.o

build/workerinfo.o: src/workerinfo.cpp src/workerinfo.hpp
	$(CXX) $(CXXFLAGS) -c src/workerinfo.cpp -o build/workerinfo.o

build/basefile.o: src/basefile.cpp src/basefile.hpp
	$(CXX) $(CXXFLAGS) -c src/basefile.cpp -o build/basefile.o

build/boolarray.o: src/boolarray.cpp src/boolarray.h
	$(CXX) $(CXXFLAGS) -c src/boolarray.cpp -o build/boolarray.o

#leaks detection
build/leaks.out: $(OBJS)
	$(CXX) $(CXXFLAGS) -fsanitize=address -o build/leaks.out $(OBJS)

#run leak detection
.PHONY: leaks
leaks: build/leaks.out
	./build/leaks.out

#tests - task2_mystring test rule
build/test_task2: tests/task2_mystring.cpp build/mystring.o
	$(CXX) $(CXXFLAGS) -o build/test_task2 tests/task2_mystring.cpp build/mystring.o

#run the test 
.PHONY: test_task2
test_task2: build/test_task2
	./build/test_task2

#tests - task5_basefile test rule
build/test_task5_basefile: tests/task5_basefile.cpp build/basefile.o
	$(CXX) $(CXXFLAGS) -o build/test_task5_basefile tests/task5_basefile.cpp build/basefile.o

#run the test 
.PHONY: test_task5_basefile
test_task5_basefile: build/test_task5_basefile
	./build/test_task5_basefile

#clean build files
.PHONY: clean
clean:
	rm -rf build/*
