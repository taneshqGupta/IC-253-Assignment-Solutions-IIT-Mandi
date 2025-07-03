#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n){
    int comparisons = 0, swaps = 0;
    for(int i=1; i<n; i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j] > key){
            comparisons++;
            swaps++;
            a[j+1] = a[j];
            j--;
        }
        if(j>=0) comparisons++;
        a[j+1] = key;

    }
    for(int i=0; i<n; i++)  cout << a[i] << ' ';
    cout << '\n';
    cout << "COMPARISONS: " << comparisons << '\n' << "SWAPS: " << swaps << '\n';
}

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    insertionSort(a, n);

    return 0;
}
