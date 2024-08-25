// WORLD LADDER 
// GIVEN TWO WORDS START AND END, AND WE HAVE TO GET THE MINIMUM NUMBER OF TRANSFORMATIONS NEEDED TO CONVERT START_WORD TO END_WORD
// ALL THE TRANSFORMATIONS MUST CONTAIN ONE CHARACTER TO CHANGE AND NEW WORD SHOULD BE IN THE ARRAY LIST OF WORDS WHICH IS UNIQUE
// AND RETURN 0 IF NO POSSIBLE WAY TO FIND ANY TRANSFORMATIONS

#include<bits/stdc++.h>
using namespace std;

int numOfSteps(vector<string> wordList, string beginWord, string targetWord){
    
    // all the words in the word List are pushed into the set
    set<string> s;
    for(int i = 0; i < wordList.size(); i++){
        s.insert(wordList[i]);
    }

    // a queue is defined which contains the word and level of that word
    queue< pair<string,int> > q;

    // whenever we push any word into the queue and remove it from set datastructure
    q.push({beginWord,1});
    s.erase(beginWord);

    // word formed by replacing character further used
    string duplicate;

    // traverse in the queue till we donot get element or queue becomes empty
    while(not q.empty() && q.front().first != targetWord){

        // get the front element of queue and pop it
        string word = q.front().first;
        int level = q.front().second;
        q.pop();

        // for each character of the word, check all the possibilies by replacing with 'a' to 'z'
        for(int i = 0; i < word.size(); i++){
            for(int j = 0; j <= 26; j++){

                // update the duplicate word
                duplicate = word;
                duplicate[i] = j + 'a';

                // if this word present in word list then push it in the queue and increase level by 1
                if(s.count(duplicate)){
                    q.push({duplicate,level+1});
                    s.erase(duplicate);
                }
            }
        }
    }

    // if queue not empty then front element's level will be our answer
    if(not q.empty()){
        return q.front().second;
    }
    
    // else no transformation possible so return 0
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
