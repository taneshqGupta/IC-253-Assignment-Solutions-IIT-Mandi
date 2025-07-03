#include <bits/stdc++.h>
using namespace std;
#define num long long
#define nl '\n'
#define all(x) (x).begin(), (x).end()

int gcd(int a, int b){
    while(a!=0){
        int temp = a;
        a = b%a;
        b = temp;
    }
    return b;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    while(true){
        cin >> a >> b;
        if(a>0 && b>0) break;
        else cout << "negative input. try again." << '\n'; 
    }

    cout << "the gcd of " << a << " and " << b << " is " << gcd(a, b) << '\n';


    return 0; 

}

