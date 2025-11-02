#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <iomanip>

using namespace std;

class Multiset {
private:
    unordered_map<string, int> data;     // element -> multiplicity
    vector<string> elements;             // maintain order
    unordered_map<string, int> indices;  // NEW: element -> universe index

public:
    Multiset();
    Multiset(const vector<string>& values);
    Multiset(const vector<pair<int,int>>& indexMult, const vector<string>& universe);

    // Operations
    Multiset Union(const Multiset& other) const;//1.
    Multiset Intersection(const Multiset& other) const;//2.
    Multiset Difference(const Multiset& other) const;//3. and 4.
    Multiset SymDiff(const Multiset& other) const;//5.
    Multiset Complement(const vector<string>& universeVec, const unordered_map<int,int>& universeMap) const;//6. and 7.

    Multiset ArithSum(const Multiset& other) const;//8.
    Multiset ArithProd(const Multiset& other) const;//9.
    Multiset ArithDiff(const Multiset& other) const;//10. and 11.
    Multiset ArithDiv(const Multiset& other) const;//12.

    void print(const string& title, bool showHeader = true) const;

    bool empty() const { return data.empty(); }
    const unordered_map<string,int>& getData() const { return data; }
};
