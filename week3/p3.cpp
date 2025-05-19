#include <iostream>
#include <algorithm>
using namespace std;

bool hasDuplicates(int arr[], int n) {
    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return true; 
        }
    }

    return false;
}

int main() {
    int arr[] = {7, 3, 2, 5, 4, 3, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (hasDuplicates(arr, n))
        cout << "Duplicate elements found.\n";
    else
        cout << "No duplicate elements.\n";

    return 0;
}
