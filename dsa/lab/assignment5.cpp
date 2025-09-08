#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertAtHead(Node*&head,int data){
    cout<<"Insert at Head Function Called : \n";
    if(!head){
        head = new Node(data);
        return;
    }
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node*&head,int data){
    cout<<"Insert at Tail Function Called : \n";
    if(!head){
        head = new Node(data);
        return;
    }
    Node* temp = new Node(data);
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = temp;
}

void insertInLL(Node *&head,int data,int position){
    cout<<"Insert in LL Function Called : \n";
    if(position == 1){
        insertAtHead(head,data);
        return;
    }
    Node *temp = head;
    for(int i=1; i<position-1; i++){
        if(!temp) return;
        temp = temp->next;
    }
    if(!temp->next) return insertAtTail(head,data); 
    Node * newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromHead(Node *&head){
    if(!head) return;
    Node *nodeToDel = head;
    head = head->next;
    delete(nodeToDel);
}

void deleteFromTail(Node *&head){
    Node *temp = head;
    if(!head) return;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node *nodeToDel = temp->next;
    temp->next = NULL;
    delete(nodeToDel);
}

Node* searchInLL(Node *head,int key){
    Node *temp = head;
    while(temp){
        if(temp->data == key) return temp;
        temp = temp->next;
    }
    return NULL;
}

void deleteFromPosition(Node *&head,int position){
    if(position == 1){
        deleteFromHead(head);
        return;
    }
    Node *temp = head;
    for(int i=1; i<position-1; i++){
        if(!temp) return;
        temp = temp->next;
    }
    if(!temp->next) return;
    Node *nodeToDel = temp->next;
    temp->next = temp->next->next;
    delete(nodeToDel);
}


// Traverse a Link List
void printLL(Node *head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}



int main1(){
    Node* node = new Node(10);
    insertAtHead(node,40);
    insertAtHead(node,50);
    insertAtHead(node,60);
    insertAtTail(node,30);
    insertInLL(node,20,3);
    insertInLL(node,70,7);
    deleteFromHead(node);
    deleteFromHead(node);
    deleteFromHead(node);
    deleteFromTail(node);
    deleteFromPosition(node,3);
    if(searchInLL(node,20)) cout<<"Found\n";
    else cout<<"Not Found\n";
    printLL(node);
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


int main(){
    int a[] = {1,2,3,4,5};
    int b = -3[a];
    cout<<b;
}                                                       