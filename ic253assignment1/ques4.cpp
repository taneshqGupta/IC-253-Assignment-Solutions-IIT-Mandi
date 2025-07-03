#include <iostream>
using namespace std;

const double pi = 3.141592653589793;
double calculateVolume(double r, double h){
    return pi*r*r*h;
}
double calculateSurfaceArea(double r, double h){
    return 2*pi*r*(r + h);
}
int main(){
    
    double a, b;
    cin >> a >> b;

    if(a<=0 || b<=0){
        cout << "invalid input. enter positive values only.";
        return -1;
    }
    else {
        cout << "Volume: " << calculateVolume(a, b) << '\n' << "Area: " << calculateSurfaceArea(a, b) << '\n';
    }

    return 0;
}
