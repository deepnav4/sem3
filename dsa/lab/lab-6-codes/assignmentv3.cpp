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
    if (!head) return;
    int n = getLength(head);

    Node* temp = head;
    for (int i = 0; i < n; i++) {
        cout << temp->data << " " << temp->next->data << " " << temp->next->next->data << " , ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(9);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(7);

    // Linking forward
    head->next = n2; n2->next = n3; n3->next = n4; n4->next = head;
    // Linking backward
    head->prev = n4; n2->prev = head; n3->prev = n2; n4->prev = n3;

    printInPattern(head);  // pattern output
    printLL(head);         // full circular LL
}
