#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    string songTitle;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string title) {
        this->songTitle = title;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* insertSong(TreeNode *root, string newSong) {
    if (!root) return new TreeNode(newSong);
    if (newSong < root->songTitle) root->left = insertSong(root->left, newSong);
    else if (newSong > root->songTitle) root->right = insertSong(root->right, newSong);
    return root;
}

void rangeFilter(TreeNode *root, string low, string high, vector<string>& result) {
    if (!root) return;
    if (root->songTitle > low) rangeFilter(root->left, low, high, result);
    if (root->songTitle >= low && root->songTitle <= high)
        result.push_back(root->songTitle);
    if (root->songTitle < high) rangeFilter(root->right, low, high, result);
}

TreeNode* findMin(TreeNode *root) {
    while (root && root->left) root = root->left;
    return root;
}

TreeNode* deleteSong(TreeNode *root, string songTitle) {
    if (!root) return NULL;
    if (songTitle < root->songTitle)  root->left = deleteSong(root->left, songTitle);
    else if (songTitle > root->songTitle)  root->right = deleteSong(root->right, songTitle);
    else {
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        } 
        else if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } 
        else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } 
        else {
            TreeNode* succ = findMin(root->right);
            root->songTitle = succ->songTitle;
            root->right = deleteSong(root->right, succ->songTitle);
        }
    }
    return root;
}

int main() {
    TreeNode *root = NULL;
    root = insertSong(root, "D");
    insertSong(root, "B");
    insertSong(root, "F");
    insertSong(root, "A");
    insertSong(root, "C");
    insertSong(root, "E");
    insertSong(root, "G");

    vector<string> result;
    rangeFilter(root, "B", "F", result);
    cout << "Songs in range B to F: ";
    for (const string &song : result)
        cout << song << " ";
    cout << endl;

    root = deleteSong(root, "D");
    result.clear();
    rangeFilter(root, "A", "G", result);
    cout << "Songs after deleting D: ";
    for (const string &song : result)
        cout << song << " ";
    cout << endl;

    return 0;
}
