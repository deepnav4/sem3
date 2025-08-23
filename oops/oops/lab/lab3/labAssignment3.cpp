#include<bits/stdc++.h>
using namespace std;

// multiply two integers
float multiply(int a,int b){
    return a*b;
}

// multiply int and float
float multiply(int a,float b){
    return a*b;
}

// multiply two floats
float multiply(float a,float b){
    return a*b;
}

int main1(){
    cout<<multiply(3.5,3) <<endl;
    cout<<multiply(3,3) <<endl;
    cout<<multiply(3.5f,3.5f) <<endl;
    return 0;
}

// compare two integers
void compare(int a,int b){
    if(a>b) cout<<a <<" is Greater than "<<b <<endl;
    else if(a<b) cout<<b<<" is Greater than "<<a <<endl;
    else cout<<"Both " <<a <<" and " <<b <<" are equal"<<endl;
}

// compare two characters
void compare(char a,char b){
    if(a>b) cout<<a <<" is Greater than "<<b <<endl;
    else if(a<b) cout<<b<<" is Greater than "<<a <<endl;
    else cout<<"Both " <<a <<" and " <<b <<" are equal" <<endl;
}

// compare two strings
void compare(string a,string b){
    if(a>b) cout<<a <<" is Greater than "<<b <<endl;
    else if(a<b) cout<<b <<" is Greater than "<<a <<endl;
    else cout<<"Both " <<a <<" and " <<b <<" are equal" <<endl;
}

int main2(){
    compare('a','b');
    compare(1,2);
    compare("Hello","World");
    return 0;
}

// reverse an integer
void reverse(int a){
    int reversedNum = 0;
    while(a){
        int rem = a%10;
        reversedNum = reversedNum * 10 + rem;
        a /= 10;
    }
    cout<<reversedNum<<endl;
}

// reverse a string
void reverse(string s){
    int start = 0, end = s.size()-1;
    while(start<=end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
    cout<<s<<endl;
}

// reverse a float
void reverse(float a){
    string s = to_string(a); 
    while(!s.empty() && s.back()=='0') s.pop_back();
    if(!s.empty() && s.back()=='.') s.pop_back();
    reverse(s);  
}

int main3(){
    // reverse()

    reverse("Navdeep");
    reverse(12.34f);
    return 0;
}

// struct for book
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

// struct for employee
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

// struct for product
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
    return 0;
}

// struct for date
struct Date{
    int day;
    int month;
    int year;
};

// struct for person with dob
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
