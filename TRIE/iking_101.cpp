#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* child[26];
    int wordCount;
    int prefixCount;
};

class Trie{
private:
    TrieNode* root;
public:
    Trie();
    void insertKey(string key);
    bool searchKey(string key);
    bool searchPrefix(string key);
    int countKeys(string key);
    int countPrefixes(string key);
    void earseKey(string key);
    bool deleteKey(string key);
};

Trie :: Trie(){
    root = new TrieNode();
    for(int i = 0; i < 26; i++) root->child[i] = NULL;
    root->wordCount = 0;
    root->prefixCount = 0;
}

void Trie :: insertKey(string key){
    TrieNode* curr = root;
    for(char c : key){
        if(curr->child[c-'a'] == NULL){
            TrieNode* newNode  = new TrieNode();
            curr->child[c-'a'] = newNode;
        }
        curr = curr->child[c-'a'];
        curr->prefixCount++;
    }
    curr->wordCount++;
}

bool Trie :: searchKey(string key){
    TrieNode* curr = root;
    for(char c : key){
        if(curr->child[c-'a'] == NULL){
            return false;
        }
        curr = curr->child[c-'a'];
    }
    return curr->wordCount;
}

bool Trie :: searchPrefix(string key){
    TrieNode* curr = root;
    for(char c : key){
        if(curr->child[c-'a'] == NULL){
            return false;
        }
        curr = curr->child[c-'a'];
    }
    return true;
}

int Trie :: countKeys(string key){
    TrieNode* curr = root;
    for(char c : key){
        if(curr->child[c-'a'] == NULL){
            return 0;
        }
        curr = curr->child[c-'a'];
    }
    return curr->wordCount;
}

int Trie :: countPrefixes(string key){
    TrieNode* curr = root;
    for(char c : key){
        if(curr->child[c-'a'] == NULL){
            return 0;
        }
        curr = curr->child[c-'a'];
    }
    return curr->prefixCount;
}

void Trie :: earseKey(string key){
    TrieNode* curr = root;
    for(char c : key){
        if(curr->child[c-'a'] == NULL){
            printf("Word Not found\n");
            return;
        }
        curr = curr->child[c-'a'];
        curr->prefixCount--;
    }
    curr->wordCount--;
}

bool Trie :: deleteKey(string key){
    TrieNode* curr = root;
    TrieNode* lastBranch = NULL;
    char lastBranchChar = 'a';
    for(auto c : key){
        if(curr->child[c-'a'] == NULL){
            printf("Word Not found\n");
            return false;
        }
        else{
            int count = 0;
            for(int i = 0; i < 26; i++){
                if(curr->child[i] != NULL) count++;
            }
            if(count > 1){
                lastBranch = curr;
                lastBranchChar = c;
            }
            curr = curr->child[c-'a'];
            curr->prefixCount--;
        }
    }

    int count = 0;
    for(int i = 0; i < 26; i++){
        if(curr->child[i] != NULL) count++;
    }

    // the deleted word is prefix of other words
    if(count > 0){
        curr->wordCount--;
        return true;
    }

    // the deleted word shares a common prefix with other words
    if(lastBranch != NULL){
        lastBranch->child[lastBranchChar] = NULL;
        return true;
    }

    // the deleted word doesnot share any prefix with other word
    else{
        root->child[key[0]] = NULL;
        return true;
    }

}

int main(){

    Trie* root = new Trie();
    vector<string> arr = {"and", "bal", "do", "balle", "dad", "ball", "ball"};

    for (const string& s : arr) {
        root->insertKey(s);
    }

    vector<string> searchKeys = {"do", "gee", "bat"};
    for (string& s : searchKeys) {
        cout << "Key : " << s << "\n";
        if (root->searchKey(s)) 
            cout << "Present\n";
        else 
            cout << "Not Present\n";        
    }

    cout << root->countKeys("ball") << "\n";
    cout << root->countPrefixes("bal") << "\n";
    root->earseKey("ball");
    root->earseKey("ball");
    root->earseKey("ball");
    cout << root->countPrefixes("bal") << "\n";
    cout << root->searchKey("ball") << "\n";
    cout << root->countKeys("ball") << "\n";

    cout << "\n";

    cout << root->countKeys("do") << "\n";
    root->earseKey("do");
    cout << root->searchKey("do") << "\n";
    cout << root->countKeys("do") << "\n";

    cout << "\n";

    cout << root->countKeys("and") << "\n";
    root->earseKey("and");
    cout << root->searchKey("and") << "\n";
    cout << root->countKeys("and") << "\n";
  
    return 0;
}