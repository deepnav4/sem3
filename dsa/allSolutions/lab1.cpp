#include<bits/stdc++.h>
using namespace std;


// Given a string s, sort it in decreasing order based on the frequency of the characters.
// The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

// Example 1:
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'.
// Therefore "eetr" is also a valid answer.




// Problem
// A new deadly virus has infected a large population of a planet.
// A brilliant scientist has discovered a new strain of virus which can cure this disease.

// Vaccine produced from this virus has various strengths depending on midichlorians count.
// A person is cured only if the midichlorians count in the vaccine batch is greater than the midichlorians count of the person.

// A doctor receives a report containing the midichlorians count of each infected patient.
// Practo stores all the vaccines the doctor has along with their midichlorians count.

// You need to determine if the doctor can save all patients with the vaccines he has.
// The number of vaccines and patients are equal.

// Input Format
// First line contains the number of vaccines N.
// Second line contains N integers → the strengths of vaccines.
// Third line contains N integers → the midichlorians count of patients.

// Output Format
// Print a single line containing "Yes" if all patients can be cured, otherwise print "No".

void freqSort(string s,string &ans){
    unordered_map<char,int>mp;
    for(auto ch : s) mp[ch]++;

    priority_queue<pair<char,int>>pq;
    for(auto f : mp) pq.push({f.second,f.first});

    while(!pq.empty()){
        char ch = pq.top().second;
        int freq = pq.top().first;
        pq.pop();
        while(freq--) ans.push_back(ch);
    }
}

void dnf(vector<int>&arr){
    int start = 0;
    int mid = 0;
    int end = arr.size();
    while(mid<end){
        if(arr[mid] == 0){
            swap(arr[start],arr[mid]);
            start++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else {
            swap(arr[mid],arr[end]);
            end--;
        }
    }
}

int main(){
    string s = "tree";
    string ans = "";
    freqSort(s,ans);
    cout<<ans;
}