#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+10;
int a[N];
int bs(int *nums,int l,int r,int target){
    while(l<=r){
        int mid=(l+r)>>1;
        if(nums[mid]>=target){//�ҵ���һ�����ڵ���target�������±�;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return l;//�ҵ���һ�����ڵ���target�������±�;
}

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<bs(a,1,n,k);
}