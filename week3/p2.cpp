// selection sort
#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr, int &comparisons, int &swaps){
    int n = arr.size();
    comparisons = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; i++){
        int minIdx = i;
        for (int j = i + 1; j < n; j++){
            comparisons++;
            if (arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        if (minIdx != i){
            swap(arr[i], arr[minIdx]);
            swaps++;
        }
    }
}

int main(){
    int n;
    cout<<"enter n : ";
    cin >> n;
    vector<int> arr(n);
    cout<<"enter array elements : "<<endl;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int comparisons = 0, swaps = 0;
    selectionSort(arr, comparisons, swaps);
    for (int num : arr){
        cout << num << " ";
    }

    cout <<endl<< "comparisons = " << comparisons << endl;
    cout << "swaps = " << swaps << endl;
    return 0;
}
