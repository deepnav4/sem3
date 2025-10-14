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

class QueueUsingArr{
    public :
        int n;
        int *arr;
        int front;
        int rear;

        QueueUsingArr(int n){
            this->n = n;
            arr = new int[n];
            front = -1;
            rear = -1;
        }


        void enqueue(int data){
            if((rear+1)%n == front){
                cout<<"Queue is FULL !!"<<endl;
                return;
            }
            if(front == -1) front = 0;
            rear = (rear+1)%n;
            arr[rear] = data;
        }

        int dequeue(){
            if(front == -1){
                cout<<"Queue is EMPTY !!"<<endl;
                return -1;
            }
            int elem = arr[front];
            if(front == rear){
                front = -1;
                rear = -1;
            } 
            else {
                front = (front+1)%n;
            }
            return elem;
        }

        void print(){
            for(int i=front; i<=rear; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};




class QueueUsingLL {
public:
    Node *front;
    Node *rear;

    QueueUsingLL() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int data) {
        Node *temp = new Node(data);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    int dequeue() {
        if (front == NULL) {
            cout << "Queue is Empty!!" << endl;
            return -1;
        }

        int elemToDel = front->data;
        Node *temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp; 
        return elemToDel;
    }

    void print() {
        if (front == NULL) {
            cout << "Queue is Empty!!" << endl;
            return;
        }

        Node *temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};



int main(){
    QueueUsingArr q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(4);
    q.dequeue();
    q.print();

    QueueUsingLL q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(4);
    q1.dequeue();
    q1.print();
}

