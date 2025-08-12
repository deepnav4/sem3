#include<bits/stdc++.h>
using namespace std;

// struct Student{
//     private :
//     string name;
//     int rollNo;
//     float marks;

//     public:
//     void takeInputs(Student &s1){
//         cout<<"Inside take inputs Functions !!\n";
//         cout<<"Enter Name of Student : ";
//         getline(cin,s1.name);
//         cout<<"Enter Roll No of Student : ";
//         cin>>s1.rollNo;
//         cout<<"Enter Marks of Student : ";
//         cin>>s1.marks;
//     }

//     void display(Student &s1){
//         cout<<"Inside Diaplay Function !!\n";
//         cout<<"Name of the Student : " <<s1.name <<endl; 
//         cout<<"Roll No of the Student : " <<s1.rollNo <<endl;
//         cout<<"Marks of the Student : " <<s1.marks <<endl;
//     }
// };

// int main(){
//     Student s1;
//     s1.takeInputs(s1);
//     s1.display(s1);
// }


// Lab Assignment 3

// Q1. Write overloaded versions of the function multiply() to: Multiply two integers, Multiply a
// float and an integer (any order), Multiply two doubles.

// float multiply(float a,int b){
//     return a*b;
// }

float multiply(int a,int b){
    return a*b;
}

float multiply(int a,float b){
    return a*b;
}

float multiply(float a,float b){
    return a*b;
}

int main1(){
    cout<<multiply(3.5,3) <<endl;
    cout<<multiply(3,3) <<endl;
    cout<<multiply(3.5f,3.5f) <<endl; // By default it is considered as double 
}


// Q2. Write overloaded version of the function compare () to, compare two integers, compare
// two strings, and compare two characters.

void compare(int a,int b){
    if(a>b) cout<<a <<" is Greater than "<<b <<endl;
    else if(a<b) cout<<b<<" is Greater than "<<a <<endl;
    else cout<<"Both " <<a <<" and " <<b <<" are equal"<<endl;
}

void compare(char a,char b){
    if(a>b) cout<<a <<" is Greater than "<<b <<endl;
    else if(a<b) cout<<b<<" is Greater than "<<a <<endl;
    else cout<<"Both " <<a <<" and " <<b <<" are equal" <<endl;
}

void compare(string a,string b){
    if(a>b) cout<<a <<" is Greater than "<<b <<endl;
    else if(a<b) cout<<b<<" is Greater than "<<a <<endl;
    else cout<<"Both " <<a <<" and " <<b <<" are equal" <<endl;
}

int main2(){
    compare('a','b');
    compare(1,2);
    compare("Hello","World");
}


// Q3. Write overloaded version of the function reverse () to, reverse an integer, reverse a string,
// and reverse a float.

void reverse(int a){
    int reversedNum = 0;
    while(a){
        int rem = a%10;
        reversedNum = reversedNum * 10 + rem;
        a /= 10;
    }
    cout<<reversedNum<<endl;
}

void reverse(string s){
    int start = 0;
    int end = s.size()-1;
    while(start<=end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
    cout<<s<<endl;
}

void reverse(float a){
    // logic of reversing float number
}


int main3(){
    reverse(201);
    reverse("Navdeep");
}





// Q4. Define a struct Book with members char title [50], char author [50], and float price. Create
// three Book variables using designated initialization and display their details.

struct Book{
    char title[50];
    char author[50];
    float price;

    void display(Book &b) {
        cout << "Book Details:" << endl;
        cout << "Title: " << b.title << endl;
        cout << "Author: " << b.author << endl;
        cout << "Price: " << b.price << endl;
    }
};

int main4(){
    Book b1 = {"Metamorphosis","Franz Kafka",106};
    Book b2 = {"White Nights","Fyodor Dostoevsky",89.5};
    Book b3 = {"To Kill a Mockingbird","Harper Lee",120.0};

    b1.display(b1);
    b2.display(b2);
    b3.display(b3);

    return 0;
}


// Q5. Define a struct named Employee with int empId, char name [50], and float salary. Write a
// function printEmployee(Employee) to print employee details. Call this function from main()
// after taking input from the user.

struct Employee{
    int empId;
    char name[50];
    float salary;

    void printEmployee(Employee emp){
        cout << "Employee ID: " << emp.empId << endl;
        cout << "Name: " << emp.name << endl;
        cout << "Salary: " << emp.salary << endl;
    }
};


int main5(){
    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.empId;
    cout << "Enter Name: ";
    cin.ignore(); 
    cin.getline(emp.name,50); 
    cout << "Enter Salary: ";
    cin >> emp.salary;
    emp.printEmployee(emp);
    return 0;
}



// Q6. Define a struct Product with int productId, char name [50], float price. Write a program to
// input details of n products and display the product with the highest price.

struct Product{
    int productId;
    char name[50];
    float price;
};

int main6(){
    int n;
    cout<<"Enter Number of Products : ";
    cin>>n;
    vector<Product>p(n);

    for(int i=0; i<n; i++){
        cout<<"Enter details for product "<<i+1<<":"<<endl;
        cout<<"Enter Product ID: ";
        cin>>p[i].productId;
        cout<<"Enter Product Name: ";
        cin>>p[i].name;
        cout<<"Enter Product Price: ";
        cin>>p[i].price;
    }

    Product maxProduct = p[0];
    for(int i=1; i<n; i++){
        if(p[i].price > maxProduct.price){
            maxProduct = p[i];
        }
    }

    cout<<"Product with Highest Price: "<<endl;
    cout<<"ID: "<<maxProduct.productId<<endl;
    cout<<"Name: "<<maxProduct.name<<endl;
    cout<<"Price: "<<maxProduct.price<<endl;
}


// Q7. Define two structures Date with day, month, year, and Person with name, Date dob (date
// of birth). Write a program to input and display a person's name and date of birth.



// Basically Use of one struct to another Inheritance
struct Date{
    int day;
    int month;
    int year;
};

struct Person{
    char name[50];
    Date dob;
};

int main7(){
    Person p;
    cout << "Enter Name: ";
    cin.getline(p.name,50);
    cout << "Enter Date of Birth (dd mm yyyy): ";
    cin >> p.dob.day >> p.dob.month >> p.dob.year;

    cout << "Name: " << p.name << endl;
    cout << "Date of Birth: " << p.dob.day << "/" << p.dob.month << "/" << p.dob.year << endl;

    return 0;
}

int main(){
    main1();
    main2();
    main3();
    main4();
    main5();
    main6();
    main7();
}