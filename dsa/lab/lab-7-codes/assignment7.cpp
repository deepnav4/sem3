// Q1 : Implement push and pop operations of stack using array and linked list
// Q2:  Implement  insertion and deletion operations of queue using array and linked list


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

class StackUsingArray{
    public:
    int* arr;
    int top;
    int n;

    StackUsingArray(int n){
        arr = new int[n];
        top = -1;
    }

    void insert(int num){
        if(top == n){
            cout<<"Stack is FULL !!";
            return; 
        }
        top++;
        arr[top] = num;
    }

    int getTop(){
        return arr[top];
    }

    int pop(){
        int elem = arr[top];
        top--;
        return elem;
    }

    void print(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};



class StackUsingLL{
    public :
    Node *node;

    StackUsingLL(){
        node = NULL;
    }

    void insert(int num){
        Node* newNode = new Node(num);
        if(node == NULL){
            node = newNode;
            return;
        }
        newNode->next = node;
        node = newNode;
    }

    int getTop(){
        return node->data;
    }

    int pop(){
        int elem = node->data;
        Node* temp = node;
        node = node->next;
        delete temp;
        return elem;
    }

    void print(){
        Node* temp = node;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};


int main(){
    StackUsingArray s(5);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    cout<<s.getTop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.getTop()<<endl;
    s.print();

    StackUsingLL s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    cout<<s1.getTop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.getTop()<<endl;
    s1.print();
    return 0;
}