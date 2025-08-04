#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }


        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void rangeSearch(Node* node, int low, int high, vector<int>& result) {
        if (!node) return;

        
        if (node->key > low)
            rangeSearch(node->left, low, high, result);

        
        if (node->key >= low && node->key <= high)
            result.push_back(node->key);

    
        if (node->key < high)
            rangeSearch(node->right, low, high, result);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    vector<int> rangeQuery(int low, int high) {
        vector<int> result;
        rangeSearch(root, low, high, result);
        return result;
    }
};

int main() {
    AVLTree tree;
    ifstream infile("input.txt");
    vector<int> keys;
    int key;
    while (infile >> key) {
        keys.push_back(key);
    }

    for (int key : keys) {
        tree.insert(key);
    }

    vector<int> inRange = tree.rangeQuery(18, 77);

    cout << "Nodes in range [18,77]: ";
    for (int val : inRange) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}