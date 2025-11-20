#include<bits/stdc++.h>
using namespace std;

// merge sort
// quick sort

// 1. Write a program to implement merge sort.
// 2. Write a program to implement quick sort.
// 3. You are given an array of k linked-lists lists, each linked-list is sorted in ascending order. Merge all linked lists into one sorted linked list and return it.



vector<int> mergeTwoSortedArrays(vector<int>& left, vector<int>& right) {
    int size1 = left.size();
    int size2 = right.size();
    vector<int> arr(size1 + size2);
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < size1 && j < size2) {
        if(left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }

    while(i < size1) arr[k++] = left[i++];
    while(j < size2) arr[k++] = right[j++];

    return arr;
}

vector<int> mergeSort(vector<int>& arr, int left, int right) {
    if(left == right) return {arr[left]};
    int mid = (left + right) / 2;
    vector<int> leftPart  = mergeSort(arr, left, mid);
    vector<int> rightPart = mergeSort(arr, mid + 1, right);
    return mergeTwoSortedArrays(leftPart, rightPart);
}



int main() {
    vector<int> arr = {3,5,2,1,7,4};

    vector<int> sortedArr = mergeSort(arr, 0, arr.size() - 1);

    for(int x : sortedArr) cout << x << " ";
}
