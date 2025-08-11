#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=1; i<n; i++){
        int min = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] > min){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = min;
    }
}

vector<int>mergeTwoSortedArray(vector<int>&arr1,vector<int>&arr2){
    int i = 0;
    int j = 0;
    int k = 0;
    int size1 = arr1.size();
    int size2 = arr2.size();
    vector<int>arr3(size1+size2);
    while(i<size1 && j<size2){
        if(arr1[i] < arr2[j]) arr3[k++] = arr1[i++];
        else arr3[k++] = arr2[j++];
    }
    while(i<size1) arr3[k++] = arr1[i++];
    while(j<size2) arr3[k++] = arr2[j++];
    return arr3;
}

vector<int> mergeSort(vector<int>&arr,int start,int end){
    int mid = (start+end)/2;
    if(start<=end) return {arr[start]};
    vector<int>arr1 = mergeSort(arr,start,mid);
    vector<int>arr2 = mergeSort(arr,mid+1,end);
    return mergeTwoSortedArray(arr1,arr2);
}

// sort array of 0s 1s 2s 
// basic approach count no of 0s 1s 2s basically and add in arr
// good approach 0n is DNF 3 pointer

void countAndArrangeInArray(vector<int>& arr) {
    int cntZero = 0, cntOne = 0, cntTwo = 0;
    for (int i : arr) {
        if (i == 0) cntZero++;
        else if (i == 1) cntOne++;
        else if (i == 2) cntTwo++;
    }
    int i = 0;
    while (cntZero--) arr[i++] = 0;
    while (cntOne--) arr[i++] = 1;
    while (cntTwo--) arr[i++] = 2;
}

void printArr(vector<int>arr){
    for(auto i : arr) cout<<i <<" ";
    cout<<endl;
}
// 3 pointers
void dnfAlgo(vector<int>&arr){
    int start = 0;
    int mid = 0;
    int end = arr.size()-1;
    while(mid<=end){
        if(arr[mid] == 0){
            swap(arr[start],arr[mid]);
            printArr(arr);
            start++;
            mid++;
        }
        else if(arr[mid] == 1){
            printArr(arr);
            mid++;
        }
        else{
            swap(arr[mid],arr[end]);
            printArr(arr);
            end--;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the numeber of the objects : ";
    cin>>n;
    vector<int>arr(n);
    // take input as color please verify also
    cout<<"Enter the objects color 0(Red) , 1(White) and 2(Blue) only : \n";
    for(int i=0; i<n; i++){
        cout<<"Enter " <<i+1 <<" th object out of "<<n <<" : ";
        cin>>arr[i];
        if(arr[i] < 0 || arr[i] > 2){
            cout<<"Invalid input! Please enter 0, 1, or 2 only.\n";
            return 1; 
        }
    }
    bubbleSort(arr);
    // selectionSort(arr);
    // insertionSort(arr);
    // countAndArrangeInArray(arr);
    // dnfAlgo(arr);
    // vector<int>mergeSortAns = mergeSort(arr,0,arr.size()-1);
    cout<<"Your sorted array of object is : \n";
    for(auto i : arr) cout<<i <<" ";
}