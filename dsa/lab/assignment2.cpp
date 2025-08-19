#include<bits/stdc++.h>
using namespace std;



// row major
int addUsingRowMajor(int i, int j, int noOfCols, int baseAddress, int rowLB = 0, int colLB = 0) {
    int sizeOfElement = 4; 
    return baseAddress + ((i - rowLB) * noOfCols + (j - colLB)) * sizeOfElement;
}

int addUsingColMajor(int i, int j, int noOfRows, int baseAddress, int rowLB = 0, int colLB = 0) {
    int sizeOfElement = 4; 
    return baseAddress + ((j - colLB) * noOfRows + (i - rowLB)) * sizeOfElement;
}


void printMatrix(vector<int>& arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<arr[i * n + j]<<" ";
        }
        cout<<endl;
    }
}

pair<int,int>findElement(vector<int>arr,int elem){
    int n = sqrt(arr.size());
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i * n + j] == elem) {
                return {i, j}; 
            }
        }
    }
    return {-1, -1};
}

int main1(){
    int size,baseAddress;
    cout<<"Enter Number of Elements in the array : ";
    cin>>size;
    cout<<"Enter the Base Address : ";
    cin>>baseAddress;
    vector<int>arr(size);
    cout<<"Enter the Elements of the array : ";
    for(int i=0; i<size; i++) cin>>arr[i];
    // your n*n array means needed to aapend zero check current size of the arry and nearest n*n 
    int n = ceil(sqrt(size));
    arr.resize(n*n, 0);

    printMatrix(arr, n);
    // if user also enters number to get that particular address (but but this fails when he enters zeros !!!)
    // then simple using n^2 find element and then store its i and j

    int elemI = 0, elemJ = 0;
    int elem;
    cout<<"Enter Element to find its Address : ";
    cin>>elem;
    pair<int,int> pos = findElement(arr, elem);
    elemI = pos.first;
    elemJ = pos.second;

    // add logic to take lower bound  ask user if wants to enter then yes else by defaulty steed as 0
    int rowLB = 0, colLB = 0;
    cout<<"Enter Lower Bound of Row (default 0) : ";
    cin>>rowLB;
    cout<<"Enter Lower Bound of Column (default 0) : ";
    cin>>colLB;

    // to print address to complete matrix
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         int addressRowMajor = addUsingRowMajor(i, j, n, baseAddress, rowLB, colLB);
    //         int addressColMajor = addUsingColMajor(i, j, n, baseAddress, rowLB, colLB);
    //         cout<<"Address of element at ("<<i<<","<<j<<") in Row Major Order : "<<addressRowMajor<<endl;
    //         cout<<"Address of element at ("<<i<<","<<j<<") in Column Major Order : "<<addressColMajor<<endl;
    //         cout<<endl;
    //     }
    // }


    // to print address to particular matrix
    if(elemI != -1 && elemJ != -1) {
        int addressRowMajor = addUsingRowMajor(elemI, elemJ, n, baseAddress, rowLB, colLB);
        int addressColMajor = addUsingColMajor(elemI, elemJ, n, baseAddress, rowLB, colLB);
        cout<<"Address of element at ("<<elemI<<","<<elemJ<<") in Row Major Order : "<<addressRowMajor<<endl;
        cout<<"Address of element at ("<<elemI<<","<<elemJ<<") in Column Major Order : "<<addressColMajor<<endl;
    } else {
        cout<<"Element not found in the array.";
    }
}




// Q1. Take an input from the user in form of 1D array. Convert the given array in nxn form. If the items are lesser than nxn then insert '0' in the last left elements. Now based on the user input element and base address, determine the row major and column major address.




bool isOrderCorrect(vector<int>order){
    int i = 0;
    while(i < order.size() - 1){
        if(order[i] > order[i + 1]) return false;
        i++;
    }
    return true;
}

int main2(){
    // basically take input of solving levels by student order by which problems in solved
    // ausmme as numbers from 1 to INT_MAX;
    int questions;
    cout<<"Enter Number of Questions solved by Student : ";
    cin>>questions;
    vector<int>order(questions);
    cout<<"Enter Difficulty level of questions from 1 to INT_MAX that you solved : \n";
    for(int i=0; i<questions; i++){
        cout<<"Enter difficulty level of "<<i+1 <<" question : ";
        cin>>order[i];
    }
    if(isOrderCorrect(order)) cout<<"Student Solved question in correct order.";
    else cout<<"Student Solved Question in Wrong order.";
}



// (Group 3)
// A company has some interns under a project. In his coding class, who are practicing problems. Given the difficulty of the problems that the students have solved in order, help the Chef identify if they are solving them in non-decreasing order of difficulty.
// Non-decreasing means that the values in an array are either increasing or remaining the same, but not decreasing. That is, the students should not solve a problem with difficulty d1, and then later a problem with difficulty d2, where d1 > d2.
// Output "Yes" if the problems are attempted in non-decreasing order of difficulty rating and "No" if not.














void uniqueQuad(int idx, vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& temp) {
    if(temp.size() == 4) {
        if(target == 0) {
            // only push if this combination is not already in ans
            // if(find(ans.begin(), ans.end(), temp) == ans.end()) {
                ans.push_back(temp);
            // }
        }
        return;
    }
    if(idx >= nums.size()) return;

    // Take current number
    temp.push_back(nums[idx]);
    uniqueQuad(idx+1, nums, target - nums[idx], ans, temp);
    temp.pop_back();

    // Do not take current number
    uniqueQuad(idx+1, nums, target, ans, temp);
}

int main3() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> ans;
    vector<int> temp;

    uniqueQuad(0, nums, target, ans, temp);

    for(auto &v : ans){
        for(int x : v) cout << x << " ";
        cout << endl;
    }
    return 0;
}




int main(){
    // main2();
    main3();
    // main1();
}