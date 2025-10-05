// Problem Statement
// Declare a 2-dimensional array, arr, with n empty arrays, all zero-indexed.
// Declare an integer, lastAnswer, and initialize it to 0.
// You need to process two types of queries:

// 1. Query: 1 x y
// Compute idx = (x ⊕ lastAnswer) % n.
// Append the integer y to arr[idx].

// 2. Query: 2 x y
// Compute idx = (x ⊕ lastAnswer) % n.
// Set lastAnswer = arr[idx][y % size(arr[idx])].
// Store the new value of lastAnswer in an answers array.

// Notes:
// ⊕ is the bitwise XOR operation (^ in most languages).
// % is the modulo operator.
// size(arr[idx]) is the number of elements in arr[idx].

#include<bits/stdc++.h>
using namespace std;


int longestSubstring(string s) {
    vector<int> lastIndex(256, -1); // store last seen index of each char
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        
        // If this character appeared before and is inside the window
        if (lastIndex[c] >= left) {
            left = lastIndex[c] + 1; // move left pointer after last occurrence
        }
        
        lastIndex[c] = right; // update last seen index
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}



long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 2, 0); // difference array

    // Step 1: mark ranges
    for (auto q : queries) {
        int a = q[0];
        int b = q[1];
        int k = q[2];
        arr[a] += k;
        arr[b + 1] -= k;
    }

    // Step 2: prefix sum and find max
    long maxVal = 0, curr = 0;
    for (int i = 1; i <= n; i++) {
        curr += arr[i];
        maxVal = max(maxVal, curr);
    }

    return maxVal;
}