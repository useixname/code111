#include<bits/stdc++.h>
using namespace std;

const int N=35;
int a[N],vis[N];
int n,m;

void dfs(int u){
    if(u>=m){
        for(int i=0;i<m;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]&&(!u||i>a[u-1])){
            vis[i]=1;
            a[u]=i;
            dfs(u+1);
            vis[i]=0;
        }
    }
}

int main(){
    cin>>n>>m;
    dfs(0);
}