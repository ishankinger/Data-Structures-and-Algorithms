// HASHING BASIC IMPLEMENTATION

#include<bits/stdc++.h>
using namespace std;

class Hashing{
    vector<list<int>>hashtable;
    int buckets;

    Hashing(int bucket){
        bucket=buckets;
        hashtable.resize(bucket);
    }

    int hashValue(int key){
        return key%buckets;
    }

    void add(int key){
        int idx = hashValue(key);
        hashtable[idx].push_back(key);
    }

    list<int>::iterator search(int key){
        int idx = hashValue(key);
        return find(hashtable[idx].begin(),hashtable[idx].end(),key);
    }
    
    void deleteKey(int key){
        int idx = hashValue(key);
        hashtable[idx].erase(search(key));
    }
};

int main(){

    return 0;
}