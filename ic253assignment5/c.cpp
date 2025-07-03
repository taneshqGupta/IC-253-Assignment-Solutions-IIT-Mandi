#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    // Make HeapNode public
    struct HeapNode {
        int value;      // The value of the element
        int listIdx;    // Index of the list it belongs to
        int elemIdx;    // Index of the element in its list
    };

private:
    HeapNode* heapArr;  // Array to store heap elements
    int capacity;       // Maximum possible size of heap
    int heapSize;       // Current number of elements in heap

    // Helper function to maintain heap property
    void minHeapify(int idx) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < heapSize && heapArr[left].value < heapArr[smallest].value)
            smallest = left;
        if (right < heapSize && heapArr[right].value < heapArr[smallest].value)
            smallest = right;

        if (smallest != idx) {
            // Swap nodes
            HeapNode temp = heapArr[idx];
            heapArr[idx] = heapArr[smallest];
            heapArr[smallest] = temp;
            minHeapify(smallest);
        }
    }

public:
    // Constructor
    MinHeap(int cap) {
        heapSize = 0;
        capacity = cap;
        heapArr = new HeapNode[cap];
    }

    // Get the parent index
    int parent(int i) { return (i - 1) / 2; }

    // Insert a new element
    void insert(int value, int listIdx, int elemIdx) {
        if (heapSize == capacity) {
            cout << "Heap overflow\n";
            return;
        }

        // First insert at the end
        heapSize++;
        int i = heapSize - 1;
        heapArr[i] = {value, listIdx, elemIdx};

        // Fix the min heap property if violated
        while (i != 0 && heapArr[parent(i)].value > heapArr[i].value) {
            // Swap with parent
            HeapNode temp = heapArr[i];
            heapArr[i] = heapArr[parent(i)];
            heapArr[parent(i)] = temp;
            i = parent(i);
        }
    }

    // Get the minimum element
    HeapNode getMin() {
        if (heapSize <= 0) {
            cout << "Heap empty\n";
            return {INT_MAX, -1, -1};
        }
        return heapArr[0];
    }

    // Extract the minimum element
    HeapNode extractMin() {
        if (heapSize <= 0) {
            cout << "Heap empty\n";
            return {INT_MAX, -1, -1};
        }

        if (heapSize == 1) {
            heapSize--;
            return heapArr[0];
        }

        // Store the minimum value and remove it from heap
        HeapNode root = heapArr[0];
        heapArr[0] = heapArr[heapSize - 1];
        heapSize--;
        minHeapify(0);

        return root;
    }

    // Check if heap is empty
    bool isEmpty() {
        return heapSize == 0;
    }
};

// Function to merge k sorted arrays
int* mergeKSortedArrays(int** lists, int* listSizes, int k, int* mergedSize) {
    // Calculate total number of elements
    int totalElements = 0;
    for (int i = 0; i < k; i++) {
        totalElements += listSizes[i];
    }
    *mergedSize = totalElements;
    
    if (totalElements == 0) return nullptr;
    
    // Create result array
    int* result = new int[totalElements];
    int resultIndex = 0;
    
    // Create a min heap with capacity equal to number of lists
    MinHeap minHeap(k);
    
    // Push first element of each list into the heap
    for (int i = 0; i < k; i++) {
        if (listSizes[i] > 0) {
            minHeap.insert(lists[i][0], i, 0);
        }
    }
    
    // Extract elements from heap one by one
    while (!minHeap.isEmpty()) {
        MinHeap::HeapNode minNode = minHeap.extractMin();
        result[resultIndex++] = minNode.value;
        
        // If there are more elements in the same list, add next element to heap
        if (minNode.elemIdx + 1 < listSizes[minNode.listIdx]) {
            minHeap.insert(
                lists[minNode.listIdx][minNode.elemIdx + 1], 
                minNode.listIdx, 
                minNode.elemIdx + 1
            );
        }
    }
    
    return result;
}

int main() {
    // Example usage with raw arrays
    const int k = 3;
    int listSizes[k] = {4, 7, 5};
    
    // Create and initialize arrays
    int* lists[k];
    lists[0] = new int[4]{1, 4, 7, 190};
    lists[1] = new int[7]{2, 5, 8, 10, 99, 807, 121212};
    lists[2] = new int[5]{-1, 0, 3, 6, 9};
    
    int mergedSize;
    int* merged = mergeKSortedArrays(lists, listSizes, k, &mergedSize);
    
    cout << "Merged sorted array: ";
    for (int i = 0; i < mergedSize; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;
}
