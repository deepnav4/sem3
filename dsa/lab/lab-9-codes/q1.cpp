#include <bits/stdc++.h>
using namespace std;

class TwoThreeNode {
    public:
        vector<string> keys;
        vector<TwoThreeNode*> children;
        bool isLeaf;

        TwoThreeNode(bool leaf = true) {
            isLeaf = leaf;
        }
};

class TwoThreeTree {
    public:
        TwoThreeNode* root;

        TwoThreeTree() {
            root = nullptr;
        }

        void insert(const string &key) {
            if (!root) {
                root = new TwoThreeNode(true);
                root->keys.push_back(key);
                cout << "Inserted \"" << key << "\" as root.\n";
            } else {
                if (root->keys.size() == 2) {
                    TwoThreeNode* newRoot = new TwoThreeNode(false);
                    newRoot->children.push_back(root);
                    splitChild(newRoot, 0);
                    root = newRoot;
                    cout << "Root split during insertion of \"" << key << "\".\n";
                }
                insertNonFull(root, key);
            }
        }

    private:
        void splitChild(TwoThreeNode* parent, int index) {
            TwoThreeNode* fullChild = parent->children[index];
            TwoThreeNode* newChild = new TwoThreeNode(fullChild->isLeaf);

            parent->keys.insert(parent->keys.begin() + index, fullChild->keys[1]);
            parent->children.insert(parent->children.begin() + index + 1, newChild);

            if (fullChild->keys.size() > 2)
                newChild->keys.push_back(fullChild->keys[2]);
            fullChild->keys.pop_back();
            fullChild->keys.pop_back();

            if (!fullChild->isLeaf) {
                newChild->children.push_back(fullChild->children[2]);
                newChild->children.push_back(fullChild->children[3]);
                fullChild->children.pop_back();
                fullChild->children.pop_back();
            }
        }

        void insertNonFull(TwoThreeNode* node, const string &key) {
            if (node->isLeaf) {
                node->keys.push_back(key);
                sort(node->keys.begin(), node->keys.end());
                cout << "Inserted \"" << key << "\" into leaf node with keys: ";
                for (auto &k : node->keys) cout << k << " ";
                cout << endl;
            } else {
                int i = node->keys.size() - 1;
                while (i >= 0 && key < node->keys[i]) i--;
                i++;
                if (node->children[i]->keys.size() == 2) {
                    splitChild(node, i);
                    if (key > node->keys[i]) i++;
                }
                insertNonFull(node->children[i], key);
            }
        }
};

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        int height;

        TreeNode(int data) {
            this->data = data;
            this->left = this->right = NULL;
            this->height = 1;
        }
};

int getHeight(TreeNode* node) {
    if(!node) return 0;
    return node->height;
}

int getBalanceFactor(TreeNode* node) {
    if(!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    cout << "Performed RIGHT rotation at node " << y->data << endl;
    return x;
}

TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    cout << "Performed LEFT rotation at node " << x->data << endl;
    return y;
}

TreeNode* insertNode(TreeNode* root, int key) {
    if (!root) {
        cout << "Inserted " << key << " as new node.\n";
        return new TreeNode(key);
    }

    if (key < root->data) {
        cout << "Going LEFT from " << root->data << " to insert " << key << endl;
        root->left = insertNode(root->left, key);
    } 
    else if (key > root->data) {
        cout << "Going RIGHT from " << root->data << " to insert " << key << endl;
        root->right = insertNode(root->right, key);
    } 
    else return root; 

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalanceFactor(root);

    if (balance > 1 && key < root->left->data) {
        cout << "Left-Left case at " << root->data << endl;
        return rightRotate(root);
    }
    if (balance < -1 && key > root->right->data) {
        cout << "Right-Right case at " << root->data << endl;
        return leftRotate(root);
    }
    if (balance > 1 && key > root->left->data) {
        cout << "Left-Right case at " << root->data << endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key < root->right->data) {
        cout << "Right-Left case at " << root->data << endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void levelOrderTraverse(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            TreeNode* node = q.front(); q.pop();
            cout << node->data << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

int main() {
    TwoThreeTree t23;
    vector<string> data23 = {"C", "A", "B", "E", "D"};
    for (auto &val : data23) t23.insert(val);

    TreeNode* root = NULL;
    vector<int> vals = {10, 20, 30, 40, 50, 25};
    for (int val : vals) {
        cout << "\nInserting " << val << "...\n";
        root = insertNode(root, val);
    }

    cout << "\nLevel Order :\n";
    levelOrderTraverse(root);
}
