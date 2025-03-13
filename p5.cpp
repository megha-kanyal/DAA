#include <iostream>
#include <vector>
using namespace std;
int find(vector<int>& v, int target) {
    int low = 0;
    int high = v.size()-1;

    while (low <= high){
        int mid = low + (high-low) / 2;
        if (v[mid] == target) {
            return mid;
        }
        if (v[mid] >target) {
            high=mid - 1;
        } else {
            low=mid+ 1;
        }
    }
    return -1;
}
void Differences(vector<int>& v){
    for (int i = 0; i < v.size(); i++){
        for (int j = i + 1; j < v.size(); j++){
            int diff = abs(v[i] - v[j]); // Absolute difference
            int z = find(v, diff);
            if (z == -1){
                cout <<"Difference of "<<v[i]<<" and "<< v[j] 
                     <<" (index "<<i<<" and " << j << ") does not exist in the array."<< endl;
            }else{
                cout <<"Difference of "<<v[i]<< " and "<< v[j] 
                     <<"(index "<<i<<" and "<<j<< ") exists at index" <<z<<endl;
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter elements in sorted order: ";
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    Differences(v);
    return 0;
}
