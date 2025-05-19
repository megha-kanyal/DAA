#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,key;
    int found=0;
    int count=0;
    cout<<"enter n : ";
    cin>>n;
    cout<<"enter elements : ";
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"enter key ";
    cin>>key;
    for(int i=0;i<v.size();i++){
        if(key==v[i]){
            found=1;
            cout<<"element found at "<<i+1<<" position"<<endl;
            cout<<"comparision done : "<<count<<endl;
        }
        count++;
    }
    if(found==0){
        cout<<"comparision done : "<<count<<endl;
        cout<<"not found";
    }
    return 0;
}