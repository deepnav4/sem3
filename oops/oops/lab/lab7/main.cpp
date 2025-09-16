#include <bits/stdc++.h>
using namespace std;



// Q1. Consider the following cases
//  Class Person
//  Private member: name (string)
//  Constructor to initialize name
//  Public methods:
//  introduce() — prints a greeting including the person's name
//  getName() — returns the name
class Person {
    private:
        string name;

    public:
        Person(string name) {
            this->name = name;
        }

        void introduce() {
            cout << "Hello Everyone, my name is: " << name << endl;
        }

        string getName() {
            return name;
        }
    };



class Employee : public Person {
    private:
        string employeeID;
        int workHours;

    public:
        Employee(string name, string employeeID, int workHours): Person(name) {
            this->employeeID = employeeID;
            this->workHours = workHours;
        }

        void work() {
            cout << "Employee ID: " << employeeID << " is working as Employee" << endl;
        }

        int getWorkHours() {
            return workHours;
        }
    };

class Student {
    private:
        string studentID;
        vector<string> courses;
        int courseCount = 2;

    public:
        Student(string studentID, string course1, string course2) {
            this->studentID = studentID;
            courses.push_back(course1);
            courses.push_back(course2);
        }

        void study() {
            cout << "Student with Student Id " << studentID<< " is enrolled in " << courses[0] << " and " << courses[1] << endl;
        }

        int getCourseCount() {
            return courseCount;
        }

        string getCourse(int index) {
            if (index < 2) return courses[index];
            else return "Invalid Index !!";
        }

        vector<string> getAllCourses() {
            return courses;
        }
    };


//  Class TeachingAssistant (inherits from both Employee and Student)
//  Private member: taHours (int) — number of hours spent assisting professors
//  Constructor to initialize all data members, including those of Employee and Student
//  Public methods:
//  assist() — prints a message about assisting professors
//  showSchedule() — prints the teaching assistant’s name, work hours, TA hours,
// courses enrolled, and total hours (work + TA)

class TeachingAssistant : public Employee, public Student {
private:
    int taHours;

public:
    TeachingAssistant(int taHours, string name, string employeeID, int workHours,string studentID, string course1, string course2): Employee(name, employeeID, workHours),Student(studentID, course1, course2) {
        this->taHours = taHours;
    }

    void assist() {
        cout << "Teaching Assistant " << getName()<< " is assisting professors." << endl;
    }

    void showSchedule() {
        cout << "Name: " << getName() << endl;
        cout << "Work Hours: " << getWorkHours() << endl;
        cout << "TA Hours: " << taHours << endl;

        cout << "Courses Enrolled: ";
        vector<string>cs = getAllCourses();
        for (auto c : cs) cout << c << " ";
        cout << endl;

        cout << "Total Hours: " << (getWorkHours() + taHours) << endl;
    }
};

int main() {
    Person p("Nav");
    p.introduce();

    Employee e("Deep", "M2", 40);
    e.work();
    cout << "Work Hours:" << e.getWorkHours() << endl;

    Student s("M1", "Math", "Physics");
    s.study();
    cout << "Course[0]: " << s.getCourse(0) << endl;

    TeachingAssistant ta(15, "Manpreet", "M3", 30, "M4", "Chemistry", "Biology");
    ta.assist();
    ta.showSchedule();

    return 0;
}


// Write a program for following cases.
// 1. Implement all the above classes with proper constructors and member functions.
// 2. Use constructor initialization lists to initialize all member variables.
// 3. In the main() function: Create objects of Person, Employee, Student, and TeachingAssistant.
// 4. Call relevant methods on each object to demonstrate their behavior.
// 5. Show that TeachingAssistant correctly inherits and accesses members from both Employee and
// Student. Format all output as described by the member functions.


//  Class Employee (inherits from Person)
//  Private members: employeeID (string), workHours (int)
//  Constructor to initialize name, employeeID, and workHours
//  Public methods:
//  work() — prints information about the employee's role and ID
//  getWorkHours() — returns the number of work hours
//  Class Student (independent of Person)
//  Private members: studentID (string), two courses (course1 and course2), and
// courseCount (int, fixed to 2)
//  Constructor to initialize studentID, course1, and course2
//  Public methods:
//  study() — prints the courses the student is enrolled in and the student ID
//  getCourseCount() — returns the number of courses
//  getCourse(int index) — returns the course name at the given index (0 or 1)
//  Class TeachingAssistant (inherits from both Employee and Student)
//  Private member: taHours (int) — number of hours spent assisting professors
//  Constructor to initialize all data members, including those of Employee and Student
//  Public methods:
//  assist() — prints a message about assisting professors
//  showSchedule() — prints the teaching assistant’s name, work hours, TA hours,
// courses enrolled, and total hours (work + TA)

// Write a program for following cases.
// 1. Implement all the above classes with proper constructors and member functions.
// 2. Use constructor initialization lists to initialize all member variables.
// 3. In the main() function: Create objects of Person, Employee, Student, and TeachingAssistant.
// 4. Call relevant methods on each object to demonstrate their behavior.
// 5. Show that TeachingAssistant correctly inherits and accesses members from both Employee and
// Student. Format all output as described by the member functions.




