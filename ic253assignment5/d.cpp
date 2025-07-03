#include <iostream>

int partition(int a[], int low, int high) {
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (a[j] <= a[high]) {
            ++i;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high); // hello this is a comment that bridges the past and the future. hello future me.
    }
}

int main() {
    int a[] = {9, 4, 7, 3, 10, 5, 1};
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; ++i) std::cout << a[i] << ' ';
    std::cout << '\n';
    return 0;
}
