#include "Menu.h"
#include "GrayCodeGenerator.h"
#include "Multiset.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <unordered_set>

using namespace std;

//--------------------------------------------------
// Helper: safe integer input (prevents crash on invalid input)
//--------------------------------------------------
int safeInputInt(const string& message, int minValue, int maxValue) {
    int value;
    while (true) {
        cout << message;
        if (cin >> value) {
            if (value >= minValue && value <= maxValue)
                return value;
            else
                cout << "Out of range! Please enter a value between "
                     << minValue << " and " << maxValue << "." << endl;
        } else {
            cout << "Input error! Please enter an integer value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

//--------------------------------------------------
// Start program: show interface first
//--------------------------------------------------
void Menu::start() {
    srand(time(0));
    cout << endl;

    runMenu();
}

//--------------------------------------------------
// Create multisets A and B
//--------------------------------------------------
void Menu::createA() {
    using namespace std;
    cout << endl << "__________________________________________________" << endl;
    cout << "Let's create the multiset A" << endl;
    cout << "Press [b] to return to the main menu, or press Enter to continue creating Set A..." << endl;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string respA;
    getline(cin, respA);
    if (respA == "b" || respA == "B") {
        cout << "Returning to main menu..." << endl;
        return;
    }

    int modeA = safeInputInt("Choose how your multiset will be filled ([0]=Automatic, [1]=Manual): ", 0, 1);
    int sizeA = safeInputInt("How many different elements must there be in multiset A? ", 0, (int)universeVec.size());

    vector<pair<int,int>> Adata; // pair<index, multiplicity>

    if (modeA == 0) {
        unordered_set<int> used;
        while ((int)Adata.size() < sizeA) {
            int idx = rand() % universeVec.size();
            if (used.count(idx)) continue;
            used.insert(idx);
            int mult = rand() % 100;
            Adata.push_back({idx, mult});
        }
    } else {
        cout << "Do you want to set multiplicities manually [1], or generate automatically [0]? ";
        int mset = safeInputInt("", 0, 1);

        unordered_set<int> used;
        cout << "Enter " << sizeA << " unique indices (0–" << universeVec.size()-1 << ") from the universe:" << endl;
        for (int i = 0; i < sizeA; i++) {
            int index;
            while (true) {
                index = safeInputInt("Index: ", 0, (int)universeVec.size()-1);
                if (used.count(index)) {
                    cout << "You can't enter a repeating element! Try again." << endl;
                } else break;
            }
            used.insert(index);
            int multiplicity = (mset == 1)
                ? safeInputInt("Multiplicity for this element: ", 0, 100)
                : rand() % 100;
            Adata.push_back({index, multiplicity});
        }
    }

    A = Multiset(Adata, universeVec);
    cout << endl << "==========================================" << endl;
    A.print("Set A", true);

    cout << "Press Enter to continue..." << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

void Menu::createB() {
    using namespace std;
    cout << endl << "__________________________________________________" << endl;
    cout << "Let's create the multiset B" << endl;
    cout << "Press [b] to return to the main menu, or press Enter to continue creating Set B..." << endl;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string respB;
    getline(cin, respB);
    if (respB == "b" || respB == "B") {
        cout << "Returning to main menu..." << endl;
        return;
    }

    int modeB = safeInputInt("Choose how your multiset will be filled ([0]=Automatic, [1]=Manual): ", 0, 1);
    int sizeB = safeInputInt("How many different elements must there be in multiset B? ", 0, (int)universeVec.size());

    vector<pair<int,int>> Bdata;

    if (modeB == 0) {
        unordered_set<int> usedB;
        while ((int)Bdata.size() < sizeB) {
            int idx = rand() % universeVec.size();
            if (usedB.count(idx)) continue;
            usedB.insert(idx);
            int mult = rand() % 100;
            Bdata.push_back({idx, mult});
        }
    } else {
        cout << "Do you want to set multiplicities manually [1], or generate automatically [0]? ";
        int mset = safeInputInt("", 0, 1);

        unordered_set<int> used;
        cout << "Enter " << sizeB << " unique indices (0–" << universeVec.size()-1 << ") from the universe:" << endl;
        for (int i = 0; i < sizeB; i++) {
            int index;
            while (true) {
                index = safeInputInt("Index: ", 0, (int)universeVec.size()-1);
                if (used.count(index)) {
                    cout << "You can't enter a repeating element! Try again." << endl;
                } else break;
            }
            used.insert(index);
            int multiplicity = (mset == 1)
                ? safeInputInt("Multiplicity for this element: ", 0, 100)
                : rand() % 100;
            Bdata.push_back({index, multiplicity});
        }
    }

    B = Multiset(Bdata, universeVec);
    cout << endl << "==========================================" << endl;
    B.print("Set B", true);

    cout << "Press Enter to continue..." << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}


void Menu::createMultisets() {
    // The back/Enter prompts are inside createA/createB
    createA();
    createB();
}


//--------------------------------------------------
// Header (menu view)
//--------------------------------------------------
void Menu::printHeader() {
    cout << endl;
    cout << "==========================================" << endl;
    cout << "    MULTISET CALCULATOR PROGRAM" << endl;
    cout << "    Discrete Mathematics Lab 1" << endl;
    cout << "==========================================" << endl;
    cout << endl;

    cout << "0.  Enter bit length for the Universe (0–10 bits)" << endl << endl;

    cout << "SET OPERATIONS:" << endl;
    cout << " 1.  Union (A ∪ B)" << endl;
    cout << " 2.  Intersection (A ∩ B)" << endl;
    cout << " 3.  Difference (A - B)" << endl;
    cout << " 4.  Difference (B - A)" << endl;
    cout << " 5.  Symmetric Difference (A Δ B)" << endl << endl;

    cout << "COMPLEMENT OPERATIONS:" << endl;
    cout << " 6.  Complement of A" << endl;
    cout << " 7.  Complement of B" << endl << endl;

    cout << "ARITHMETIC OPERATIONS:" << endl;
    cout << " 8.  Arithmetic Sum (A + B)" << endl;
    cout << " 9.  Arithmetic Product (A × B)" << endl;
    cout << " 10. Arithmetic Difference (A - B)" << endl;
    cout << " 11. Arithmetic Difference (B - A)" << endl;
    cout << " 12. Arithmetic Division (A ÷ B)" << endl << endl;

    cout << "DISPLAY / RESET:" << endl;
    cout << " 13. View All (A, B & Universe)" << endl;
    cout << " 14. Reset Set A" << endl;
    cout << " 15. Reset Set B" << endl << endl;

    cout << " x.  EXIT" << endl;
    cout << "==========================================" << endl;
}

//--------------------------------------------------
// Main loop
//--------------------------------------------------
void Menu::runMenu() {
    string choice;
    do {
        printHeader();
        cout << "Enter your choice [0–18] or [x] to exit: ";
        cin >> choice;
        cout << endl;

        if (choice == "0") {
            int n = safeInputInt("Enter bit length for the universe (0–10 bits): ", 0, 10);
            universeVec = GrayCodeGenerator::generate(n);
            universeMap.clear();
            for (size_t i = 0; i < universeVec.size(); ++i)
                universeMap[i] = rand() % 100;

            cout << endl << "Generated " << n << "-bit Gray code universe with random values:" << endl;
            for (size_t i = 0; i < universeVec.size(); ++i)
                cout << "     " << universeVec[i] << "  [" << i << "] :  " << universeMap[i] << endl;
            cout << "----------------------------------------" << endl;
            cout << "Press [b] to return to the main menu, or press Enter to create multisets..." << endl;
            cin.ignore();
            string resp;
            getline(cin, resp);
            if (resp == "b" || resp == "B") {
                cout << "Returning to main menu..." << endl;
            } else {
                createMultisets();
            }

        }

        else if (choice == "1") {
            cout << "\n--- UNION (A ∪ B) ---\n";

            if (A.empty() && B.empty()) {
                cout << "Both sets are empty. Result: ∅ (empty set)\n";
            } 
            else if (A.empty()) {
                cout << "Set A is empty. Result = Set B.\n";
                B.print("A ∪ B", true);
            } 
            else if (B.empty()) {
                cout << "Set B is empty. Result = Set A.\n";
                A.print("A ∪ B", true);
            } 
            else {
                Multiset result = A.Union(B);
                result.print("A ∪ B", true);
            }

            cout << "----------------------------------------" << endl;
            cout << "Press Enter to return to the main menu..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

        else if (choice == "2") {
            cout << "\n--- INTERSECTION ---\n";

            if (A.empty() && B.empty()) {
                cout << "Both sets are empty. Result: (empty set)\n";
            } 
            else if (A.empty() || B.empty()) {
                cout << "One of the sets is empty. Result: (empty set)\n";
            } 
            else {
                Multiset result = A.Intersection(B);
                result.print("Intersection", true);
            }

            cout << "----------------------------------------" << endl;
            cout << "Press Enter to return to the main menu..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

        else if (choice == "3") {
            cout << "\n--- DIFFERENCE (A - B) ---\n";

            if (A.empty() && B.empty()) {
                cout << "Both sets are empty. Result: ∅ (empty set)\n";
            }
            else if (A.empty()) {
                cout << "Set A is empty. Result: ∅ (empty set)\n";
            }
            else {
                Multiset result = A.Difference(B);
                result.print("A - B", true);
            }

            cout << "----------------------------------------" << endl;
            cout << "Press Enter to return to the main menu..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

        else if (choice == "4") {
            cout << "\n--- DIFFERENCE (B - A) ---\n";

            if (A.empty() && B.empty()) {
                cout << "Both sets are empty. Result: ∅ (empty set)\n";
            }
            else if (B.empty()) {
                cout << "Set B is empty. Result: ∅ (empty set)\n";
            }
            else {
                Multiset result = B.Difference(A);
                result.print("B - A", true);
            }

            cout << "----------------------------------------" << endl;
            cout << "Press Enter to return to the main menu..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

        else if (choice == "5") {
            cout << "\n--- SYMMETRIC DIFFERENCE (A /_\\ B) ---\n";

            if (A.empty() && B.empty()) {
                cout << "Both sets are empty. Result: ∅ (empty set)\n";
            }
            else {
                Multiset result = A.SymDiff(B);
                result.print("A Δ B", true);
            }

            cout << "----------------------------------------" << endl;
            cout << "Press Enter to return to the main menu..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

        else if (choice == "6") { // Complement of A
            cout << "\n--- COMPLEMENT OF A (Ā) ---\n";
            if (A.empty() && universeVec.empty()) {
                cout << "Universe or Set A is empty. Cannot compute complement.\n";
            } else {
                Multiset result = A.Complement(universeVec, universeMap);
                result.print("Ā (Complement of A)", true);
            }
            cout << "Press Enter to return to the main menu..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

        else if (choice == "7") { // Complement of B
            cout << "\n--- COMPLEMENT OF B (B̄) ---\n";
            if (B.empty() && universeVec.empty()) {
                cout << "Universe or Set B is empty. Cannot compute complement.\n";
            } else {
                Multiset result = B.Complement(universeVec, universeMap);
                result.print("B̄ (Complement of B)", true);
            }
            cout << "Press Enter to return to the main menu..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

        else if (choice == "8") { // Arithmetic Sum
            cout << "\n--- ARITHMETIC SUM (A + B) ---\n";

            if (A.empty() && B.empty()) {
                cout << "Both sets are empty. Result: ∅ (empty set)\n";
            }
            else if (A.empty()) {
                cout << "Set A is empty. Result = Set B.\n";
                B.print("A + B (equal to B)", true);
            }
            else if (B.empty()) {
                cout << "Set B is empty. Result = Set A.\n";
                A.print("A + B (equal to A)", true);
            }
            else {
                Multiset result = A.ArithSum(B);
                result.print("A + B", true);
            }

            cout << "----------------------------------------" << endl;
            cout << "Press Enter to return to the main menu..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

        else if (choice == "9") { // Arithmetic Product
            cout << "\n--- ARITHMETIC PRODUCT (A × B) ---\n";

            if (A.empty() && B.empty()) {
                cout << "Both sets are empty. Result: ∅ (empty set)\n";
            }
            else if (A.empty() || B.empty()) {
                cout << "One of the sets is empty. Product = ∅ (empty set)\n";
            }
            else {
                Multiset result = A.ArithProd(B);
                result.print("A × B", true);
            }

            cout << "----------------------------------------" << endl;
            cout << "Press Enter to return to the main menu..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

        else if (choice == "10") { // Arithmetic Difference (A - B)
            cout << "\n--- ARITHMETIC DIFFERENCE (A - B) ---\n";

            if (A.empty() && B.empty()) {
                cout << "Both sets are empty. Result: ∅ (empty set)\n";
            }
            else if (A.empty()) {
                cout << "Set A is empty. Result: ∅ (empty set)\n";
            }
            else {
                Multiset result = A.ArithDiff(B);
                result.print("A - B", true);
            }

            cout << "----------------------------------------" << endl;
            cout << "Press Enter to return to the main menu..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

        else if (choice == "11") { // Arithmetic Difference (B - A)
            cout << "\n--- ARITHMETIC DIFFERENCE (B - A) ---\n";

            if (A.empty() && B.empty()) {
                cout << "Both sets are empty. Result: ∅ (empty set)\n";
            }
            else if (B.empty()) {
                cout << "Set B is empty. Result: ∅ (empty set)\n";
            }
            else {
                Multiset result = B.ArithDiff(A);
                result.print("B - A", true);
            }

            cout << "----------------------------------------" << endl;
            cout << "Press Enter to return to the main menu..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

        else if (choice == "12") { // Arithmetic Division (A ÷ B)
            cout << "\n--- ARITHMETIC DIVISION (A ÷ B) ---\n";

            if (A.empty() && B.empty()) {
                cout << "Both sets are empty. Result: ∅ (empty set)\n";
            }
            else if (A.empty() || B.empty()) {
                cout << "One of the sets is empty. Division = ∅ (empty set)\n";
            }
            else {
                Multiset result = A.ArithDiv(B);
                result.print("A ÷ B", true);
            }

            cout << "----------------------------------------" << endl;
            cout << "Press Enter to return to the main menu..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

        else if (choice == "13") {
            A.print("Multiset A", true);
            B.print("Multiset B", true);
            printUniverse();
        }

       else if (choice == "14") {
            A = Multiset();
            cout << "Set A has been reset." << endl;
            cout << "Press [1] to create Set A again, or press Enter to return to the main menu..." << endl;

            cin.ignore();
            string resp;
            getline(cin, resp);

            if (resp == "1") {
                cout << endl << "Recreating Set A..." << endl;
                createA(); // ONLY A
            }
        }

        else if (choice == "15") {
            B = Multiset();
            cout << "Set B has been reset." << endl;
            cout << "Press [1] to create Set B again, or press Enter to return to the main menu..." << endl;

            cin.ignore();
            string resp;
            getline(cin, resp);

            if (resp == "1") {
                cout << endl << "Recreating Set B..." << endl;
                createB(); // ONLY B
            }
        }


        else if (choice == "x" || choice == "X") {
            cout << "Program terminated. Goodbye!" << endl;
            break;
        }

        else {
            cout << "Operation not implemented or invalid. Please choose again." << endl;
        }

        cout << endl << "Press Enter to return to the main menu..." << endl;
        cin.ignore();
        cin.get();

    } while (true);
}

//--------------------------------------------------
// Print universe
//--------------------------------------------------
void Menu::printUniverse() {
    cout << "----------------------------------------" << endl;
    cout << "Universe" << endl;
    if (universeVec.empty()) {
        cout << "(Universe not created yet)" << endl;
    } else {
        for (size_t i = 0; i < universeVec.size(); ++i)
            cout << "     " << universeVec[i] << "  [" << i << "] :  "
                 << universeMap[i] << endl;
    }
    cout << "----------------------------------------" << endl;
}
