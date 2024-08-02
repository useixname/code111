#include<bits/stdc++.h>
using namespace std;

const int N=1e2+10;
int n;
int a[N];

int bs(int *nums,int l,int r){
    while(l<=r){
        int mid=(l+r)>>1;
        if(nums[mid]>mid){
            r=mid-1;
        }
        else if(nums[mid]<mid){
            l=mid+1;
        }
        else{
            return nums[mid];
        }
    }
    return -1;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<bs(a,0,n-1);
}