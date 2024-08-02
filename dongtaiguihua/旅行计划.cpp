#include<bits/stdc++.h>
using namespace std;

int f[100010];
vector<int>E[100010];
int n,m;

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        E[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        f[i]=1;
        for(int j=0;j<E[i].size();j++){
            f[i]=max(f[i],f[E[i][j]]+1);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<f[i]<<'\n';
    }
    return 0;
}