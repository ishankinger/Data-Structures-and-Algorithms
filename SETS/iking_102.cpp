// UNORDERED SET
// THE VALUES ARE NOT IN SORTED ORDER
// AND INSERTION , DELETION AND SEARCH WILL TAKE PLACE IN O(1) TIME COMPLEXITY

#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<string>s;
    s.insert("abc");                        // IN AVERAGE CASE O(1) AND IN WORST CASE O(N)
    s.insert("xhe");
    s.insert("win");
    s.insert("abc");
    s.insert("aef");
    s.insert("win");
    for(auto val:s) cout<<val<<"\n";

    return 0;
}