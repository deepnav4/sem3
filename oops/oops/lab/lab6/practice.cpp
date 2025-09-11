// Q1. Write a program with multiple classes, some of which are members of other classes, to
// observe the order in which constructors and destructors are called during object creation and
// destruction. You can use std::cout statements within the constructors and destructors to trace
// their execution.

#include <iostream>
using namespace std;

class class1 {
    public:
        class1() {
            cout << "Constructor of class1 called" << endl;
        }
        ~class1() {
            cout << "Destructor of class1 called" << endl;
        }
};

class class2 {
    public:
        class2() {
            cout << "Constructor of class2 called" << endl;
        }
        ~class2() {
            cout << "Destructor of class2 called" << endl;
        }
};

class class3 {
    class2 b; 
    class1 a; 
    public:
        class3() {
            cout << "Constructor of class3 called" << endl;
        }
        ~class3() {
            cout << "Destructor of class3 called" << endl;
        }
};


int main() {
    cout << "Creating object constrcurtor" << endl;
    class3 c;   
    cout << "Object created." << endl;

    cout << "Exiting destrcutor called" << endl;
    return 0;
}




class Base{
    private:
        string s;
        int age;

    protected:
        char gender;    

    public:
        void getBasicInfo(void){
            cout<<s<<endl;
            cout<<age<<endl;
            cout<<gender<<endl;
        }

        void putBasicInfo(void){
            cout<<"Enter Name : ";
            cin>>s;
            cout<<"Enter Age : ";
            cin>>age;
            cout<<"Enter Gender : ";
            cin>>gender;
        }
};


class Derived:public Base{
    private:
        int totalM;
        float perc;
        char grade;

    public:
        void getResultInfo(void){
            //  cout<<s<<endl; // private member in base class
            // cout<<age<<endl;  // private member in base class
            // cout<<gender<<endl;  // can be accessed in parent class protected member
        };
        void putResultInfo(void){
            cout<<"Enter Total Marks : ";
            cin>>totalM;
            cout<<"Enter Percentage : ";
            cin>>perc;
            cout<<"Enter Grade : ";
            cin>>grade;
        };
};

int main2(){
    // Derived d;
    Base B;
    B.putBasicInfo();
    B.getBasicInfo();
    // d.putResultInfo();
    // d.getResultInfo();
}