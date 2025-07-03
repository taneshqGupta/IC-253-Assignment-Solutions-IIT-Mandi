#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int val) : key(val), height(1), left(NULL), right(NULL) {}
};

class AVLTree {
    Node* root;

    int height(Node* n) {
        return n ? n->height : 0;
    }

    int balanceFactor(Node* n) {
        return height(n->left) - height(n->right);
    }

    void updateHeight(Node* n) {
        n->height = 1 + max(height(n->left), height(n->right));
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);
        updateHeight(node);
        int balance = balanceFactor(node);
        if (balance > 1 && key < node->left->key)
            return rotateRight(node);
        if (balance < -1 && key > node->right->key)
            return rotateLeft(node);
        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    void inorder(Node* node, vector<int>& res) {
        if (!node) return;
        inorder(node->left, res);
        res.push_back(node->key);
        inorder(node->right, res);
    }

public:
    AVLTree() : root(NULL) {}

    void insert(int key) {
        root = insert(root, key);
    }

    vector<int> inorder() {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n = 10;
    while (true) {
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 1);
        shuffle(perm.begin(), perm.end(), mt19937(random_device{}()));

        AVLTree tree;
        auto t1 = high_resolution_clock::now();
        for (int x : perm) tree.insert(x);
        vector<int> avl_sorted = tree.inorder();
        auto t2 = high_resolution_clock::now();

        vector<int> to_sort = perm;
        auto t3 = high_resolution_clock::now();
        insertionSort(to_sort);
        auto t4 = high_resolution_clock::now();

        auto avl_time = duration_cast<microseconds>(t2 - t1).count();
        auto ins_time = duration_cast<microseconds>(t4 - t3).count();

        cout << "n = " << n << ", AVL: " << avl_time << " µs, Insertion: " << ins_time << " µs\n";
        if (avl_time < ins_time) {
            cout << "n₀ = " << n << " is the smallest where AVL is faster\n";
            break;
        }
        n++;
    }
    return 0;
}
