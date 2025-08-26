#include<bits/stdc++.h>
using namespace std;



class Point {
public:
    int x, y;
    Point(int a = 0, int b = 0) {
        x = a;
        y = b;
        cout << "Constructor called for (" << x << ", " << y << ")" << endl;
    }

    Point(const Point &p) {
        x = p.x;
        y = p.y;
        cout << "Copy constructor called for (" << x << ", " << y << ")" << endl;
    }

    // Display function
    void display() { cout << "(" << x << ", " << y << ")" << endl; }
};

int main(){
    Point p1;
    Point p2 = p1;
    Point p2(p1);
}

// Function to demonstrate pass by value
// void passByValue(Point p) {
//     cout << "Inside passByValue: ";
//     p.display();
// }

// // Function to demonstrate pass by reference
// void passByReference(Point &p) {
//     cout << "Inside passByReference: ";
//     p.display();
// }

int main1() {
    cout << "1. Direct Initialization" << endl;
    Point p1(10, 20);  // Direct initialization
    p1.display();

    cout << "\n2. Copy Initialization" << endl;
    Point p2 = p1;     // Copy initialization
    p2.display();

    cout << "\n3. Pass by Value" << endl;
    // passByValue(p1);   // Calls copy constructor

    cout << "\n4. Pass by Reference" << endl;
    // passByReference(p1); // No copy constructor called

    cout << "\n5. Copy Assignment" << endl;
    Point p3;          // Default constructor
    p3 = p1;           // Copy assignment
    p3.display();

    return 0;
}


// Key Points
// A copy constructor cannot have default arguments.
// It takes exactly one parameter, which is a reference to the same class type.
// The compiler provides a default copy constructor if none is defined, which performs a shallow copy.
// Use a custom copy constructor when your class manages resources like dynamic memory to prevent issues like double deletion.




class Tracker {
    public:
        int id; // unique id for each object

    private:
        static int count;   // number of active objects
        static int nextId;  // next id to assign

    public:
        // Parameterized constructor
        Tracker() {
            id = nextId;       // assign unique id
            nextId++;           // increment nextId for future objects
            count++;            // increment active object count
            cout << "Constructor called. ID = " << id << ", Count = " << count << endl;
        }

        // syntax className(const className &obj);
        Tracker(const Tracker &obj) {
            id = nextId;      
            nextId++;
            count++;          
            cout << "Copy constructor called for id = " << id << " (copied from id = " << obj.id << ")" << endl;
        }

        ~Tracker() {
            cout << "Destructor called for id = " << id << ", Count before destruction = " << count << endl;
            count--;          
        }

        Tracker createTracker() {
            Tracker temp; 
            return temp; 
        }

        int getCount() {
            return count;
        }
};

void takeTracker(Tracker t) {
    cout << "Inside takeTracker() function" << endl;
    // cout << "Current active objects: " << Tracker::getCount() << endl;
}

Tracker createTracker() {
    Tracker temp;
    cout << "Inside createTracker() function" << endl;
    // cout << "Current active objects: " << Tracker::getCount() << endl;
    return temp; // Copy constructor may be called depending on compiler optimization (RVO)
}

int Tracker::count = 0;
int Tracker::nextId = 1;

