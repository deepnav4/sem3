#include<bits/stdc++.h>
using namespace std;


// Q1: Write a function that takes two integers by reference and returns the larger one. Also,
// update both variables by adding 1.

pair<int,int> fxn1(int &a,int &b){
    a++;
    b++;
    return {a,b}; 
}

int main1(){
    int a = 10;
    int b = 20;
    pair<int,int>ans = fxn1(a,b);
    cout<<a<<" "<<b;
}



//  Q2: Write a function that takes multiple variables by reference and updates their values based
// on user input.
void fxn2(int &a, int &b, int &c) {
    cout << "Enter three integers: ";
    cin >> a >> b >> c;
}

void main2() {
    int a, b, c;
    fxn2(a, b, c);
    cout << "Updated values: " << a << " " << b << " " << c << endl;
}


// Q3: Write a function that adds a number to a vector passed by reference.

void fxn3(vector<int> &v, int num) {
    v.push_back(num);
}

int main3(){
    vector<int>v = {1,2,3};
    int num;
    cout<<"Enter Number to push into vector : ";
    cin>>num;
    cout<<"Before Pushing Number : ";
    for(auto i : v) cout<<i<<" ";
    cout<<endl;
    fxn3(v,num);
    cout<<"After pushing Number : ";
    for(auto i : v) cout<<i<<" ";
}



// Q4: Write a function that takes two integers by value and returns quotient and remainder via
// reference parameters.

#include <iostream>
using namespace std;

// Function to calculate quotient and remainder
void fxn4(int a, int b, int &quotient, int &remainder) {
    if (b == 0) {
        cout << "Error: Division by zero is undefined." << endl;
        quotient = 0;
        remainder = 0;
        return;
    }
    quotient = a / b;
    remainder = a % b;
}

int main4() {
    int num1 = 20, num2 = 6;
    int q, r;
    fxn4(num1, num2, q, r);
    cout << "Quotient: " << q << endl;
    cout << "Remainder: " << r << endl;
    return 0;
}




// Q5: Write an inline function that calculates the power of a number with a default exponent of
// 2 (square). For example, power(3) returns 9, and power(2, 3) returns 8.

inline int fxn5(int num,int exponenet = 2){
    return pow(num,exponenet);
}

int main5(){
    cout<<fxn5(3)<<endl;
    cout<<fxn5(2,3);
}


int main(){
    // main1();
    // main2();
    // main3();
    // main4();
    main5();
}