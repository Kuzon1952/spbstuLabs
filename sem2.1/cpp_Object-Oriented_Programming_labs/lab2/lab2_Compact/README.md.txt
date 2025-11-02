lab2/
├── include/                     # header files (.h)
│   ├── Shape.h
│   ├── Rect.h
│   ├── Vector.h
│   ├── Circle.h
│   ├── MyString.h
│   └── stdafx.h
│
├── src/                         # source code (.cpp)
│   ├── Lab2.cpp                 # main file
│   ├── Shape.cpp
│   ├── Rect.cpp
│   ├── Vector.cpp
│   ├── Circle.cpp
│   ├── MyString.cpp
│
├── build/                       # compiled output (not tracked)
│   ├── lab2                     # final executable
│   └── object_files/            # optional .o files
│
├── Makefile                     # build instructions
└── README.md                    # short description

make        # builds the program
make run    # builds and runs the program
make clean  # deletes /build folder
