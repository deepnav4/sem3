// "1. Write a C++ program that asks the user to enter three numbers. Calculates and prints
// sum of the three numbers, average of the three numbers, product of the three numbers,
#include <bits/stdc++.h>
using namespace std;

int sum(int a, int b, int c) {
    return a + b + c;
}

int product(int a, int b, int c) {
    return a * b * c;
}

int max(int a, int b, int c){
    if(a >= b && a >= c) return a;
    else if(b >= a && b >= c) return b;
    else return c;
}

int min(int a, int b, int c){
    if(a <= b && a <= c) return a;
    else if(b <= a && b <= c) return b;
    else return c;
}

int average(int a, int b, int c) {
    return (a + b + c) / 3;
}

int main1() {
    int a, b, c;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;
    cout << "Sum: " << sum(a, b, c) << endl;
    cout << "Product: " << product(a, b, c) << endl;
    cout << "Maximum: " << max(a, b, c) << endl;
    cout << "Minimum: " << min(a, b, c) << endl;
    cout << "Average: " << average(a, b, c) << endl;
    return 0;
}




// Topic: Relational Operators, Logical Operators, and Bitwise Operators
// 2. Write a program to check if a number entered by the user lies between 10 and 20
// (inclusive).
// 3. Write a program that takes two boolean inputs (0 or 1) from the user and prints the
// result of logical AND, OR, and NOT operations on these inputs.
// 4. Write a program that takes two integers and prints the result of bitwise AND, OR, XOR,
// left shift, and right shift operations.

// Ques2
bool isNumBw(int num){
    return (num>=10 && num<=20);
}

int main2(){
    int num;
    cout<<"ENter Number : ";
    if(isNumBw(num)) cout<<"Yes !";
    else cout<<"False !!";
}



// Ques 3

void boolOperations(bool a,bool b){
    cout<<"AND : " <<a&&b;
    cout<<"OR : " <<a||b;
    // Not
}

int main3(){
    bool a,b;
    cout<<"Enter two Bools : ";
    cin>>a,b;
    boolOperations(a,b);
}


// Ques4
#include <iostream>
using namespace std;

void operations(int a, int b) {
    cout << "AND : " << (a & b) << endl;
    cout << "OR  : " << (a | b) << endl;
    cout << "XOR : " << (a ^ b) << endl;
}

int main4() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;  
    operations(a, b);
    return 0;
}



// Topic: Control Statement
// 5. Write a C++ program that asks the user to enter their exam score (0 to 100) and then
// prints the grade based on the following criteria:
// i. 90 to 100: Print "Grade: A"
// ii. 80 to 89: Print "Grade: B"
// iii. 70 to 79: Print "Grade: C"
// iv. 60 to 69: Print "Grade: D"
// v. Below 60: Print "Grade: F"
// 6. Write a C++ program that asks the user to enter their age and then prints whether the person
// is:
// i. “Child” if age is less than 13
// ii. “Teenager” if age is between 13 and 19 (inclusive)
// iii. “Adult” if age is between 20 and 59 (inclusive)
// iv. “Senior” if age is 60 or older


// Ques 5
void grade(int marks){
    if(marks > 100) cout<<"Invalid Marks !";
    else if(marks >= 90 && marks <= 100)  cout<<"Grade A";
    else if(marks >= 80 && marks <= 89)  cout<<"Grade B";
    else if(marks >= 70 && marks <= 79)  cout<<"Grade C";
    else if(marks >= 60 && marks <= 69)  cout<<"Grade D";
    else  cout<<"Grade F";
}

int main5(){
    int marks;
    cout<<"Enter Your Marks : ";
    cin>>marks;
    grade(marks);
}


int ageee(int age) {
    if (age < 0) 
        cout << "Invalid age entered!" << endl;
    else if (age < 13) 
        cout << "You are a Child." << endl;
    else if (age >= 13 && age <= 19) 
        cout << "You are a Teenager." << endl;
    else if (age >= 20 && age <= 59) 
        cout << "You are an Adult." << endl;
    else 
        cout << "You are a Senior." << endl;
    return 0;
}


int main6(){
    int age;
    cout<<"Enter a Age : ";
    cin>>age;
    cout<<ageee(age);
}



// Topic: Iteration Statements
// 7. Write a program to print the first 10 natural numbers using a for loop.
// 8. Write a program that asks the user to enter a positive number and then prints all numbers
// from that number down to 1 using a while loop.
// 9. Write a program that repeatedly asks the user to enter a number until the user enters
// zero. Use a do-while loop for this.

void naturalNums(){
    for(int i=1; i<11; i++) cout<<i<<" ";
}

int main7(){
    naturalNums();
}


void printNum(int n){
    while(n!=0){
        cout<<n<<" ";
        n--;
    }
}

int main8(){
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    printNum(num);
}


int main9() {
    int n;  
    do {
        cout << "Enter a number (0 to stop): ";
        cin >> n;
    } while (n != 0); 
    cout << "You entered 0. Program terminated." << endl;
    return 0;
}



// Topic: Array
// 10. Write a C++ program to input 5 integers from the user and store them in an array and
// print all the elements of the array, sum of all elements, and maximum and minimum
// element in the array.
// 11. Write a C++ program that reads n integers and prints the frequency of each unique
// element in the array.
// 12. Write a C++ program to input two arrays of size n1 and n2 and merge them into a third
// array. Print the merged array.


#include <iostream>
#include <climits>
using namespace std;

void arrayOperations(int arr[]) {
    int sum = 0;
    int maxi = INT_MIN;
    int mini = INT_MAX;

    for (int i = 0; i < 5; i++) {
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
        sum += arr[i];
        cout << i + 1 << " element of the array: " << arr[i] << endl;
    }
    cout << "Sum: " << sum << endl;
    cout << "Average: " << (sum / 5.0) << endl; 
    cout << "Max: " << maxi << endl;
    cout << "Min: " << mini << endl;
}

int main10() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "Enter " << i + 1 << "th Number: ";
        cin >> arr[i];
    }
    arrayOperations(arr);
    return 0;
}



int main11() {
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;
    map<int, int> freq;
    for (int i = 1; i <= n; i++) {
        int num;
        cout << "Enter " << i << "th number: ";
        cin >> num;
        freq[num]++;
    }
    cout << "\nFrequencies :\n";
    for (auto pair : freq) {
        cout << pair.first << " => " << pair.second << endl;
    }
    return 0;
}


// merge two arrays
int main12() {
    int n1, n2;
    cout << "Enter the size of the array 1 : ";
    cin >> n1;
    cout << "Enter the size of the array 2 : ";
    cin >> n2; 

    int arr1[n1];
    int arr2[n2];
    int arr3[n1 + n2];
    int idx = 0;

    cout << "Enter the Elements of array 1:\n";
    for (int i = 0; i < n1; i++) {
        cout << "Enter " << i + 1 << "th element of 1st Array : ";
        cin >> arr1[i];
    }

    cout << "Enter the Elements of array 2:\n";
    for (int i = 0; i < n2; i++) {
        cout << "Enter " << i + 1 << "th element of 2nd Array : ";
        cin >> arr2[i];
    }

    // Merge arrays
    for (int i = 0; i < n1; i++) arr3[idx++] = arr1[i];
    for (int i = 0; i < n2; i++) arr3[idx++] = arr2[i];

    // Print merged array
    cout << "Merged Array: ";
    for (int i = 0; i < n1 + n2; i++) cout << arr3[i] << " ";
    cout << endl;
    return 0;
}


int main(){
    main10();
}