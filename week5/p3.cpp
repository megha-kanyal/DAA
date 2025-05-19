#include <iostream>
#include <vector>

using namespace std;

vector<int> findCommonElements(int arr1[], int m, int arr2[], int n) {
    vector<int> commonElements;
    int i = 0, j = 0;
    
    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) { 
            commonElements.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    return commonElements;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {3, 4, 5, 7, 8};

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    vector<int> common = findCommonElements(arr1, m, arr2, n);

    cout << "Common Elements: ";
    for (int num : common) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
