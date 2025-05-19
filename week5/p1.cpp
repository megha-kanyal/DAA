#include <iostream>
using namespace std;

char findMaxOccurringChar(string str) {
    int count[26] = {0};

 
    for (char ch : str) {
        count[ch - 'a']++; 
    }

    int maxCount = 0;
    char maxChar;
    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            maxChar = 'a' + i;
        }
    }

    return maxChar;
}

int main() {
    string input;
    cout << "Enter a string in lowercase letters: ";
    cin >> input;

    char maxChar = findMaxOccurringChar(input);
    cout << "The maximum occurring character is: " << maxChar << endl;

    return 0;
}
