#include<bits/stdc++.h>
using namespace std;

// array insertion
// aaray deletion
// array traversing
// linear search
// binary serach

void linearSearch(int arr[],int &ans,int key,int size){
    for(int i=0; i<size; i++){
        if(arr[i] == key){
            ans = i;
            break;
        }
    }
}

void binarySearch(int arr[],int &ans,int key,int size){
    int start = 0;
    int end = size-1;
    while(start<=end){
        int mid = (start + end)/2;
        if(arr[mid] == key){
            ans = mid;
            return;
        }
        else if(arr[mid] > key) end = mid-1;
        else start = mid + 1;
    }
}

void traverseArray(int arr[],int size){
    cout<<"Traversing the Array : ";
    for(int i=0; i<size; i++){
        cout<<arr[i] <<" ";
    }
    cout<<endl;
}

void insertionInArray(int arr[],int size,int elem,int position = 0){
    // store last elem
    int lastItem = arr[size-1];
    // increase the size of arr by 1
    arr[size] = lastItem;
    // shift all elems in right side
    for(int i=size-1; i>position; i--){
        arr[i] = arr[i-1];
    }
    // insert elem at position
    arr[position] = elem;
}

void deletionInArray(int arr[],int &size,int position = 0){
    // shift all elems in left side
    for(int i=position; i<size-1; i++){
        arr[i] = arr[i+1];
    }
    // decrease the size of arr by 1
    size--;
}



// search in roatated sorted array
// [4,5,6,7,0,1,2]
// int key = 6

int searchInRotatedSortedArray(int arr[],int key,int size){
    int start = 0;
    int end = size-1;
    while(start<=end){
        int mid = (start + end)/2;
        if(arr[mid] == key){
            return mid;
        }
        // check if left part is sorted or right part
        else if(arr[start] < arr[mid]){
            if(arr[start] <= key && key <= arr[mid]) end = mid-1;
            else start = mid + 1;
        }

        else{  // right part is sorted
            if(arr[mid] <= key && key <= arr[end]) start = mid + 1;
            else end = mid - 1; 
        }
    }
    return -1;
}





// complexity is 0n becouse of 1 for loop
int search(int arr[],int key,int size){  
    for(int i=0; i<size; i++){
        if(arr[i] == key) return i;
    }
    return -1;
}

int main2(){
    int arr[7] = {4,5,6,7,0,1,2};
    int size = 7;    
    int ans = -1;
    int key = 6;
    cout<<"Search in Rotated Sorted Array : ";
    cout << searchInRotatedSortedArray(arr,key,size);
}


int main1(){
    int arr[5] = {2,4,5,6,6};
    int size = 5;    
    int ans = -1;
    int key = 6;
    linearSearch(arr,ans,key,size);
    cout<<"Linear Search : "<<ans<<endl;
    binarySearch(arr,ans,key,size);
    cout<<"Binary Search : "<<ans<<endl;
    traverseArray(arr,size);
    insertionInArray(arr,size,3);
    traverseArray(arr,size);
    deletionInArray(arr,size,2);
    traverseArray(arr,size);
}

int main(){
    main2();
}



// Problem Statement
// You are given N types of blocks.
// There are A[i] blocks of type i (where 0 ≤ i ≤ N−1).
// You need to make groups of size K.
// Constraint: In any group, no type of block can appear more than ⌊K/2⌋ times.
// Your task is to find the maximum number of groups that can be formed.
// Example 1
// Input:

// N = 3
// A = [4, 3, 5]
// K = 4


// Explanation:
// Each group must have exactly 4 blocks.
// No block type can appear more than ⌊4/2⌋ = 2 times per group.
// Possible grouping:
// Group 1: [Type0, Type0, Type1, Type2]
// Group 2: [Type0, Type1, Type2, Type2]
// Group 3: [Type0, Type2, Type2, Type1]
// So we can make 3 groups.
// Output:3


// Example 2

// Input:
// N = 2
// A = [6, 2]
// K = 3

// Explanation:
// Each group must have exactly 3 blocks.
// No type can appear more than ⌊3/2⌋ = 1 time in a group.
// This means all 3 blocks in a group must be of different types.
// But we only have 2 types → impossible to form a valid group.
// Output:0