#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public :
    int folder;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int folder){
        this->folder = folder;
        this->left = NULL;
        this->right = NULL;
    }
};

void simpleBFS(TreeNode *root,vector<int>&ans){
    if(!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        ans.push_back(curr->folder);

        if(curr->right) q.push(curr->right);
        if(curr->left) q.push(curr->left);
    }

}


// main ques is to explore the deepest folder first
void reverseBFS(TreeNode* root,vector<int>&ans){
    if(!root) return;

    queue<TreeNode*> q;
    stack<int>st;
    q.push(root);

    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        st.push(curr->folder);

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(7);
    root->left->right = new  TreeNode(8);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(11);
    vector<int>ans;
    // simpleBFS(root,ans);
    reverseBFS(root,ans);
    for(auto elem : ans){
        cout<<elem <<" ";
    }
    cout<<endl;
}