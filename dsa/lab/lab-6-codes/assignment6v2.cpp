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

int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    if (head) {
        temp->next = head;
        head->prev = temp;
    }
    head = temp;
}

void insertAtTail(Node* &head, int data) {
    Node* temp = new Node(data);
    if (!head) {
        head = temp;
        return;
    }
    Node* startPtr = head;
    while (startPtr->next) {
        startPtr = startPtr->next;
    }
    startPtr->next = temp;
    temp->prev = startPtr;
}

void insertAtPosition(int pos, Node* &head, int data) {
    if (pos == 1) {
        insertAtHead(head, data);
        return;
    }
    int len = getLength(head);
    if (pos == len + 1) {
        insertAtTail(head, data);
        return;
    }
    if (pos < 1 || pos > len + 1) return; // invalid

    Node* temp = new Node(data);
    Node* startPtr = head;
    for (int i = 1; i < pos - 1; i++) {
        startPtr = startPtr->next;
    }
    Node* after = startPtr->next;
    startPtr->next = temp;
    temp->prev = startPtr;
    if (after) {
        after->prev = temp;
        temp->next = after;
    }
}

void deleteFromHead(Node* &head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    delete temp;
}

void deleteFromEnd(Node* &head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteFromPos(Node* &head, int pos) {
    if (!head) return;
    if (pos == 1) {
        deleteFromHead(head);
        return;
    }
    int len = getLength(head);
    if (pos == len) {
        deleteFromEnd(head);
        return;
    }
    if (pos < 1 || pos > len) return; // invalid

    Node* startPtr = head;
    for (int i = 1; i < pos - 1; i++) {
        startPtr = startPtr->next;
    }
    Node* nodeToDel = startPtr->next;
    Node* after = nodeToDel->next;
    startPtr->next = after;
    if (after) after->prev = startPtr;
    delete nodeToDel;
}

void printLL(Node* head) {
    Node* temp = head;
    cout << "Printing LL : ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);
    insertAtPosition(3, head, 90);

    printLL(head);

    deleteFromHead(head);
    printLL(head);

    deleteFromEnd(head);
    printLL(head);

    deleteFromPos(head, 1);
    printLL(head);

    deleteFromPos(head, 2);
    printLL(head);

    return 0;
}
