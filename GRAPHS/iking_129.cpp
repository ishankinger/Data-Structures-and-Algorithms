// WORLD LADDER - 2
// WE HAVE TO RETURN ALL THE POSSIBLE SHORTEST TRANSFORMATIONS POSSIBLE FROM START_WORD TO END_WORD
// TILL ALL SEQUENCES FROM ONE LEVEL ARE NOT DONE, DONOT ERASE ANY WORD FROM THE SET ( POSSIBILITY THAT DIFFERENT SEQUENCE CAN BE FORMED FROM THAT WORD )
// WHEN ALL SEQUENCES FROM ONE LEVEL ARE DONE THEN ERASE ALL THE WORDS FROM THE SET THAT ARE ADDED TO DIFFERENT SEQUENCES


#include<bits/stdc++.h>
using namespace std;

vector< vector<string> > wordSequences(vector<string> wordList, string beginWord, string targetWord){
    
    // final ans vector containing different sequences
    vector< vector<string> > ans;

    // all the words in the word List are pushed into the set
    set<string> st(wordList.begin(),wordList.end());

    // a queue is defined which contains the array of words ( sub sequence which may form possible transformation )
    queue< vector<string> > q;
    q.push({beginWord});

    // vector storing the words used in particular level to form different sequences
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);

    // keeping the track of the level
    int level = 0;
    
    // traversing in the queue
    while(not q.empty()){

        // get the front sequence of the queue
        vector<string> vec = q.front();
        q.pop();

        // if vector size is greater than level then level++ and erase all words used on prev level
        if(vec.size() > level){
            level++;
            for(auto it : usedOnLevel){
                st.erase(it);
            }
        }

        // if we get the final word from any sequence then we will push in final ans
        string word = vec.back();
        if(word == targetWord){

            // if this sequence is the first one then it will be the shortest so directly pushed in
            if(ans.size() == 0){
                ans.push_back(vec);
            }

            // any other sequence should have size equal to first one to be shortest transformation sequence
            else if(ans[0].size() == vec.size()){
                ans.push_back(vec);
            }
        }

        // for each character of the word check all possibilities
        for(int i = 0; i < word.size(); i++){
            char original = word[i];
            for(char c = 'a'; c <= 'z'; c++){
                word[i] = c;
                // if word found in word list then push new sequence into the queue
                if(st.count(word)){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }

    return ans;
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

    vector< vector<string> > ansSeqs = wordSequences(wordList,beginWord,targetWord);
    for(int i = 0; i < ansSeqs.size(); i++){
        for(int j = 0; j < ansSeqs[i].size(); j++){
            cout << ansSeqs[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
