#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>v,int ele){
    int low=0;
    int high = v.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]==ele){
            return mid;
        }
        if(v[mid]<ele){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
 
int lower(vector<int>v,int ele){  //lower bound is greater than or equal to //upper bound is greater than
    int low=0;
    int high=v.size()-1;
    int ans=-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]>=ele){
            ans = mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans==-1? v.size() : ans;
}

int upper(vector<int>v,int ele){
    int low=0;
    int high=v.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]>ele){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans == -1 ? v.size() : ans; 
}
int main(){
    int n;
    cout<<"enter size of array : ";
    cin>>n;
    vector<int>v(n);
    cout<<"enter elements in a sorted order : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ele;
    cout<<"enter element to be searched : ";
    cin>>ele;
    int found=search(v,ele);
    if(found==-1){
        cout<<"element not found ";
    }
    else{
        int lb = lower(v,ele);
        cout<<"lb : "<<lb;
        int up = upper(v,ele);
        cout<<"up : "<<up<<endl;;
        int copies = up-lb;
        cout<<"element "<<ele<<" present "<<copies<<" times.";
    }
    return 0;
    
}