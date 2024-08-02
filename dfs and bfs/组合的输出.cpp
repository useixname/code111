#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
int vis[25],ret[25];
int n,m;

void dfs(int step,int front){
    if(step==m+1){
        for(int i=1;i<=m;i++){
            cout << setw(3) << ret[i];
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]&&i>front){
            vis[i]=1;
            ret[step]=i;
            dfs(step+1,ret[step]);
            vis[i]=0;
        }
    }
}

int main(){
    cin>>n>>m;
    dfs(1,0);
    return 0;
}