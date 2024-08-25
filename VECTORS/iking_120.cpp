// ********* GIVEN A SORTED ARRAY OF INTEGERS, RETURN SORTED ARRAY OF SQUARE OF INTEGERS ***********

#include<bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ans;
    int front = 0, back = nums.size()-1;
    while(front <= back){
        if(abs(nums[front]) > abs(nums[back])){
            ans.push_back(nums[front]*nums[front]);
            front++;
        }
        else{
            ans.push_back(nums[back]*nums[back]);
            back--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int>v;
    v={-9,-5,3,6,7};
    int p1=0,p2=v.size()-1;
    while(p1<p2){
        if(abs(v[p1])>abs(v[p2])){                        // WE ARE ALWAYS COMPARING THE FIRST ELEMENT WITH THE LAST UNCOMPARED ELEMENTS
            v.insert(v.begin()+p2+1,abs(v[p1]));          // IF IT'S ABSOLUTE VALUE IS GREATER THEN WE WILL ADD IT TO THE BACK
            v.erase(v.begin()+p1);                        // ERASE FROM THE INITIAL POSITION
            p2--;                                         // AND NOW BY DOING P2-- WE ARE ACTUALLY MOVING POINTER TO UNCOMPARED ELEMENTS
        }else{
            p2--;                                         // ELSE NOTHING JUST MOVE P2 POINTER TO BACK
        }
    }
    for(int i=0;i<v.size();i++) cout<<v[i]*v[i]<<" ";
    return 0;
}
