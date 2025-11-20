#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

typedef pair<int, ListNode*> P;

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<P, vector<P>, greater<P>> pq;

    for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != nullptr) {
            pq.push({lists[i]->val, lists[i]});
        }
    }

    ListNode* head = new ListNode(-1);
    ListNode* tail = head;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int val = top.first;
        ListNode* node = top.second;

        tail->next = node;
        tail = tail->next;

        if (node->next != nullptr) {
            pq.push({node->next->val, node->next});
        }
    }

    return head->next;
}

void printLL(ListNode* node) {
    ListNode* temp = node;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<ListNode*> lists;

    ListNode* node1 = new ListNode(3);
    node1->next = new ListNode(4);
    node1->next->next = new ListNode(5);
    node1->next->next->next = new ListNode(6);

    ListNode* node2 = new ListNode(9);
    node2->next = new ListNode(15);
    node2->next->next = new ListNode(17);
    node2->next->next->next = new ListNode(18);

    ListNode* node3 = new ListNode(7);
    node3->next = new ListNode(8);
    node3->next->next = new ListNode(10);
    node3->next->next->next = new ListNode(12);

    lists.push_back(node1);
    lists.push_back(node2);
    lists.push_back(node3);

    ListNode* ans = mergeKLists(lists);
    printLL(ans);
}
