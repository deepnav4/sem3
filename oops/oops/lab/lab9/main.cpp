#include <bits/stdc++.h>
using namespace std;

// Question 1: Design a class hierarchy to manage employee information in a company.
// ● Create a base class Employee with data members: empID, name, and
// basicSalary.
// ● Create a derived class Manager that inherits from Employee and adds data
// members: department and bonus.
// ● Create another derived class Developer that inherits from Employee and adds
// data members: projectName and extraHours.
// ● Both derived classes should override a member function calculateSalary()
// that computes total salary using suitable formulae (e.g., including bonus or extra
// payment).
// ● Demonstrate runtime polymorphism by calling calculateSalary() through
// a base class pointer.
// Output Requirement:
// Display the details of employees and their total salary using function overriding and
// inheritance.





class Employee {
    protected:
        int empID;
        string name;
        int basicSalary;

    public:
        Employee(int empID, string name, int basicSalary) {
            this->empID = empID;
            this->name = name;
            this->basicSalary = basicSalary;
        }

        virtual float calculateSalary() {
            return basicSalary;
        }

        virtual void display() {
            cout << "Employee ID: "<<empID<<endl;
            cout<<"Name: "<<name<<endl;
        }
};



class Manager : public Employee{
    string department;
    int bonus;
    public:
        Manager(int empID, string name, int basicSalary, string department, int bonus) :
            Employee(empID, name, basicSalary){
                this->department = department;
                this->bonus = bonus;
            }

        float calculateSalary() override{
            return basicSalary + bonus;
        }

        void display() override{
            Employee::display();
            cout << "Department: " << department<< "\nTotal Salary: " << calculateSalary() << "\n\n";
        }
};



class Developer : public Employee{
    string projectName;
    int extraHours;
    int ratePerHour;

    public:
        Developer(int empID, string name, int basicSalary, string projectName, int extraHours, int ratePerHour)
            : Employee(empID, name, basicSalary){
                this->projectName = projectName;
                this->extraHours = extraHours;
                this->ratePerHour = ratePerHour;
            }

        float calculateSalary() override{
            return basicSalary + (extraHours * ratePerHour);
        }

        void display() override {
            Employee::display();
            cout << "Project: " << projectName<< "\nTotal Salary: " << calculateSalary() << "\n\n";
        }
};



int main1() {
    Employee *e1 = new Manager(101, "Navdeep", 30000, "HR", 5000);
    Employee *e2 = new Developer(102, "Rishi", 25000, "AI App", 20, 200);

    e1->display();
    e2->display();
}





// Question 2: Write a program to demonstrate the use of friend functions for accessing
// private data members of two different classes.
// ● Create two classes Rectangle and Circle having private data members:
// length, breadth (for Rectangle), and radius (for Circle).
// ● Write a friend function compareArea(Rectangle, Circle) that compares
// the areas of both shapes and prints which one has a larger area.
// ● Accept the values for dimensions from the user and display the results.
// Output Requirement:
// Display the area of both shapes and a message indicating which shape has the larger
// area.

class Circle; 

class Rectangle {
    private:
        int length;
        int breadth;

    public:
        Rectangle(int length, int breadth) {
            this->length = length;
            this->breadth = breadth;
        }

        friend void compareArea(Rectangle &r, Circle &c);
};

class Circle {
    private:
        int radius;

    public:
        Circle(int radius) {
            this->radius = radius;
        }

        friend void compareArea(Rectangle &r, Circle &c);
};

void compareArea(Rectangle &r, Circle &c) {
    float areaRect = r.length * r.breadth;
    float areaCircle = 3.14159 * c.radius * c.radius;

    cout << fixed << setprecision(2);
    cout << "\nArea of Rectangle: " << areaRect;
    cout << "\nArea of Circle: " << areaCircle << endl;

    if (areaRect > areaCircle)
        cout << "\nRectangle has the larger area." << endl;
    else if (areaCircle > areaRect)
        cout << "\nCircle has the larger area." << endl;
    else
        cout << "\nBoth have equal area." << endl;
}

int main() {
    Rectangle rect(4,5);
    Circle circ(1);

    compareArea(rect, circ);

    return 0;
}