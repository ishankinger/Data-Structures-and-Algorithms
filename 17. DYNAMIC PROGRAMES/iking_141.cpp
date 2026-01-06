// BOOLEAN EVALUATION TO TRUE

#include<bits/stdc++.h>
using namespace std;

bool f(int i, int j, string s, int &count){
    if(i == j){
        if(s[i] == 'T') return true;
        else return false;
    }
    for(int k = i+1; k <= j-1; k += 2){
        bool part1 = f(i,k-1,s,count);
        bool part2 = f(k+1,j,s,count);
        bool ans;
        if(s[k] == '^') ans = part1 ^ part2;
        else if(s[k] == '|') ans = part1 | part2;
        else ans = part1 & part2;
        if(i == 0 and j == s.size()-1){
            if(ans) count++;
        }
        else return ans;
    }
}

int main(){
    string s;
    cin >> s;
    int count = 0;
    f(0,s.size()-1,s,count);
    cout << count << "\n";
    return 0;
}