#include <iostream>
using namespace std;

class Tracker {
    public:
        int id;              // Unique ID for each object
        string name;         // Example public member

    private:
        static int count;    // Active object count
        static int nextId;   // Next available unique ID

    public:
        // Parameterized constructor
        Tracker(string n) {
            id = nextId++;
            name = n;
            count++;
            cout << "Constructor called. ID = " << id << ", Count = " << count << endl;
        }

        // Copy constructor
        Tracker(const Tracker &other) {
            id = nextId++;
            name = other.name; // Copy other data if needed
            count++;
            cout << "Copy constructor called for id = " << id << " (copied from id = " << other.id << ")" << endl;
        }

        // Destructor
        ~Tracker() {
            cout << "Destructor called for id = " << id << ", Count before destruction = " << count << endl;
            count--;
        }

        // Function to get current active object count
        static int getActiveCount() {
            return count;
        }
    };

// Initialize static members
int Tracker::count = 0;
int Tracker::nextId = 1;

// Function that creates and returns a Tracker object by value
Tracker createTracker() {
    Tracker t("CreatedByFunction");
    return t;
}

// Function that accepts a Tracker object by value
void takeTracker(Tracker t) {
    cout << "Inside takeTracker function. ID = " << t.id << endl;
}

int main1() {
    cout << "Step 1: Creating two Tracker objects" << endl;
    Tracker t1("Tracker1");
    Tracker t2("Tracker2");
    cout << "Active objects: " << Tracker::getActiveCount() << endl << endl;

    cout << "Step 2: Copying one object" << endl;
    Tracker t3 = t1; // Copy constructor
    cout << "Active objects: " << Tracker::getActiveCount() << endl << endl;

    cout << "Step 3: Calling createTracker()" << endl;
    Tracker t4 = createTracker(); // Returns by value, copy may be optimized
    cout << "Active objects: " << Tracker::getActiveCount() << endl << endl;

    cout << "Step 4: Passing object to takeTracker()" << endl;
    takeTracker(t2); // Copy constructor called because pass by value
    cout << "Active objects: " << Tracker::getActiveCount() << endl << endl;

    cout << "Step 5: Block scope creation" << endl;
    {
        Tracker t5("BlockTracker1");
        Tracker t6("BlockTracker2");
        cout << "Active objects inside block: " << Tracker::getActiveCount() << endl;
    } // t5 and t6 destroyed here
    cout << "Active objects after block: " << Tracker::getActiveCount() << endl << endl;

    return 0;
}



class SessionManager {
public:
    int sessionId;                  
      static int activeSessions;      
     static int nextSessionId;       

    // Default constructor
    SessionManager() {
        sessionId = nextSessionId++;
        activeSessions++;
        cout << "Session started. ID = " << sessionId << ", Active sessions = " << activeSessions << endl;
    }

    // Copy constructor
    SessionManager(const SessionManager &other) {
        sessionId = nextSessionId++;
        activeSessions++;
        cout << "Session duplicated. New ID = " << sessionId << " (copied from ID = " << other.sessionId << ")" << endl;
    }

    // Destructor
    ~SessionManager() {
        cout << "Session ended. ID = " << sessionId << ", Active sessions before ending = " << activeSessions << endl;
        activeSessions--;
    }

    SessionManager startNewSession() {
        SessionManager s;
        return s;
    }

    void processSession(SessionManager s) {
        cout << "Processing session ID = " << s.sessionId << endl;
    }
};

// Initialize static members
int SessionManager::activeSessions = 0;
int SessionManager::nextSessionId = 1;

int main2() {
    cout << "Step 1: Create three SessionManager objects" << endl;
    SessionManager s1, s2, s3;
    cout << "Active sessions: " << SessionManager::activeSessions << endl << endl;

    cout << "Step 2: Duplicate one session using copy constructor" << endl;
    SessionManager s4 = s2;
    cout << "Active sessions: " << SessionManager::activeSessions << endl << endl;

    cout << "Step 3: Call startNewSession()" << endl;
    SessionManager s5 = s1.startNewSession();
    cout << "Active sessions: " << SessionManager::activeSessions << endl << endl;

    cout << "Step 4: Pass a session object to processSession()" << endl;
    s3.processSession(s1); // Copy constructor triggered
    cout << "Active sessions: " << SessionManager::activeSessions << endl << endl;

    cout << "Step 5: Nested block with two more sessions" << endl;
    {
        SessionManager s6, s7;
        cout << "Active sessions inside block: " << SessionManager::activeSessions << endl;
    }
    cout << "Active sessions after block: " << SessionManager::activeSessions << endl << endl;

    return 0;
}


int main(){
    main2();
}