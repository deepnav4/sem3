#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printLL(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int getLength(Node* head) {
    if (!head) return 0;
    Node* temp = head;
    int count = 0;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

void printInPattern(Node* head) {
    int n = getLength(head);
    if (n < 3) {
        cout << "Not enough nodes for pattern!" << endl;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < n; i++) {
        cout << temp->data << " " << temp->next->data << " " << temp->next->next->data;
        if (i != n - 1) cout << " , ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(9);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(7);

    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = head; head->prev = n4;

    cout << "Pattern Output:" << endl;
    printInPattern(head);

    cout << "Full Circular List:" << endl;
    printLL(head);

    return 0;
}
