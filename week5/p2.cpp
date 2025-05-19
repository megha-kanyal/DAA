#include <iostream>
#include <algorithm>

using namespace std;

bool hasPairWithSum(int arr[], int n, int key) {
    
    sort(arr, arr + n);
    
    int left = 0, right = n - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum == key) {
            return true; 
        } else if (sum < key) {
            left++; 
        } else {
            right--; 
        }
    }
    
    return false;
}

int main() {
    int arr[] = {1, 4, 45, 6, 10, 8};
    int key = 16;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (hasPairWithSum(arr, n, key)) {
        cout << "Pair with given sum exists" << endl;
    } else {
        cout << "No such pair found" << endl;
    }

    return 0;
}
