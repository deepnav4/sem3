#include<bits/stdc++.h>
using namespace std;

void allSubSeq(int idx,vector<int>arr,vector<int>&level,vector<vector<int>>&ans){
    if(idx == arr.size()) {
        ans.push_back(level);
        return;
    }
    level.push_back(arr[idx]);
    allSubSeq(idx+1,arr,level,ans);
    level.pop_back();

    allSubSeq(idx+1,arr,level,ans);
}

int main(){
    vector<int>arr = {2,3,4,2};
    vector<int>level;
    vector<vector<int>>ans;
    allSubSeq(0,arr,level,ans);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}