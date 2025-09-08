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

 