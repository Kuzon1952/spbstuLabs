#include <iostream>
#include "Shape.h"
#include "MyVector.h"  // Full definition needed for implementation

using namespace std;

// Initialize static members
int Shape::Count = 0;

Shape* Shape::shapes[1000] = { nullptr };

Shape::Shape()
{
    if (Count < 1000) {
        shapes[Count] = this;
    }
    Count++;
}

Shape::~Shape()
{
    // Remove this shape from the array
    for (int i = 0; i < Count && i < 1000; i++) {
        if (shapes[i] == this) {
            // Shift remaining elements
            for (int j = i; j < Count - 1 && j < 999; j++) {
                shapes[j] = shapes[j + 1];
            }
            shapes[Count - 1] = nullptr;
            break;
        }
    }
    Count--;
}

void Shape::PrintCount()
{
    cout << "\n Now there are " << Count << " shapes"<<endl;
}

int Shape::GetCount()
{
    return Count;
}

void Shape::PrintFormattedShapes()
{
    cout << "\n\n=== Formatted Shapes List ===";
    for (int i = 0; i < Count && i < 1000; i++) {
        if (shapes[i] != nullptr) {
            cout << "\n\nShape " << i << ":";
            shapes[i]->Out();
            cout << "\nArea = " << shapes[i]->Area();
        }
    }
    cout << "\n=============================";
}
