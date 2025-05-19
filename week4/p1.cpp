#include <iostream>
#include <vector>
using namespace std;

long long comparisons = 0;
long long inversions = 0;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++; 
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inversions += (n1 - i);
        }
    }
    while (i < n1){
        arr[k++] = L[i++];
    } 
    while(j < n2){
        arr[k++] = R[j++];
    } 
}
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
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
        for (int i = 0; i < n; i++) cin >> arr[i];

        comparisons = 0;
        inversions = 0;

        mergeSort(arr, 0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << arr[i];
            if (i < n - 1) {
                cout << " ";
            }
        }
        cout <<endl<<"comparisons = " << comparisons <<endl;
        cout <<"inversions = " << inversions <<endl;
    }
    return 0;
}
