// incomplete
// g++ -std=c++11 -o design_hashset design_hashset.cpp
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std; 

class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> hashset; 
    
    MyHashSet() {
    }
    
    void add(int key) {
        cout << "\nadding " << key << endl;
        int e = hashset.size(); 

        if (e == 0) {
            hashset.push_back(key);
        } else {
            vector<int> res = binarySearch(0, e, key);

            // key not in set 
            if (res[0] == -1) {

                // insert position
                int pos = res[1];

                if (pos == e-1) {
                    shiftRight(res[1]);
                    hashset[pos] = key; 
                } else {
                    hashset.push_back(key); 
                }
            } 
        }
        printHS();
    }
    
    void remove(int key) {
        cout << "\nremoving key " << key << endl;
        int e = hashset.size(); 
        
        if (e == 0) {
            return; 
        }

        vector<int> res = binarySearch(0, e, key); 
        if (res[0] == 1) {
            // found item in hash set
            int pos = res[1]; 
            shiftLeft(pos); 
        }

        printHS(); 
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int e = hashset.size(); 
        vector<int> res = binarySearch(0, e, key); 
        return res[0] == 1;
    }

    void printHS() {
        for (int i = 0; i < hashset.size(); i++) {
            cout << hashset[i] << " "; 
        }
        cout << endl;
    }

private:
    vector<int> binarySearch(int s, int e, int target) {
        vector<int> res = {-1, 2};
        int m;

        while (s <= e) {
            m = s + (e - s) / 2; 
            if (target > hashset[m])
                s = m + 1; 
            else if (target < hashset[m])
                e = m - 1;
            else 
                return {1, m};
        }

        return {-1,m}; 
    }
    
    void shiftRight(int pos) {
        int e = hashset.size(); 
        hashset.resize(e+1); 

        for (int i = e-1; i >= pos; i--) 
            hashset[i+1] = hashset[i];

        printHS();
    }
    
    void shiftLeft(int pos) {
        int e = hashset.size(); 
        for (int i = pos; i < e - 1; i++)
            hashset[i] = hashset[i+1];

        hashset.resize(e-1); 

        printHS(); 
    }
};

int main() {
    MyHashSet *hs = new MyHashSet(); 
    hs->add(1); 
    hs->add(2); 
    hs->add(4);
    hs->add(3); 
    hs->add(4); 

    cout << hs->contains(3) << endl;
    cout << hs->contains(10) << endl; 
    hs->remove(3); 
    hs->remove(4); 

    hs->add(3); 
    hs->add(4);

    return 0;
}