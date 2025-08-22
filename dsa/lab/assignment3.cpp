#include<bits/stdc++.h>
using namespace std;

// Question1: Find the longest substring without repeating characters efficiently with O(n) complexity.
// string s1 = "Navdeep";
// void allStr(int idx,vector<string>&ans,string temp,string s){

//     if(idx >= s.size()){
//         ans.push_back(temp);
//         return;
//     }
//     temp.push_back(s[idx]);
//     allStr(idx+1,ans,temp,s);
//     temp.pop_back();

//     allStr(idx+1,ans,temp,s);
// }

// void allSubStr(string s){
//     vector<string>ans;
//     string temp = "";
//     allStr(0,ans,temp,s);
//     for(auto i : ans) cout<<i <<" ";
// }

// int main(){
//     allSubStr("Navdeep");
// }




// roatate aaray k times


// using 0n and 0n simple using temp array
void rotateKtimes2(vector<int>&nums,int k,vector<int>&temp){
    for(int i=0; i<nums.size(); i++){   //0n 
        temp[(i+k) % nums.size()] = nums[i];
    }
}   


// Brute force about n square and constant
void rotateKtimes1(vector<int>&nums,int k){
    int n = nums.size();
    for(int i=0; i<k; i++){
        //pickup last elem
        int last = nums[n-1];
        // shift all elems by 1 place
        for(int l=n-1; l>0; l--){
            nums[l] = nums[l-1];
        }
        nums[0] = last;
    }
}


int main1(){
    vector<int>nums = {1,2,3,4,5};
    vector<int>temp(nums.size());
    int k = 7;
    k = k%nums.size(); // if 5 times rotate than orignal array back
    // rotateKtimes1(nums,k);
    rotateKtimes2(nums,k,temp);
    for(auto i : temp) cout<<i <<" ";
}



// Question 2: Count Special Pairs in an Array
// Alice, an aspiring cryptographer, recently discovered an ancient scroll containing a sequence of mysterious numbers. According to legend, these numbers hold the key to unlocking a hidden treasure buried centuries ago by an enigmatic mathematician. However, deciphering the scroll requires identifying specific pairs of numbers that follow an ancient numerical pattern.
// Alice is given an array of integers nums. She wants to determine how many pairs (i, j) exist such that:

// 0≤𝑖<𝑗<nums.length0≤i<j<nums.length
// The sum of digits of nums[i] is equal to the sum of digits of nums[j].
// Your task is to help Alice compute this number so she can continue her quest.
// Task
// Return the number of special pairs that satisfy the conditions above.
// Input Format
// The first line contains a single integer N (size of the array).
// The second line contains N space-separated integers representing the array nums.
// Output Format
// A single integer representing the number of valid pairs.
// Example 1

// Input:
// 4
// 51 71 17 42
// Output:
// 2

// Explanation:
// Sum of digits for each number:

// 51 → 5 + 1 = 6
// 71 → 7 + 1 = 8
// 17 → 1 + 7 = 8
// 42 → 4 + 2 = 6

// Valid pairs:
// (1,4) → 51 & 42 (sum = 6)
// (2,3) → 71 & 17 (sum = 8)
// Total pairs = 2
// Example 2
// Input:

// 5
// 23 32 14 41 50
// Output:
// 4
// Explanation
// Sum of digits:

// 23 → 5
// 32 → 5
// 14 → 5
// 41 → 5
// 50 → 5

// Valid pairs:
// (1,2) → 23 & 32
// (1,3) → 23 & 14
// (1,4) → 23 & 41
// (1,5) → 23 & 50
// (2,3), (2,4), (2,5), (3,4), (3,5), (4,5) → all sum = 5

// Total pairs = 10

// (For large arrays, only count the number of valid pairs where i < j.)
// Complexity Analysis
// Naive approach: Compare each pair → 
// 𝑂(𝑁2)O(N2)time
// Optimized approach: Use a hashmap to count frequencies of digit sums → 
// 𝑂(𝑁⋅𝐷)O(N⋅D) where D is number of digits per number


int sum(int num){
    int total = 0;
    while(num > 0){
        total += num % 10;
        num /= 10;
    }
    return total;
}

int countSpecialPairs1(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for(int i = 0; i < n; ++i) {
        int sumI = sum(nums[i]);
        for(int j = i+1; j < n; ++j) {
            int sumJ = sum(nums[j]);
            if(sumI == sumJ) count++;
        }
    }
    return count;
}

int countSpecialPairs2(vector<int>&nums){
    int n = nums.size();
    int ans = 0;
    unordered_map<int,int>freq;
    for(int i=0; i<n; i++){
        int total = sum(nums[i]);
        freq[total]++;
    }
    for(auto f : freq){
        int frequency = f.second;
        if(frequency > 1) ans += frequency*(frequency-1)/2;
    }
    return ans;
}

int main2(){
    vector<int>nums = {23,32,14,41,50};
    cout<<countSpecialPairs2(nums);
}



int main(){
    // main1();
    main2();
}














// int countSpecialPairs(const vector<int>& nums) {
//     unordered_map<int, int> freq;
//     // Count frequency of each digit sum
//     for (int num : nums) {
//         int s = digitSum(num);
//         freq[s]++;
//     }
//     // Calculate number of valid pairs for each digit sum
//     int totalPairs = 0;
//     for (auto p : freq) {
//         int f = p.second;
//         if (f > 1)
//             totalPairs += f * (f - 1) / 2;
//     }
//     return totalPairs;
// }
