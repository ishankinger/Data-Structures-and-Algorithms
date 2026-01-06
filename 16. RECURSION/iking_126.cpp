// COMBINATION SUM

#include<bits/stdc++.h>
using namespace std;

void allCombinations(int index,vector<int> candidate, int target, 
    vector<int> combination, vector< vector<int> > &ans){

        if(index == candidate.size()){
            if(target == 0){
                ans.push_back(combination);
            }
            return;
        }
        if(target >= candidate[index]){
            combination.push_back(candidate[index]);
            allCombinations(index,candidate,target-candidate[index],combination,ans);
            combination.pop_back();
        }
        allCombinations(index+1,candidate,target,combination,ans);
    }

void allCombinations_mine(int index,vector<int> candidate, int target, 
    vector<int> combination, vector< vector<int> > &ans){

        if(target < 0){
            return;
        }
        if(target == 0){
            ans.push_back(combination);
            return;
        }
        for(int i = index; i < candidate.size(); i++){
            target -= candidate[i];
            combination.push_back(candidate[i]);
            allCombinations_mine(i,candidate,target,combination,ans);
            target += candidate[i];
            combination.pop_back();
        }
    }

    void allCombinations_pickOnce_Unique(int index,vector<int> candidate, int target, 
    vector<int> combination, vector< vector<int> > &ans){
        if(target == 0){
            ans.push_back(combination);
            return;
        }
        for(int i = index; i < candidate.size(); i++){
            if(i > index and candidate[i] == candidate[i-1]) continue;
            if(candidate[i] > target) break;
            target -= candidate[i];
            combination.push_back(candidate[i]);
            allCombinations_pickOnce_Unique(i+1,candidate,target,combination,ans);
            target += candidate[i];
            combination.pop_back();
        }
    }


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> combination;
    vector< vector<int> > ans;
    int index = 0;
    allCombinations(index,candidates,target,combination,ans);
    sort(candidates.begin(),candidates.end());
    return ans;
}