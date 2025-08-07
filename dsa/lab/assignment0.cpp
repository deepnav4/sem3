#include<bits/stdc++.h>
using namespace std;

// date 31st July 2025
// array assigment

// bubble sort
vector<int>bubbleSort(vector<int>arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
    return arr;
}


// selection sort
vector<int>selectionSort(vector<int>arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
    return arr;
}



/// merge sort
// merge two sorted arrays
vector<int> mergeTwoSortedArray(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();
    vector<int> ans(m + n);
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) ans[k++] = arr1[i++];
        else ans[k++] = arr2[j++];
    }

    while (i < m) ans[k++] = arr1[i++];
    while (j < n) ans[k++] = arr2[j++];

    return ans;
}

vector<int> mergeSort(vector<int>& arr, int start, int end) {
    if (start == end) return {arr[start]};

    int mid = start + (end - start) / 2;
    vector<int> left = mergeSort(arr, start, mid);
    vector<int> right = mergeSort(arr, mid + 1, end);
    return mergeTwoSortedArray(left, right);
}



// binary search if element not present in the array than return -1 !!
int binarySearch(vector<int>arr,int key){
    int start = 0;
    int end = arr.size()-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid] == key) return mid;
        else if(arr[mid]>key) end = mid-1;
        else start = mid+1; 
    }
    return -1;
}


int linearSearch(vector<int>arr,int target){
    for(int i=0; i<arr.size(); i++) if(arr[i] == target) return i;
    return -1;
}

int main2(){
    int n;
    cout<<"Enter size of the array  : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"\nEnter the array in sorted manner : \n";
    for(int i=0; i<n; i++){
        cout<<"Enter " <<i+1 <<"th element : ";
        cin>>arr[i];
    }
    int key;
    cout<<"Enter key to search : ";
    cin>>key;
    cout<<binarySearch(arr,key);
    // cout<<linearSearch(arr,key);
}



int main1(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cout<<"Enter the " <<i+1 <<" th element of the array : ";
        cin>>arr[i];
    }
    vector<int>ans = bubbleSort(arr);
    // vector<int>ans = selectionSort(arr);
    // vector<int>ans = mergeSort(arr,0,arr.size()-1);
    cout<<"\n Sorted Array : \n";
    for(auto i : ans){
        cout<<i <<" ";
    }
}

int main(){
    // main2();
    main1();
}