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

// int main(){
//     // main1();
//     main2();
// }














// Q1. Write a C++ program to define a class named LibraryBook to manage book
// registrations in a library. The class should perform the following:
// i. Declare a static data member totalBooks to count how many books have been
// registered.
// ii. Declare a non-static data member bookID to hold each book’s unique ID.
// iii. Create a member function registerBook() that:
// a. Accepts a book ID as a parameter.
// b. Assigns it to the current object's bookID.
// c. Increments the static totalBooks counter.
// iv. Define a member function displayBook() to display the book’s ID.
// v. Define another non-static member function displayTotalBooks() that:
// a. Displays the current value of totalBooks by accessing the static data
// member.
// In the main() function:
// i. Write a command to create at least four objects of the LibraryBook class in the
// main() function?
// ii. Write the necessary commands to register a book for each object using the
// registerBook() function, assigning a different book ID to each.
// iii. Write the commands to display the book ID of each object using the displayBook()
// function.
// iv. Using any one of the objects, write the command to display the total number of
// books registered by calling the displayTotalBooks() function.


class LibraryBook {
    static int totalBooks;   // static member
    int bookID;              // non-static member

    public:
        // Register a book with given ID
        void registerBook(int bookID) {
            this->bookID = bookID;
            totalBooks++;
        }

        // Display book ID
        void displayBook() {
            cout << "Book ID: " << bookID << endl;
        }

        // Display total number of books registered
        void displayTotalBooks() {
            cout << "Total Books: " << totalBooks << endl;
        }
};

// Define and initialize static member
int LibraryBook::totalBooks = 0;

int main34() {
    // Create 4 objects
    LibraryBook b1, b2, b3, b4;

    // regsitering books
    b1.registerBook(217);
    b2.registerBook(318);
    b3.registerBook(765);
    b4.registerBook(654);

    // Display each book ID
    b1.displayBook();
    b2.displayBook();
    b3.displayBook();
    b4.displayBook();

    b1.displayTotalBooks();

    return 0;
}








// Q2. Write a C++ program that defines a class OnlineOrder to manage customer orders
// with the following specifications:
// i. Define a static data member orderCount to track the number of orders.
// ii. Define a non-static data member orderNumber.
// iii. Create a non-static member function placeOrder() that:
// a. Sets orderNumber to the current value of orderCount + 1.
// b. Increments orderCount.
// iv. Define another function showOrder() to display the orderNumber.
// v. Define a non-static member function showOrderCount() to display the current
// total order count using the static member.
// In the main() function:
// i. Write a command to create at least four objects of the LibraryBook class in the
// main() function?
// ii. Write the necessary commands to call the placeOrder() function for each object to
// simulate placing an order.
// iii. Write the commands to display the order details of each object using the
// showOrder() function.
// iv. Using any one of the objects, write the command to display the total number of
// orders placed by calling the showOrderCount() function.


#include <iostream>
using namespace std;

class OnlineOrder {
    static int orderCount;   // Static member to track total orders
    int orderNumber;         // Each object's order number

public:
    // Place an order
    void placeOrder() {
        orderNumber = orderCount + 1;  // Set order number
        orderCount++;                  // Increment total orders
    }

    // Show order number
    void showOrder() {
        cout << "Order Number: " << orderNumber << endl;
    }

    // Show total order count
    void showOrderCount() {
        cout << "Total Orders: " << orderCount << endl;
    }
};

// Initialize static member
int OnlineOrder::orderCount = 0;

int main() {
    // Create 4 objects
    OnlineOrder o1, o2, o3, o4;

    // Place orders
    o1.placeOrder();
    o2.placeOrder();
    o3.placeOrder();
    o4.placeOrder();

    // Show order details
    o1.showOrder();
    o2.showOrder();
    o3.showOrder();
    o4.showOrder();

    // Show total orders using one object
    o1.showOrderCount();

    return 0;
}
