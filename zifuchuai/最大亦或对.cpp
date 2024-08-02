#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int a[N],tr[N*4][2],cnt[N],idx;

void insert(int x){
    int p=0;
    for(int i=30;i>=0;i--){
        int j=x>>i&1;
        if(!tr[p][j]){
            tr[p][j]=++idx;
        }
        p=tr[p][j];
    }
}

int query(int x){
    int ret=0;
    int p=0;
    for(int i=30;i>=0;i--){
        int j=x>>i&1;
        if(tr[p][!j]){
            ret+=1<<i;
            p=tr[p][!j];
        }
        else{
            p=tr[p][j];
        }
    }
    return ret;
}

int main(){
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        insert(a[i]);
    }
    for(int i=0;i<n;i++){
        ans=max(ans,query(a[i]));
    }
    cout<<ans;
    return 0;
}