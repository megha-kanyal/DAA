#include <iostream>
#include <vector>
using namespace std;

bool findTriplet(const vector<int>& arr, int& i_out, int& j_out, int& k_out) {
    int n = arr.size();
    for (int k = n - 1; k >= 2; --k) {
        int i = 0;
        int j = k - 1;
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == arr[k]) {
                i_out = i;
                j_out = j;
                k_out = k;
                return true;
            } else if (sum < arr[k]) {
                ++i;
            } else {
                --j;
            }
        }
    }
    return false;
}

int main() {
    int T;
    cout<<"enter total test cases : ";
    cin >> T;
    while (T--) {
        int n;
        cout<<"enter n ";
        cin >> n;
        vector<int> arr(n);
        cout<<"enter elements in sorted order : "<<endl;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int i, j, k;
        if (findTriplet(arr, i, j, k)) {
            cout << i << ", " << j << ", " << k << endl;
        } else {
            cout << "No sequence found." << endl;
        }
    }
    return 0;
}
