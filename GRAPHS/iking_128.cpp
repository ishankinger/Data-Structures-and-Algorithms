// WORLD LADDER 

#include<bits/stdc++.h>
using namespace std;

int numOfSteps(vector<string> wordList, string beginWord, string targetWord){
    
    set<string> s;
    for(int i = 0; i < wordList.size(); i++){
        s.insert(wordList[i]);
    }

    queue< pair<string,int> > q;
    q.push({beginWord,1});
    s.erase(beginWord);
    string duplicate;
    while(not q.empty() && q.front().first != targetWord){
        string word = q.front().first;
        int level = q.front().second;
        q.pop();
        for(int i = 0; i < word.size(); i++){
            for(int j = 0; j <= 26; j++){
                duplicate = word;
                duplicate[i] = j + 'a';
                if(s.count(duplicate)){
                    q.push({duplicate,level+1});
                    s.erase(duplicate);
                }
            }
        }
    }

    if(not q.empty()){
        return q.front().second;
    }
    else{
        return 0;
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> wordList;
    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        wordList.push_back(word);
    }
    string beginWord;
    cin >> beginWord;
    string targetWord;
    cin >> targetWord;

    cout << numOfSteps(wordList,beginWord,targetWord);

    return 0;
}