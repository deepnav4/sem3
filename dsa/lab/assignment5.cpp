#include <bits/stdc++.h>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at the head of the list
void insertAtHead(Node*& head, int data) {
    cout << "Insert at Head Function Called\n";
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

// Insert at the tail of the list
void insertAtTail(Node*& head, int data) {
    cout << "Insert at Tail Function Called\n";
    Node* temp = new Node(data);
    if (!head) {
        head = temp;
        return;
    }
    Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = temp;
}

// Insert at a specific position
void insertInLL(Node*& head, int data, int position) {
    cout << "Insert in LL Function Called\n";
    if (position == 1) {
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp; i++) {
        temp = temp->next;
    }
    if (!temp) { // position beyond length → insert at tail
        insertAtTail(head, data);
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from head
void deleteFromHead(Node*& head) {
    if (!head) return;
    Node* nodeToDel = head;
    head = head->next;
    delete nodeToDel;
}

// Delete from tail
void deleteFromTail(Node*& head) {
    if (!head) return;
    if (!head->next) { // only one node
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    Node* nodeToDel = temp->next;
    temp->next = NULL;
    delete nodeToDel;
}

// Search for a key in the list
Node* searchInLL(Node* head, int key) {
    Node* temp = head;
    while (temp) {
        if (temp->data == key) return temp;
        temp = temp->next;
    }
    return NULL;
}

// Delete from a specific position
void deleteFromPosition(Node*& head, int position) {
    if (position == 1) {
        deleteFromHead(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp; i++) {
        temp = temp->next;
    }
    if (!temp || !temp->next) return; // invalid position
    Node* nodeToDel = temp->next;
    temp->next = temp->next->next;
    delete nodeToDel;
}

// Print the linked list
void printLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Delete the entire linked list
void deleteLL(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "Linked List deleted successfully.\n";
}

// Driver function
int main() {
    Node* node = new Node(10);  // initial node
    cout << "Initial list: ";
    printLL(node);

    insertAtHead(node, 40);
    insertAtHead(node, 50);
    insertAtHead(node, 60);
    insertAtTail(node, 30);
    insertInLL(node, 20, 3);
    insertInLL(node, 70, 7);

    cout << "List after insertions: ";
    printLL(node);

    deleteFromHead(node);
    deleteFromHead(node);
    deleteFromHead(node);
    deleteFromTail(node);
    deleteFromPosition(node, 3);

    cout << "List after deletions: ";
    printLL(node);

    if (searchInLL(node, 20)) cout << "Found 20\n";
    else cout << "20 Not Found\n";

    if (searchInLL(node, 50)) cout << "Found 50\n";
    else cout << "50 Not Found\n";

    deleteLL(node); // cleanup
    return 0;
}



// Q1: Given pointers to the head nodes of linked lists that merge together at some point, find the node
// where the two lists merge. The merge point is where both lists point to the same node, i.e. they
// reference the same memory location. It is guaranteed that the two head nodes will be different, and
// neither will be NULL. If the lists share a common node, return that node&#39;s  data value.

int lengthOfList(Node *head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
}

// Node* mergeNode(Node *h1,Node *h2){
//     if(!h1 || !h2) return NULL;
//     int len1 = lengthOfList(h1);
//     int len2 = lengthOfList(h2);
//     int diff = abs(len1-len2);
//     if(diff>0)
// }


// int main(){
//     int a[] = {1,2,3,4,5};
//     int b = -3[a];
//     cout<<b;
// }                                                       