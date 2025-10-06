#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // move slow by one step
        fast = fast->next->next;     // move fast by two steps
        if (slow == fast) return true; // cycle detected
    }
    return false; // no cycle found
}

int main() {
    // Creating example list: 1->2->3->4->5->3(cycle)
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating a cycle for demo (node 5 points to node 3)
    head->next->next->next->next->next = head->next->next;

    if (hasCycle(head))
        cout << "Cycle detected!" << endl;
    else
        cout << "No cycle." << endl;

    // Cleanup omitted for brevity

    return 0;
}


// lb 6
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    int duration;
    Node* next;
    Node* prev;
    Node(int _id, int _dur) : id(_id), duration(_dur), next(nullptr), prev(nullptr) {}
};

class CircularPlaylist {
    unordered_map<int, Node*> songs;
    Node* head = nullptr;

public:
    void AddSongAfter(int X, int Y, int D) {
        Node* newSong = new Node(Y, D);

        // If playlist is empty (first song)
        if (head == nullptr) {
            head = newSong;
            newSong->next = newSong;
            newSong->prev = newSong;
        } else {
            Node* curr = songs[X];
            Node* nxt = curr->next;
            curr->next = newSong;
            newSong->prev = curr;
            newSong->next = nxt;
            nxt->prev = newSong;
        }

        songs[Y] = newSong;
    }

    void RemoveSong(int X) {
        if (songs.find(X) == songs.end()) return;
        Node* node = songs[X];

        // If only one node
        if (node->next == node) {
            head = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            if (head == node) head = node->next;
        }

        songs.erase(X);
        delete node;
    }

    void PlayFrom(int X, int T) {
        Node* curr = songs[X];
        int total = 0;
        vector<int> played;

        while (total < T) {
            played.push_back(curr->id);
            total += curr->duration;
            curr = curr->next;
        }

        for (int i = 0; i < played.size(); i++) {
            cout << played[i];
            if (i != played.size() - 1) cout << " ";
        }
        cout << endl;
    }
};

int main() {
    int Q;
    cin >> Q;

    CircularPlaylist playlist;
    for (int i = 0; i < Q; i++) {
        string op;
        cin >> op;
        if (op == "AddSongAfter") {
            int X, Y, D;
            cin >> X >> Y >> D;
            playlist.AddSongAfter(X, Y, D);
        } else if (op == "RemoveSong") {
            int X;
            cin >> X;
            playlist.RemoveSong(X);
        } else if (op == "PlayFrom") {
            int X, T;
            cin >> X >> T;
            playlist.PlayFrom(X, T);
        }
    }
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> out;
    int x;
    while (cin >> x) out.push_back(x);
    int n = out.size();

    for (int sz = 1; sz <= n / 3; ++sz) {
        vector<int> cand(out.begin(), out.begin() + sz);
        // Simulate output
        bool ok = true;
        for (int i = 0; i + 2 < n; ++i)
            if (out[i] != cand[(i % sz)])
                ok = false;
        if (ok) {
            cout << sz << endl;
            for (int v : cand) cout << v << " ";
            cout << endl;
            break;
        }
    }
    return 0;
}

