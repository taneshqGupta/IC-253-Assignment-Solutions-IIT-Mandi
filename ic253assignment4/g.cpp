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

    void inorder(Node* node, int* res, int &idx) {
        if (!node) return;
        inorder(node->left, res, idx);
        res[idx++] = node->key;
        inorder(node->right, res, idx);
    }

public:
    AVLTree() : root(NULL) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void inorder(int* res, int &idx) {
        idx = 0;
        inorder(root, res, idx);
    }
};

void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void shuffleArray(int* arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

int main() {
    srand(time(NULL));
    int n = 10;
    while (true) {
        int* perm = new int[n];
        for (int i = 0; i < n; i++) perm[i] = i + 1;
        shuffleArray(perm, n);

        AVLTree tree;
        auto t1 = high_resolution_clock::now();
        for (int i = 0; i < n; i++) tree.insert(perm[i]);
        int* avl_sorted = new int[n];
        int idx;
        tree.inorder(avl_sorted, idx);
        auto t2 = high_resolution_clock::now();

        int* copy = new int[n];
        for (int i = 0; i < n; i++) copy[i] = perm[i];
        auto t3 = high_resolution_clock::now();
        insertionSort(copy, n);
        auto t4 = high_resolution_clock::now();

        auto avl_time = duration_cast<microseconds>(t2 - t1).count();
        auto ins_time = duration_cast<microseconds>(t4 - t3).count();

        cout << "n = " << n << ", AVL: " << avl_time << " µs, Insertion: " << ins_time << " µs\n";
        if (avl_time < ins_time) {
            cout << "n₀ = " << n << " is the smallest where AVL is faster\n";
            break;
        }

        delete[] perm;
        delete[] avl_sorted;
        delete[] copy;
        n++;
    }
    return 0;
}
