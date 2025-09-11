// Q1: (a) Implement insertion and deletion in doubly linked list
//        (b) Implemet insertion and deletion in circular linked list

#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
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

void insertAtTail(Node *&head,int data){
    Node* temp = new Node(data);
    Node* startPtr = head;
    while(startPtr->next != NULL){
        startPtr = startPtr->next;
    }
    startPtr->next = temp;
    temp->prev = startPtr;
}

void insertAtPosition(int pos,Node* &head,int data){
    if(pos==1) insertAtHead(head,data);
    if(pos==getLength(head)) insertAtTail(head,data);
    Node* temp = new Node(data);
    Node* startPtr = head;
    for(int i=1; i<pos-1; i++){
        startPtr = startPtr->next;
        if(!temp) return ;
    }
    Node* after = startPtr->next;
    startPtr->next = temp;
    temp->prev = startPtr;
    after->prev = temp;
    temp->next =after;
}

void printLL(Node* head){
    Node* temp = head;
    cout<<"Printing A LL : ";
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void deleteFromHead(Node* &head){
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete(temp);
}

void deleteFromEnd(Node *&head){
    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    Node* nodeToDel = temp->next;
    temp->next = NULL;
    delete(nodeToDel);
}

void deleteFromPos(Node *&head,int pos){
    if(pos == 1) deleteFromHead(head);
    if(pos == getLength(head)) deleteFromEnd(head);
    Node* startPtr = head;
    for(int i=1; i<pos-1; i++){
        startPtr = startPtr->next;
    }
    Node* nodeToDel = startPtr->next;
    Node* after = nodeToDel->next;
    startPtr->next = after;
    after->prev = startPtr;
    delete(nodeToDel);
}

int main(){
    Node* head = new Node(10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtTail(head,50);
    insertAtTail(head,60);
    insertAtPosition(3,head,90);
    deleteFromHead(head);
    deleteFromEnd(head);
    deleteFromPos(head,1);
    deleteFromPos(head,2);
    printLL(head);
}













///////////////////////////////////////////////////////
//circular Link List
