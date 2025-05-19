#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countPairsWithDifferenceK(vector<int>& arr, int K) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int i = 0, j = 1;
    int count = 0;

    while (j < n && i < n) {
        int diff = arr[j] - arr[i];
        if (diff == K) {
            count++;
            i++;
            j++;
        } else if (diff < K) {
            j++;
        } else {
            i++;
            if (i == j) {
                j++;
            }
        }
    }

    return count;
}

int main() {
    int T; 
    cout<<"enter t : ";
    cin >> T;
    while (T--) {
        int n; 
        cout<<"enter n : ";
        cin >> n;
        vector<int> arr(n);
        cout<<"enter array elements : ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int K; 
        cout<<"enter k : ";
        cin >> K;

        cout << countPairsWithDifferenceK(arr, K) << "\n";
    }
    return 0;
}
