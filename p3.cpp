#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    vector<int>arr {3,4,6,7,10,11,12,13,14,18,19,20};
    int n=12;
    int key = 18;
    int exp =0;
    int i =0;
    int prev ;
    while(arr[exp]<key && exp<n){
        prev=exp;
        exp=pow(2,i);
        if(arr[exp]==key){
            cout<<"found";
            return 0;
        }
        i++;
    }
    if(exp>n-1){
        exp=n-1;
    }
    for(int i=prev;i<=exp;i++){
        if(arr[i]==key){
          cout<<"key found in "<<i+1<<" position";
          return 0;   
        }
    }
    cout<<"not found";

    return 0;
}