#include<bits/stdc++.h>
using namespace std;

// Question1: Find the longest substring without repeating characters efficiently with O(n) complexity.

string s1 = "Navdeep";

void allStr(int idx,vector<string>&ans,string temp,string s){

    if(idx >= s.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(s[idx]);
    allStr(idx+1,ans,temp,s);
    temp.pop_back();

    allStr(idx+1,ans,temp,s);
}

void allSubStr(string s){
    vector<string>ans;
    string temp = "";
    allStr(0,ans,temp,s);
    for(auto i : ans) cout<<i <<" ";
}

int main(){
    allSubStr("Navdeep");
}