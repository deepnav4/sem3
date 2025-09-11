#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertAtHead(Node *&head,int data){
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtAnyPos(Node *&head,int data,int pos){
    if(pos == 1) insertAtHead(head,data);
    Node* temp = new Node(data);
    Node* startPtr = head;
    for(int i=1; i<pos-1; i++){
        startPtr = startPtr->next;
    }
    Node* after = startPtr->next;
    startPtr->next = temp;
    temp->next = after;
}

void printLL(Node *head){
    Node* temp = head;
    while(temp->next != head){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    insertAtAnyPos(head,60,6);
    printLL(head);
}