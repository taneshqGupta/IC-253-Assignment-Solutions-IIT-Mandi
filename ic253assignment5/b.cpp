#include <bits/stdc++.h>
using namespace std;

void heap_sort(int a[], int size) {

    function<void(int[], int, int)> maxHeapify = [&](int arr[], int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[largest] < arr[l]) largest = l;
        if (r < n && arr[largest] < arr[r]) largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(arr, n, largest);
        }
    };

    function<void(int[], int)> buildHeap = [&](int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeapify(arr, n, i);
        }
    };

    buildHeap(a, size);

    for (int i = size - 1; i > 0; i--) {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}

int main() {
    int a[] = {0, 3, 4, 5, -2, -232323, -5, 0, 1, 1, 1, 1, 2, 3, 3, 2, 6, 1000000, 1, 6};
    int size = sizeof(a) / sizeof(a[0]);
    heap_sort(a, size);
    for (auto c : a) cout << c << ' ';
    cout << '\n';
}