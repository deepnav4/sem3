#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Tracker {
public:
    int id;
    string name;

private:
    static int count;    // number of active objects
    static int nextId;   // gives a unique id to each new object

public:
    // constructor
    Tracker(string n) {
        id = nextId++;
        name = n;
        count++;
        cout << "Object created: " << name << " (id = " << id << ")\n";
    }

    // copy constructor
    Tracker(const Tracker &other) {
        id = nextId++;
        name = other.name; 
        count++;
        cout << "Copy made from id " << other.id << " to new id " << id << "\n";
    }

    // destructor
    ~Tracker() {
        cout << "Object destroyed: id = " << id << "\n";
        count--;
    }

    static int getActiveCount() {
        return count;
    }
};

// static members
int Tracker::count = 0;
int Tracker::nextId = 1;

// returns an object
Tracker makeOne() {
    Tracker t("TempObj");
    return t;
}

// takes object by value
void useOne(Tracker t) {
    cout << "Using tracker with id = " << t.id << "\n";
}

int main1() {
    cout << "Creating objects...\n";
    Tracker a("First");
    Tracker b("Second");
    cout << "Active = " << Tracker::getActiveCount() << "\n\n";

    cout << "Copying object...\n";
    Tracker c = a;
    cout << "Active = " << Tracker::getActiveCount() << "\n\n";

    cout << "Object returned from function...\n";
    Tracker d = makeOne();
    cout << "Active = " << Tracker::getActiveCount() << "\n\n";

    cout << "Passing object to function...\n";
    useOne(b);
    cout << "Active = " << Tracker::getActiveCount() << "\n\n";

    cout << "Block scope demo...\n";
    {
        Tracker e("Block1");
        Tracker f("Block2");
        cout << "Active inside block = " << Tracker::getActiveCount() << "\n";
    } // e and f destroyed here
    cout << "Active after block = " << Tracker::getActiveCount() << "\n";

    return 0;
}


#include <iostream>
using namespace std;

class SessionManager {
public:
    int sessionId;                  
    static int activeSessions;      
    static int nextSessionId;       

    // constructor
    SessionManager() {
        sessionId = nextSessionId++;
        activeSessions++;
        cout << "New session started (id = " << sessionId << ")\n";
    }

    // copy constructor
    SessionManager(const SessionManager &other) {
        sessionId = nextSessionId++;
        activeSessions++;
        cout << "Session copied from id " << other.sessionId 
             << " to new id " << sessionId << "\n";
    }

    // destructor
    ~SessionManager() {
        cout << "Session ended (id = " << sessionId << ")\n";
        activeSessions--;
    }

    // return new session
    SessionManager makeSession() {
        SessionManager s;
        return s;
    }

    // take session by value
    void handle(SessionManager s) {
        cout << "Handling session id = " << s.sessionId << "\n";
    }
};

// initialize static members
int SessionManager::activeSessions = 0;
int SessionManager::nextSessionId = 1;

int main() {
    cout << "Creating a few sessions...\n";
    SessionManager s1, s2, s3;
    cout << "Currently active: " << SessionManager::activeSessions << "\n\n";

    cout << "Copying a session...\n";
    SessionManager s4 = s2;
    cout << "Currently active: " << SessionManager::activeSessions << "\n\n";

    cout << "Starting a session from inside function...\n";
    SessionManager s5 = s1.makeSession();
    cout << "Currently active: " << SessionManager::activeSessions << "\n\n";

    cout << "Passing session to a function...\n";
    s3.handle(s1);
    cout << "Currently active: " << SessionManager::activeSessions << "\n\n";

    cout << "Block scope example...\n";
    {
        SessionManager s6, s7;
        cout << "Active inside block: " << SessionManager::activeSessions << "\n";
    } // s6, s7 destroyed here
    cout << "Active after block: " << SessionManager::activeSessions << "\n";

    return 0;
}


// int main(){
//     main2();
// }