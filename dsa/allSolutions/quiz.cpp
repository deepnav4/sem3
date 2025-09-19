// #include <bits/stdc++.h>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* prev;
//     Node* next;

//     Node(int data) {
//         this->data = data;
//         this->prev = NULL;
//         this->next = NULL;
//     }
// };

// // 1. Insert a node in sorted order
// void insertNode(Node* &head, int data) {
//     Node* newNode = new Node(data);

//     // case: empty list
//     if (head == NULL) {
//         head = newNode;
//         return;
//     }

//     // case: insert at head
//     if (data <= head->data) {
//         newNode->next = head;
//         head->prev = newNode;
//         head = newNode;
//         return;
//     }

//     Node* temp = head;
//     while (temp->next != NULL && temp->next->data < data) {
//         temp = temp->next;
//     }

//     newNode->next = temp->next;
//     if (temp->next != NULL) {
//         temp->next->prev = newNode;
//     }
//     temp->next = newNode;
//     newNode->prev = temp;
// }

// // 2. Delete all occurrences of a given key
// void deleteAllOccurrences(Node* &head, int key) {
//     Node* temp = head;

//     while (temp != NULL) {
//         if (temp->data == key) {
//             Node* toDelete = temp;

//             if (temp->prev != NULL) temp->prev->next = temp->next;
//             else head = temp->next; // deleting head

//             if (temp->next != NULL) temp->next->prev = temp->prev;

//             temp = temp->next;
//             delete toDelete;
//         } else {
//             temp = temp->next;
//         }
//     }
// }

// // 3. Reverse the doubly linked list
// Node* reverse(Node* &head) {
//     Node* prev = NULL;
//     Node* curr = head;
//     Node* next = NULL;

//     while (curr != NULL) {
//         next = curr->next;
//         curr->next = prev;
//         curr->prev = next;
//         prev = curr;
//         curr = next;
//     }
//     head = prev;
//     return head;
// }

// // Utility to print list
// void printList(Node* head) {
//     Node* temp = head;
//     while (temp != NULL) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << "\n";
// }

// int main() {
//     Node* head = NULL;

//     insertNode(head, 5);
//     insertNode(head, 3);
//     insertNode(head, 8);
//     insertNode(head, 3);
//     insertNode(head, 1);

//     cout << "List after insertion: ";
//     printList(head);

//     deleteAllOccurrences(head, 3);
//     cout << "List after deleting 3s: ";
//     printList(head);

//     head = reverse(head);
//     cout << "List after reversal: ";
//     printList(head);

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main(){
    string startWord = "cold";
    string endWord = "warm";
    vector<string>ans;

    for(int i=0; i<startWord.size(); i++){
        char orgWord = startWord[i];
        for(char ch='a'; ch<='z'; ch++){
            if(ch == orgWord) continue; // skip same letter
            startWord[i] = ch;

            if(startWord == endWord){   // ✅ full word check
                ans.push_back(startWord);
            }
        }
        startWord[i] = orgWord; // restore original character
    }

    for(auto &s : ans){
        cout << s << " ";
    }
}
