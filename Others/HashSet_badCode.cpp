//INEFFICIENT - (Memory Usage - wise efficient)
#include <vector>
#include <algorithm>
#include <iostream>

class MyHashSet {
public:
    vector <int> hashset;
    MyHashSet() {
    }
     
    void add(int key) {
        for (int i=0; i<hashset.size(); i++){
            if (hashset[i]==key) return;
        }
        hashset.push_back(key);
    }
    
    void remove(int key) {
        hashset.erase(std::remove(hashset.begin(), hashset.end(), key), hashset.end());
    }
    
    bool contains(int key) {
        for (int i=0; i<hashset.size(); i++){
            if (hashset[i]==key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

////////////////////////////////////////////////////////////////////////////////////////////////

//EFFICIENT
#include <vector>
#include <list>
using namespace std;

class MyHashSet {
private:
    static const int SIZE = 769;
    vector<list<int>> table;

    int hash(int key) const {
        return key % SIZE;
    }

public:
    MyHashSet() : table(SIZE) {}

    void add(int key) {
        int index = hash(key);
        for (const int &val : table[index])
            if (val == key) return;
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hash(key);
        table[index].remove(key);
    }

    bool contains(int key) const {
        int index = hash(key);
        for (const int &val : table[index])
            if (val == key) return true;
        return false;
    }
};
