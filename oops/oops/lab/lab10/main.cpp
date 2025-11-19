#include<bits/stdc++.h>
using namespace std;

// Q1. Write a program to demonstrate pointer declaration, initialization and dereferencing.
// ● Declare an integer variable and a pointer to it.
// ● Display the variable’s value and its address using the pointer.
// ● Modify the value of the variable through the pointer and show that the change is reflected.

int main1(){
    int num = 10;
    int *ptr = &num;
    cout<<"Using Num Variable : "<<num <<endl;
    cout<<"Using Pointer Variable : " <<*ptr <<endl;
    cout<<"Addrss of ptr : " <<ptr <<endl;
}


// Q2. Given a string s, return the longest palindromic substring in s. Implement the solution using pointers.
// Example: s= “stress”, output: “ss”

bool ispalidrome(string s){
    int i = 0;
    int j = s.size()-1;
    while(i<=j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

string longestpalindrome(string* ptr){
    string s=*ptr;
    string ans="";
    for(int i=0;i<s.size();i++){
        string temp="";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(ispalidrome(temp)){
                if(temp.size()>ans.size()) ans=temp;
            }
        }
    }
    return ans;
}



int main(){
    string s="stress";
    string ans=longestpalindrome(&s);
    cout<<ans;
    return 0;
}

// Q3. Create a base class Shape with a virtual function area().
// Derive two classes Circle and Rectangle that override the area() function.
// Use a base class pointer to call the appropriate area() function for each derived object.


//Q3
class Shape{
    public:
    virtual void Area(){
        cout<<"This is base class Area function"<<endl;
    }
};

class Rectangle: public Shape{
    public:
    int length;
    int breadth;
    Rectangle(int length,int breadth):Shape(),length(length),breadth(breadth){}
    void Area() override{
        cout<<"Area of the Rectangle is: "<<length*breadth<<endl;
    }
};

class Circle: public Shape{
    public:
    int radius;
    Circle(int radius):Shape(), radius(radius){}
    void Area() override{
        cout<<"Area of the Circle is: "<<3.1415*radius*radius<<endl;
    }
};

int main4(){
    Rectangle r1(5,10);
    Shape *ptr=&r1;
    ptr->Area();

    Circle c1(4);
    ptr=&c1;
    ptr->Area();

    return 0;
}

// Q4. Given an input string s, reverse the order of the words concatenated by a single space.
// Use a function that takes the string by references to perform the reversal.
// Example: s= “ hello world ”, output: “world hello”



void reverseWords(string &s) {
    string result = "", word = "";
    int i = s.length() - 1;
    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') i--;
        word = "";
        while (i >= 0 && s[i] != ' '){
            word = s[i] + word;
            i--;
        }
        if (!word.empty()) {
            if (!result.empty()) result += " ";
            result += word;
        }
    }
    s = result;
}

int main5() {
    string s = "   hello   world   ";
    reverseWords(s);
    cout << s; 
    return 0;
}


// Q5. Pointer Types Demonstration Program
// Write a single program that does the following:
// 1. Null Pointer
// o Declare a null pointer and check if it is null.
// o Print a message indicating it is a null pointer.
// 2. Dangling Pointer
// o Allocate memory dynamically, delete it, and
// attempt to access the pointer.
// o Show how to fix the dangling pointer by
// resetting it to null.
// 3. Wild Pointer
// o Declare a pointer without initialization.
// o Try to use it (observe behavior), then safely
// initialize it.
// 4. Void Pointer
// o Create a void pointer pointing to an integer.
// o Demonstrate typecasting to correctly access the
// value.
// 5. Constant Pointer & Pointer to Constant
// o Declare a constant pointer and pointer to
// constant.
// o Demonstrate allowed and disallowed
// operations.
// 6. Pointer to Pointer (Double Pointer)
// o Create a pointer that points to another pointer.
// o Use it to access the value indirectly.


int main() {
    int* nullPtr = nullptr;
    if (nullPtr == nullptr) {
        cout << "This is a null pointer." << endl;
    }

    int* danglingPtr = new int(10);
    delete danglingPtr;
    danglingPtr = nullptr;

    int* wildPtr;
    // cout << *wildPtr;
    int value = 20;
    wildPtr = &value;
    cout << "Value via wildPtr: " << *wildPtr << endl;

    int intValue = 30;
    void* voidPtr = &intValue;
    cout << "Value via voidPtr: " << <int>(voidPtr) << endl;

    int constValue = 40;
    int* const constPtr = &constValue; 
    // *constPtr = 50;
    cout << "Value via constPtr: " << *constPtr << endl;

    const int* ptrToConst = &constValue; 
    // *ptrToConst = 60;
    cout << "Value via ptrToConst: " << *ptrToConst << endl;

    int var = 70;
    int* ptr = &var;
    int** doublePtr = &ptr;
    cout << "Value via doublePtr: " << **doublePtr << endl;

    return 0;
}