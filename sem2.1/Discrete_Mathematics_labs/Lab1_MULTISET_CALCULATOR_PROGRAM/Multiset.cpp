#include "Multiset.h"
#include <algorithm>
#include <cmath>
using namespace std;

//--------------------------------------------------
Multiset::Multiset() {}

//--------------------------------------------------
Multiset::Multiset(const vector<string>& values) {
    for (const auto& v : values) {
        if (data.find(v) == data.end())
            elements.push_back(v);
        data[v]++;
    }
}

//--------------------------------------------------
// NEW: construct using index/multiplicity pairs + universe
Multiset::Multiset(const vector<pair<int,int>>& indexMult, const vector<string>& universe) {
    for (auto& [idx, mult] : indexMult) {
        if (idx >= 0 && idx < (int)universe.size()) {
            string code = universe[idx];
            data[code] = mult;
            indices[code] = idx;
            elements.push_back(code);
        }
    }
}

//--------------------------------------------------
// 1. Union (max of multiplicities)
Multiset Multiset::Union(const Multiset& other) const {
    Multiset result = *this;
    for (auto& [key, val] : other.data)
        result.data[key] = max(result.data[key], val);
    result.elements = elements;
    for (auto& [key, _] : other.data)
        if (find(result.elements.begin(), result.elements.end(), key) == result.elements.end())
            result.elements.push_back(key);
       
        result.indices = indices;
        for (auto& [k, v] : other.indices)
                result.indices[k] = v;

    return result;
}

//--------------------------------------------------
// 2. Intersection (min of multiplicities)
Multiset Multiset::Intersection(const Multiset& other) const {
    Multiset result;
    for (auto& [key, val] : data) {
        auto it = other.data.find(key);
        if (it != other.data.end())
            result.data[key] = min(val, it->second);
    }
    for (auto& [key, _] : result.data)
        result.elements.push_back(key);
    
    
    result.indices = indices;
    for (auto& [k, v] : other.indices)
        result.indices[k] = v;

    
    return result;
}

//--------------------------------------------------
// 3. and 4. Difference (A − B) = multiplicityA − multiplicityB (>=0)
Multiset Multiset::Difference(const Multiset& other) const {
    Multiset result;
    for (auto& [key, val] : data) {
        int diff = val - (other.data.count(key) ? other.data.at(key) : 0);
        if (diff > 0)
            result.data[key] = diff;
    }
    for (auto& [key, _] : result.data)
        result.elements.push_back(key);

    result.indices = indices;
    for (auto& [k, v] : other.indices)
        result.indices[k] = v;


    return result;
}

//--------------------------------------------------
// 5. Symmetric Difference = (A − B) ∪ (B − A)
Multiset Multiset::SymDiff(const Multiset& other) const {
    return this->Difference(other).Union(other.Difference(*this));
}

//--------------------------------------------------
// 6. and 7. Complement relative to universe: Ā or B̄
//--------------------------------------------------
Multiset Multiset::Complement(const vector<string>& universeVec,
                              const unordered_map<int,int>& universeMap) const {
    Multiset result;

    // Current multiset lookup
    unordered_map<string,int> current = data;

    // For every element in the universe:
    for (size_t i = 0; i < universeVec.size(); ++i) {
        string code = universeVec[i];
        int uVal = universeMap.count(i) ? universeMap.at(i) : 0;
        int aVal = current.count(code) ? current.at(code) : 0;
        int comp = max(uVal - aVal, 0);

        if (comp > 0) {
            result.data[code] = comp;
            result.elements.push_back(code);
            result.indices[code] = i;
        }
    }

    return result;
}


//--------------------------------------------------
//8. Arithmetic operations (elementwise)
//--------------------------------------------------
Multiset Multiset::ArithSum(const Multiset& other) const {
    Multiset result = *this;
    for (auto& [key, val] : other.data)
        result.data[key] += val;
    result.elements = elements;
    for (auto& [key, _] : other.data)
        if (find(result.elements.begin(), result.elements.end(), key) == result.elements.end())
            result.elements.push_back(key);


    result.indices = indices;
    for (auto& [k, v] : other.indices)
        result.indices[k] = v;
    

    return result;
}

//9.--------------------------------------------------
Multiset Multiset::ArithProd(const Multiset& other) const {
    Multiset result;
    for (auto& [key, val] : data) {
        if (other.data.count(key))
            result.data[key] = val * other.data.at(key);
    }
    for (auto& [key, _] : result.data)
        result.elements.push_back(key);

    result.indices = indices;
    for (auto& [k, v] : other.indices)
        result.indices[k] = v;

    
    return result;
}

//10. and 11.--------------------------------------------------
Multiset Multiset::ArithDiff(const Multiset& other) const {
    Multiset result;
    for (auto& [key, val] : data) {
        int diff = val - (other.data.count(key) ? other.data.at(key) : 0);
        result.data[key] = diff;
    }
    for (auto& [key, _] : result.data)
        result.elements.push_back(key);

    result.indices = indices;
    for (auto& [k, v] : other.indices)
        result.indices[k] = v;
    
    
    return result;
}

//12.--------------------------------------------------
Multiset Multiset::ArithDiv(const Multiset& other) const {
    Multiset result;
    for (auto& [key, val] : data) {
        if (other.data.count(key) && other.data.at(key) != 0)
            result.data[key] = val / other.data.at(key);
    }
    for (auto& [key, _] : result.data)
        result.elements.push_back(key);
    
    result.indices = indices;
    for (auto& [k, v] : other.indices)
        result.indices[k] = v;
        
    return result;
}

//--------------------------------------------------
// Print multiset in formatted style
//--------------------------------------------------
void Multiset::print(const string& title, bool showHeader) const {
    if (showHeader)
        cout << "----------------------------------------" << endl;

    cout << title << endl;

    if (data.empty()) {
        cout << "(empty set)" << endl;
    } else {
        for (const auto& e : elements) {
            int idx = (indices.count(e) ? indices.at(e) : -1);
            cout << "     " << setw(4) << e
                 << "  [" << setw(2);
            if (idx != -1)
                cout << idx;
            else
                cout << "--";
            cout << "] :  " << data.at(e) << endl;
        }
    }

    if (showHeader)
        cout << "----------------------------------------" << endl;
}