#include <iostream>
using namespace std;
int calculateArea(int a, int b){
    return a*b;
}
int calculatePerimeter(int a, int b){
    return 2*(a+b);
}
int main(){
    
    int a, b; 
    cin >> a >> b;
    if(a<=0 || b<=0){
        cout << "invalid input. enter positive values only." << '\n';
        return -1;
    } else {
        cout << "Perimeter: " << calculatePerimeter(a, b) << '\n';
        cout << "Area: " << calculateArea(a, b) << '\n';
    }







    return 0;
}
