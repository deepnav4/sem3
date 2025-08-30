#include <bits/stdc++.h>
using namespace std;

// ------------------- SHALLOW COPY -------------------
class Points1 {
public:
    int *x;

    // Constructor
    Points1(int a = 0) {
        x = new int(a);
        cout << "Constructor called, *x = " << *x << endl;
    }

    // Default copy constructor (SHALLOW COPY)
    // Compiler-generated: just copies the pointer address (not the value itself)

    void setValue(int val) {
        *x = val;
    }

    void display() {
        cout << "Value = " << *x << " | Address = " << x << endl;
    }

    // Destructor
    ~Points1() {
        cout << "Destructor called for *x = " << *x << endl;
        delete x;
    }
};

// ------------------- DEEP COPY -------------------
class Points2 {
public:
    int *x;

    // Constructor
    Points2(int a = 0) {
        x = new int(a);
        cout << "Constructor called, *x = " << *x << endl;
    }

    // User-defined Copy Constructor (DEEP COPY)
    Points2(const Points2 &p) {
        x = new int(*p.x);  // allocate new memory and copy value
        cout << "Deep Copy constructor called, *x = " << *x << endl;
    }

    void setValue(int val) {
        *x = val;
    }

    void display() {
        cout << "Value = " << *x << " | Address = " << x << endl;
    }

    // Destructor
    ~Points2() {
        cout << "Destructor called for *x = " << *x << endl;
        delete x;
    }
};

int main() {
    cout << "===== Shallow Copy Example =====" << endl;
    Points1 p1(10);
    Points1 p2 = p1;  // shallow copy (pointer copied, not value)

    cout << "Before change:" << endl;
    p1.display();
    p2.display();

    p1.setValue(20);  // changing p1 also changes p2 because both share same memory

    cout << "After change in p1:" << endl;
    p1.display();
    p2.display();

    cout << "\n===== Deep Copy Example =====" << endl;
    Points2 q1(30);
    Points2 q2 = q1;  // deep copy (separate memory)

    cout << "Before change:" << endl;
    q1.display();
    q2.display();

    q1.setValue(40);  // changing q1 does NOT affect q2

    cout << "After change in q1:" << endl;
    q1.display();
    q2.display();

    return 0;
}


