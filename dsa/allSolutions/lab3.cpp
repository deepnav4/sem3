#include<bits/stdc++.h>
using namespace std;

// Function to count occurrences of queries in strList
vector<int> noOfStr(vector<string> strList, vector<string> queries) {
    unordered_map<string,int> freq;

    // Build frequency map
    for(auto &str : strList) {
        freq[str]++;
    }

    // Answer queries
    vector<int> result;
    for(auto &q : queries) {
        result.push_back(freq[q]); // if q not found, returns 0
    }

    return result;
}



// hackerRank problem array manuplation
int arrayManipulation(int n, vector<vector<int>> manipulations) {
    vector<long long> arr(n + 2, 0);  // long long to avoid overflow

    for (auto m : manipulations) {
        int startIdx = m[0];
        int endIdx = m[1];
        int val = m[2];

        arr[startIdx] += val;     // add value at start
        arr[endIdx + 1] -= val;   // subtract value after end
    }

    // Build prefix sum and track maximum
    long long maxVal = 0, curr = 0;
    for (int i = 1; i <= n; i++) {
        curr += arr[i];   // prefix sum
        maxVal = max(maxVal, curr);
    }

    return (int)maxVal;
}


// longest substring without repeating chracters
vector<string>allSubStr(string s){
    unordered_map<char,int>freq;
    vector<string>ans;
    for(int i=0; i<s.size(); i++){
        string sub = "";
        for(int j=i; j<s.size() ;j++){
            freq[s[j]]++;
            if(freq[s[j]] > 1) break;
            sub += s[j];
            ans.push_back(sub);
        }
    }
    return ans;
}

int main(){
    string s = "abcda";
    vector<string>ans = allSubStr(s);
    for(auto s : ans) cout<<s<<" ";
}

int main1() {
    vector<string> strList = {"ab", "ab", "abc"};
    vector<string> queries = {"ab", "abc", "bc"};

    vector<int> ans = noOfStr(strList, queries);

    // Print results
    for(int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
