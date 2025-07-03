#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    const static int MAX_SIZE = 100;
    int heap[MAX_SIZE];
    int size;

public:

    MaxHeap(int a[], int n) {
        size = n;
        for (int i = 0; i < n; i++) {
            heap[i] = a[i];
        }
        buildHeap();    
    }

    void MaxHeapify(int i) {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < size && heap[l] > heap[largest]) {
            largest = l;
        }
        if (r < size && heap[r] > heap[largest]) {
            largest = r;
        }

        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];    
            heap[largest] = temp;
            MaxHeapify(largest);
        }
    }

    void buildHeap() {
        for (int i = size/2 - 1; i >= 0; i--) {
            MaxHeapify(i);
        }
    }

    int getMax() {
        if (size >= 1) {
            return heap[0];
        } else {
            return INT_MIN;
        }
    }

    int extractMax() {
        if (size <= 0) {
            return INT_MIN;
        }
        if (size == 1) {
            size--;
            return heap[0];
        }

        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        MaxHeapify(0);

        return root;
    }

    int currentSize() {
        return size;
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << '\n';
    }

    void increaseKey(int i, int increment) {
        if (i >= size) return;
        heap[i] += increment;
        while(i != 0 && heap[(i-1)/2] < heap[i]) {
            int temp = heap[i];
            heap[i] = heap[(i-1)/2];
            heap[(i-1)/2] = temp;
            i = (i-1)/2;
        }
    }

    void insert(int val) {
        if(size == MAX_SIZE) return;

        int i = size;
        heap[size++] = val;
        while(i != 0 && heap[i] > heap[(i-1)/2]) {
            int temp = heap[i];
            heap[i] = heap[(i-1)/2];
            heap[(i-1)/2] = temp;
            i = (i-1)/2;
        }
    }

};

int main() {
    int input[] = {3, 5, 9, 6, 8, 20, 10, 12, 18};
    int n = sizeof(input)/sizeof(input[0]);
    MaxHeap mango(input, n);
    cout << "Max Heap: ";
    mango.printHeap();
    cout << "Current Size: " << mango.currentSize() << '\n';
    cout << "MAX: " << mango.getMax() << '\n';
    cout << "Extracted Max: " << mango.extractMax() << '\n';
    cout << "New Max: " << mango.getMax() << '\n';
    cout << "Current Size: " << mango.currentSize() << '\n';
    cout << "Max Heap after extraction: ";
    mango.printHeap();

    mango.increaseKey(4, 50);
    cout << "After increasing index 4 to 50: ";
    mango.printHeap();

    mango.insert(60);
    cout << "After inserting 60: ";
    mango.printHeap();

    return 0;
}