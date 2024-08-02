#include<bits/stdc++.h>
using namespace std;

const int N=25;
int a[N],vis[N],ret[N];
int n,k,ans=0;

bool chk(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void dfs(int u,int sum,int last){
    if(u==k){
        if(chk(sum)){
            ans++;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]&&i>last){
            ret[u]=a[i];
            vis[i]=1;
            dfs(u+1,sum+a[i],i);
            vis[i]=0;
        }
    }
}


int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,0);
    cout<<ans;
}