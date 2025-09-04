#include <bits/stdc++.h>
using namespace std;

// Base class: Student
class Student {
private:   // private members: accessible only inside Student
    int rollNo;

protected: // protected members: accessible in derived classes
    string name;

public:    // public members: accessible everywhere
    int age;

    // Constructor
    Student(string n, int r, int a) {
        name = n;
        rollNo = r;
        age = a;
    }

    // Public method to access private member
    void setRollNo(int r) { rollNo = r; }
    int getRollNo() { return rollNo; }
 
    void showStudentInfo() {
        cout << "Name: " << name << ", Roll No: " << rollNo << ", Age: " << age << endl;
    }
};

// Derived class: ITStudent with different types of inheritance
class ITStudent : public Student {  // public inheritance
private:
    int marks;

public:
    ITStudent(string n, int r, int a, int m) : Student(n, r, a) {
        marks = m;
    }

    void showITInfo() {
        // name is protected in base → accessible here
        cout << "Name: " << name << ", Marks: " << marks << endl;
        // age is public in base → accessible here
        cout << "Age: " << age << endl;
        // rollNo is private in base → not directly accessible
        // cout << rollNo; // ❌ Error
        cout << "Roll No (via getter): " << getRollNo() << endl;
    }
};

// Another derived class: CSStudent with protected inheritance
class CSStudent : protected Student {  // protected inheritance
public:
    int marks;

    CSStudent(string n, int r, int a, int m) : Student(n, r, a) {
        marks = m;
    }

    void showCSInfo() {
        // name is protected → accessible
        cout << "Name: " << name << ", Marks: " << marks << endl;
        // age is public in base but becomes protected here due to protected inheritance
        cout << "Age: " << age << endl;
        cout << "Roll No (via getter): " << getRollNo() << endl;
    }
};

int main() {
    cout << "===== IT Student (public inheritance) =====" << endl;
    ITStudent s1("Navdeep", 73, 19, 98);
    s1.showITInfo();

    cout << "\n===== CS Student (protected inheritance) =====" << endl;
    CSStudent s2("Aman", 101, 20, 95);
    s2.showCSInfo();

    // Access from main
    cout << "\nAccessing members from main:" << endl;
    // s1.name → ❌ protected → not accessible outside
    cout << "s1.age = " << s1.age << endl;  // public → accessible
    cout << "s1.getRollNo() = " << s1.getRollNo() << endl;

    // s2.age → ❌ protected due to protected inheritance → not accessible
    // s2.name → ❌ protected → not accessible

    return 0;
}
