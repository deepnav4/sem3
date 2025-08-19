#include<bits/stdc++.h>
using namespace std;



// class Student{
//     int id;
//     int marks;
//     static int count;  // Static member inside class

// public:
//     void display(){
//         cout <<"id "<< id << endl;
//         cout <<"marks : " << marks << endl;
//         count++;
//         cout << "Count: " << count << endl;
//     }

//     void setValues(int a , int m ){
//         id = a ;
//         marks =  m ;
//     }
// };

// // Definition of static member
// int Student::count = 0;
// // varibale type  Object Name :: varible name  initialValue

// int main(){
//     Student s1;
//     s1.setValues(1 , 98) ;
//     s1.display();
//     s1.display();
//     s1.display();
//     return 0;
// }



// Q1. Write a C++ program to define a class named BankAccount that performs the following
// operations:
// i. Declare a static data member named totalAccounts to keep track of the total number
// of bank accounts created.
// ii. Declare a non-static data member named accountNumber to store the account number
// of each individual account.
// iii. Define a public member function named setAccountNumber() that:
// a. Accepts an account number as a parameter.
// b. Sets the accountNumber for the object.
// c. Increments the totalAccounts counter each time it is called.
// iv. Define a member function named showTotalAccounts() that:
// a. Displays the total number of accounts created by accessing the static variable.


static int totalAccounts; // declartion of global static variable

class BankAccount{
    int accountNo;

    public :
        void setAccountNumber(int no){
            accountNo = no;
            totalAccounts++;
        }

        void showTotalAccounts(){
            cout<< "Total Account Number : " <<totalAccounts;
        }
};


int main1(){
    BankAccount b1;
    b1.setAccountNumber(94);
    b1.setAccountNumber(95);
    b1.setAccountNumber(96);
    b1.setAccountNumber(97);
    b1.showTotalAccounts();
}




// // Q2. Write a C++ program that defines a class User to simulate user registration in a system,
// // with the following requirements:
// // i. Define a static data member nextID to keep track of the next available unique user ID
// // (starting from 1000).
// // ii. Define a non-static data member userID to store the ID of each registered user.
// // iii. Create a member function registerUser() that:
// // a. Assigns the current nextID value to the userID of the object.
// // b. Increments nextID so the next user gets a new ID.
// // iv. Create a member function showUser() to display the userID of the object.
// // v. Create another member function showNextID() that:
// // a. Displays the next user ID to be assigned (by accessing the static data member).



class User{
    public:
        static int nextId; // static varible declared as data member but its value should be declared outside the function

        int userId;
        int temp = nextId;
        User(){
            userId = nextId;
            nextId++;
        }

        void registerUser(){
            userId = nextId;
            nextId++;
            cout<<"User Registered with ID : " <<userId <<endl;
        }

        void showUser(){
            cout<<"User id of the current user : "<<userId <<endl;
        }

        void showNextId(){
            cout<<"Next User id to be assigned to the user is : " <<nextId <<endl;
        }
};


int User :: nextId = 1000; // value initilzed of static data member 

int main2(){
    User s1;
    s1.showUser();
    s1.registerUser();
    s1.registerUser();
    s1.registerUser();
    s1.showUser();
    s1.showNextId();
}

int main(){
    // main1();
    main2();
}



