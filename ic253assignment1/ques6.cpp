#include <iostream> 
#include <cstring>
using namespace std;

int main() {

    char str[10000];
    int i=0;
    char ch;

    while(cin.get(ch) && ch != '\n'){
        str[i++] = ch;
    }
    str[i] = '\0';
    cout << "the length of the given string is: " << i << '\n';
    
    char reverse_str[10000];
    for(int x=0; x<i; x++){
        reverse_str[x] = str[i-x-1];
    }
    reverse_str[i] = '\0';

    cout << "the reverse of the given string is: " << reverse_str << '\n';
    
    if(strcmp(reverse_str, str) == 0) cout << "given string is a palindrome." << '\n';
    else cout << "given string is not a palindrome." << '\n';

    return 0;

}
