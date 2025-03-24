#obj files(each source file is compiled separately)
OBJS = build/lab1.o build/matrix.o build/rect.o build/barrel.o build/mystring.o build/TextWrapper.o

#Compiler
CXX = g++
CXXFLAGS = -g -Wall -std=c++17#Debugging and warnings

#target executable
build/debug.out: $(OBJS)
	$(CXX) $(CXXFLAGS) -o build/debug.out $(OBJS)

#compilation for each .cpp file
build/lab1.o: src/lab1.cpp
	$(CXX) $(CXXFLAGS) -c src/lab1.cpp -o build/lab1.o

build/matrix.o: src/matrix.cpp
	$(CXX) $(CXXFLAGS) -c src/matrix.cpp -o build/matrix.o

build/rect.o: src/rect.cpp
	$(CXX) $(CXXFLAGS) -c src/rect.cpp -o build/rect.o

build/barrel.o: src/barrel.cpp
	$(CXX) $(CXXFLAGS) -c src/barrel.cpp -o build/barrel.o

build/mystring.o: src/mystring.cpp
	$(CXX) $(CXXFLAGS) -c src/mystring.cpp -o build/mystring.o

build/TextWrapper.o: src/TextWrapper.cpp
	$(CXX) $(CXXFLAGS) -c src/TextWrapper.cpp -o build/TextWrapper.o

#memory Leak Detection Build
build/leaks.out: $(OBJS)
	$(CXX) $(CXXFLAGS) -fsanitize=address -o build/leaks.out $(OBJS)

#running Memory Leak Check
.PHONY: leaks
leaks: build/leaks.out
	./build/leaks.out

build/test_rect_basic_methods.out: tests/test_rect_basic_methods.cpp src/rect.cpp
	$(CXX) -g -o build/test_rect_basic_methods.out tests/test_rect_basic_methods.cpp src/rect.cpp

build/test_rect_properties.out: tests/test_rect_properties.cpp src/rect.cpp
	g++ -g -o build/test_rect_properties.out tests/test_rect_properties.cpp src/rect.cpp

build/test_rect_operations.out: tests/test_rect_operations.cpp src/rect.cpp
	g++ -g -o build/test_rect_operations.out tests/test_rect_operations.cpp src/rect.cpp

build/test_bounding_rect.out: tests/test_bounding_rect.cpp src/rect.cpp
	g++ -g -o build/test_bounding_rect.out tests/test_bounding_rect.cpp src/rect.cpp

test: build/test_rect_basic_methods.out build/test_rect_properties.out build/test_rect_operations.out build/test_bounding_rect.out

	@echo "_________________________________running test_rect_basic_methods..._________________________________"
	./build/test_rect_basic_methods.out

	@echo "_________________________________running test_rect_properties..._________________________________"
	./build/test_rect_properties.out

	@echo "_________________________________running test_rect_operations..._________________________________"
	./build/test_rect_operations.out

	@echo "_________________________________running test_bounding_rect..._________________________________"
	./build/test_bounding_rect.out

	@echo "_________________________________all working fine..._________________________________"


#cleanning build directory
.PHONY: clean test
clean:
	rm -rf build/*
