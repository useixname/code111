#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e6;
int a[N],cnt;
long long ans;
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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=N;i++){
        int cost=i*(n-bs(a,1,n,i)+1);
        if(cost>ans){
            ans=cost;
            cnt=i;
        }
    }
    cout<<ans<<" "<<cnt;
}