#include<iostream>
#include<vector>
using namespace std;
int b_search(vector <int> v,int key){
    int low = 0;
    int high=v.size()-1;
    int mid;
    while(low<=high){
        mid = low + (high-low)/2;
        if(v[mid]==key){
            return mid;
        }
        if(v[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"enter total element of arr : ";
    cin>>n;
    vector<int> v;
    cout<<"enter elements of array ";
    for(int i=0;i<n;i++){
        int value;
        cin >> value;
        v.push_back(value); 
    }
    int key;
    cout<<"enter key : ";
    cin>>key;
    int index = b_search(v,key);
   if(index==-1){
    cout<<"not found";
   }else{
    cout<<"found in : "<<index<<" position"<<endl;
   }
    return 0;
}