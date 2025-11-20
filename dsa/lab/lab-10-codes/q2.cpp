#include <bits/stdc++.h>
using namespace std;

vector<int> quickSort(vector<int> arr) {

    // Base case: 0 or 1 element → already sorted
    if (arr.size() <= 1) return arr;

    int pivot = arr[arr.size() / 2];  // pick middle element as pivot

    vector<int> left;
    vector<int> equal;
    vector<int> right;

    // Partition step
    for (int x : arr) {
        if (x < pivot) left.push_back(x);
        else if (x == pivot) equal.push_back(x);
        else right.push_back(x);
    }

    // Recursively sort left and right
    vector<int> sortedLeft = quickSort(left);
    vector<int> sortedRight = quickSort(right);

    // Merge results: left + equal + right
    vector<int> result;
    result.reserve(arr.size());
    result.insert(result.end(), sortedLeft.begin(), sortedLeft.end());
    result.insert(result.end(), equal.begin(), equal.end());
    result.insert(result.end(), sortedRight.begin(), sortedRight.end());

    return result;
}

int main() {
    vector<int> arr = {3,5,2,1,7,4};

    vector<int> sortedArr = quickSort(arr);

    for (int x : sortedArr) cout << x << " ";
}
