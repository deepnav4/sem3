#include <bits/stdc++.h>
using namespace std;

// Q1.Create a class Car with data members brand and model. Define a method display()
// to show the values. Declare an object of Car and a pointer pointing to it. Access the
// object’s members using the pointer.

// Q2.Define a class Rectangle with members length and breadth. Create a function that
// accepts a pointer to a Rectangle object and calculates the area. Call this function
// using a pointer to a Rectangle object.

// Q3.Define a class Employee with members name and salary. Create three objects of
// Employee and store their addresses in an array of pointers. Use the pointers to call
// member functions and display details.

// Q4.Create a class Circle with a radius member and a method to compare the radius of
// two circles. Pass a pointer to another object as an argument to the method and
// compare the radius.

// Q5.Define a class Student with a method display(). Declare a constant object and a
// pointer to that object. Call the method using the pointer.
// Q6.Create a class Counter with a private integer variable. Define a function outside
// the class that increments the counter by accessing it through a pointer. Call the
// function from main().
// Q7.Define a class Point with x and y coordinates. Create a method that takes a pointer
// to another Point object and calculates the distance between the two points.
// Q8.Create a class Item with members id and price. Define three objects and store their
// addresses in a pointer array. Use a loop to assign and display values through the
// pointer array.

class Car {
public:
    string brand;
    string model;

    Car(string brand, string model) {
        this->brand = brand;
        this->model = model;
    }

    void display() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }
};

int main1() {
    Car *c1 = new Car("Honda", "Civic");
    c1->display();
    delete c1;
    return 0;
}


class Rectangle {
public:
    float length;
    float breadth;

    Rectangle(float length, float breadth) {
        this->length = length;
        this->breadth = breadth;
    }

    float area() {
        return length * breadth;
    }
};

float calcArea(Rectangle *r) {
    return r->length * r->breadth;
}

int main2() {
    Rectangle *r1 = new Rectangle(5.0, 3.0);
    cout << "Area: " << calcArea(r1) << endl;
    delete r1;
    return 0;
}


class Employee {
public:
    string name;
    float salary;

    Employee(string name, float salary) {
        this->name = name;
        this->salary = salary;
    }

    void display() {
        cout << "Name: " << name << " | Salary: " << salary << endl;
    }
};

int main3() {
    vector<Employee*> e;
    e.push_back(new Employee("A", 24000));
    e.push_back(new Employee("B", 23000));
    e.push_back(new Employee("C", 22000));

    for (auto emp : e)
        emp->display();

    for (auto emp : e)
        delete emp;

    return 0;
}


class Circle {
    public:
        float radius;

        Circle(float radius) {
            this->radius = radius;
        }

        void compare(Circle *c2) {
            if (this->radius > c2->radius)
                cout << "This circle is larger." << endl;
            else if (this->radius < c2->radius)
                cout << "Passed circle is larger." << endl;
            else
                cout << "Both circles have equal radius." << endl;
        }
};

int main4() {
    Circle c1(5.5);
    Circle c2(7.2);
    c1.compare(&c2);
    return 0;
}



class Student {
    public:
        string name;

        Student(string name) {
            this->name = name;
        }

        void display() const {
            cout << "Student Name: " << name << endl;
        }
};

int main5() {
    const Student s1("Navdeep");
    const Student *ptr = &s1;
    ptr->display();
    return 0;
}


class Counter {
    private:
        int count;
    public:
        Counter(int count = 0) {
            this->count = count;
        }
        void show() { cout << "Count: " << count << endl; }
        friend void increment(Counter *c);
};

void increment(Counter *c) {
    c->count++;
}

int main6() {
    Counter c1(5);
    increment(&c1);
    c1.show();
    return 0;
}


class Point {
    public:
        float x, y;
        Point(float x, float y) {
            this->x = x;
            this->y = y;
        }

        float distance(Point *p2) {
            return sqrt(pow(p2->x - x, 2) + pow(p2->y - y, 2));
        }
};

int main7() {
    Point p1(2, 3);
    Point p2(5, 7);
    cout << "Distance: " << p1.distance(&p2) << endl;
    return 0;
}


class Item {
    public:
        int id;
        float price;

        Item(int id = 0, float price = 0.0) {
            this->id = id;
            this->price = price;
        }

        void display() {
            cout << "ID: " << id << " | Price: " << price << endl;
        }
};

int main() {
    Item *items[3];
    items[0] = new Item(101, 50.5);
    items[1] = new Item(102, 70.2);
    items[2] = new Item(103, 99.9);

    cout << "Item Details:" << endl;
    for (int i = 0; i < 3; i++)
        items[i]->display();

    for (int i = 0; i < 3; i++)
        delete items[i];

    return 0;
}
