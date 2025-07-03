#include <iostream>
using namespace std;
int a[10000] = {0, 1};
void generateFibonacci(int n){
    for(int i=2; i<n; i++){
        a[i] = a[i-1] + a[i-2];
    }
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    cout << '\n';
}
int main(){
    int n;
    cin >> n;
    if(n<=0){
        cout << "invalid input. enter positive numbers only" << '\n';
        return -1;
    }
    else {
        generateFibonacci(n);
    }



    return 0;
}
