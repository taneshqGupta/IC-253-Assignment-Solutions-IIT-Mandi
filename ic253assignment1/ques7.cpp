#include <iostream>
using namespace std;

int main() {
    char str[10000];
    int t = 0;
    char ch;

    // Read input sentence as a char array
    while (cin.get(ch) && ch != '\n') {
        str[t++] = ch;
    }
    str[t] = '\0';

    cout << "given sentence as a char array is: " << str << '\n';

    // Splitting logic
    char split_array[1000][100]; // Assume max 1000 words, each up to 99 chars
    int word_count = 0, i = 0, j = 0;
    bool in_word = false;

    for (int x = 0; x < t; x++) {
        if (str[x] == ' ') {
            if (in_word) {  
                split_array[i][j] = '\0'; // Null-terminate the word
                i++;
                j = 0;
                word_count++;
                in_word = false;
            }
        } else {
            split_array[i][j++] = str[x];
            in_word = true;
        }
    }

    // Null-terminate the last word
    if (in_word) {
        split_array[i][j] = '\0';
        word_count++;
        in_word = false;
    }

    // Print the words
    cout << "given sentence as a split array is: " << '\n';
    for (int c = 0; c < word_count; c++) {
        cout << split_array[c] << '\n';
    }

    return 0;
}

