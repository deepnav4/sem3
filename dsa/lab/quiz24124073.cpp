#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node* other;
    Node(int data){ 
        this->data = data;
        this->other = NULL;
        this->next = NULL;  
    }
};

void mergeTwoMultiList(Node* h1, Node* h2, Node* &mergeList){
    // Connect horizontally
    Node* t1 = h1;
    while(t1->next) t1 = t1->next;
    t1->next = h2;

    // Connect vertically level 2
    t1 = h1->other;
    Node* t2 = h2->other;
    while(t1->next) t1 = t1->next;
    t1->next = t2;

    t1 = h1->other->other;
    t2 = h2->other->other; 
    while(t1->next) t1 = t1->next;
    t1->next = t2;

    Node* dummy = new Node(-1);
    Node* tail = dummy;

    Node* arr[3];
    arr[0] = h1;
    arr[1] = h1->other;
    arr[2] = h1->other->other;

    for(int lvl = 0; lvl < 3; lvl++){
        Node* temp = arr[lvl];
        while(temp&&temp->next){
            tail->next = new Node(temp->data);
            tail = tail->next;
            temp = temp->next->next;
        }
    }

    mergeList = dummy->next;
    delete dummy;
}

void printList(Node * head){
    Node * temp = head;
    while(temp){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

int main(){

    // Creating multi List one
    Node *node1 = new Node(49);
    node1->next = new Node(43);
    node1->next->next = new Node(41);

    Node *node2 = new Node(13);
    node2->next = new Node(12);
    node2->next->next = new Node(11);

    Node *node3 = new Node(37);
    node3->next = new Node(31);
    node3->next->next = new Node(38);
    node3->next->next->next = new Node(36);

    node1->other = node2;
    node2->other = node3;

    // creating multi list 2
    Node *node11 = new Node(29);
    node11->next = new Node(23);
    node11->next->next = new Node(27);
    node11->next->next->next = new Node(24);

    Node *node22 = new Node(9);
    node22->next = new Node(3);
    node22->next->next = new Node(7);

    Node *node33 = new Node(59);
    node33->next = new Node(53);
    node33->next->next = new Node(55);

    node11->other = node22;
    node22->other = node33;

    // merge
    Node* mergeList = NULL;
    mergeTwoMultiList(node1,node11,mergeList);

    // print merged list
    printList(mergeList);
}
