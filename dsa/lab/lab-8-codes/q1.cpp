// A Human Resources application needs to visualize the company's organizational chart, which can be modeled as a binary tree where each node represents an employee.
// Scenario: Management wants to know the "maximum depth" of the organization (the longest chain of command from the CEO to the lowest employee) to ensure the structure isn't too flat or too deep.
// Assignment: Write a function calculateMaxDepth(root) to find the height of the binary tree. Furthermore, write a function isBalanced(root) to determine if the organization's structure is "balanced" (height difference of any two subtrees at any node is at most one), as unbalanced structures can be inefficient.


#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

int calculateMaxDepth(TreeNode *root){
    if(!root) return 0;
    return 1 + max(calculateMaxDepth(root->left),calculateMaxDepth(root->right));
}

bool isBalanced(TreeNode* root){
    if(!root) return true;
    int leftHeight = calculateMaxDepth(root->left);
    int rightHeight = calculateMaxDepth(root->right);
    if(abs(leftHeight - rightHeight) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

void levelOrderTraverse(TreeNode* root,vector<vector<int>>&result){
    if(!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> currentLevel;
        for(int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        result.push_back(currentLevel);
    }
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout<<"Max Depth: "<<calculateMaxDepth(root)<<endl;
    if(isBalanced(root)){
        cout<<"The tree is balanced"<<endl;
    }
    else{
        cout<<"The tree is not balanced"<<endl;
    }
    vector<vector<int>> ans;
    levelOrderTraverse(root,ans);
    cout<<"Level Order Traversal: "<<endl;
    for(auto level : ans){
        for(auto val : level){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}
