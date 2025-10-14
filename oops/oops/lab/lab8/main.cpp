#include<bits/stdc++.h>
using namespace std;




class B;

class A {
public:
    int a;
    A(int val) {
        a = val;
    }
    friend int add(A, B);
};

class B {
public:
    int b;
    B(int val) {
        b = val;
    }
    friend int add(A, B);
};

int add(A obj1, B obj2) {
    return (obj1.a + obj2.b);
}

int main1() {
    A a(10);
    B b(20);
    cout << "Sum = " << add(a, b);
    return 0;
}

// Q2.Write a program to increment the salary of employee using friend class.

class Employee{
    int salary;
    public:
    Employee(int sal){
        salary = sal;
    }
    friend class Manager;
};

class Manager{
    public:
    void incrementSalary(Employee &emp){
        emp.salary += 1000;
    }
    void display(Employee &emp){
        cout<<emp.salary;
    }
};

int main6(){
    Employee emp(5000);
    Manager mgr;
    mgr.incrementSalary(emp);
    mgr.display(emp);
    return 0;
}


class Cube;

class Cuboid {
    float length, breadth, height;

    public:
    Cuboid(float l, float b, float h) {
        length = l;
        breadth = b;
        height = h;
    }

    float area() {
        return 2 * (length * breadth + breadth * height + height * length);
    }

    friend class Cube;
};

class Cube {
    float side;

    public:
    void convert(Cuboid c) {
        float volume = c.length * c.breadth * c.height;
        side = cbrt(volume);
    }

    void display() {
        cout << "Converted Cube side: " << side;
        cout << "Surface Area of Cube: " << 6 * side * side << endl;
    }
};

int main11() {
    float l, b, h;
    cout << "Enter length, breadth and height of cuboid: ";
    cin >> l >> b >> h;
    Cuboid cuboid(l, b, h);
    cout << "\nSurface Area of Cuboid: " << cuboid.area() << endl;
    Cube cube;
    cube.convert(cuboid);
    cube.display();

    return 0;
}

class Array {
    int *arr;   
    int size;

    public:
    Array(int s) {
        size = s;
        arr = new int[size];  
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    int findLargest() {
        int largest = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > largest)
                largest = arr[i];
        }
        return largest;
    }
};

int main19(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    Array a(n); 
    cout << "Largest element in the array: " << a.findLargest() << endl;
}


// Q5.Write a class that stores a string and all its status details such as number of
// upper case characters, vowel, characters, and words.

class String{
    string s;
    public:
        String(string s){
            this->s = s;
        }

        int countVowels() {
            int count = 0;
            for (char c : s) {
                c = tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    count++;
            }
            return count;
        }
        int countUppercase() {
            int count = 0;
            for (char c : s) {
                if (isupper(c))
                    count++;
            }
            return count;
        }
        int countCharacters() {
            int count = 0;
            for (char c : s) {
                if (!isspace(c))
                    count++;
            }
            return count;
        }
};

int main(){
    String s("Navdeep Singh");
    cout<<s.countCharacters() <<endl;
    cout<<s.countUppercase() <<endl;
    cout<<s.countVowels() <<endl;
}

// Q6.Write a program that dynamically allocates memory to a matrix. Add two
// matrices, display the resultant matrix, and finally free the memory space.


