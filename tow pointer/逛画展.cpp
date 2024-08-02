#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
int a[N],cnt[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int i=1,j=1,num=1,len=N,l,r;
    cnt[a[i]]=1;
    while(j<=n){
        if(num<m){
            j++;
            if(cnt[a[j]]==0){
                num++;
            }
            cnt[a[j]]++;
        }
        if(num==m){
            if(len>j-i+1){
                len=j-i+1;
                l=i,r=j;
            }
            cnt[a[i]]--;
            if(cnt[a[i]]==0) num--;
            i++;
        }
    }
    cout<<l<<" "<<r;
    return 0;
}