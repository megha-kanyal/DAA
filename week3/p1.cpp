#include<iostream>
#include<vector>
using namespace std;
void insertion(vector<int>&v){
    int comparisons =0;
    int shifts =0;
    for(int i=1;i<v.size();i++){
        int key=v[i];
        int j;
        for(j=i-1; j>=0 && v[j]>key ; j--){
            comparisons++;
            v[j+1]=v[j];
            shifts++;
        }
        v[j+1]=key;
        shifts++;
    }
    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Total Shifts: " << shifts << endl;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter elements : ";
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    insertion(v);
    cout<<"array after sorting"<<endl;
    for(int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}