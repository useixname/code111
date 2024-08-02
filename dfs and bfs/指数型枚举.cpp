#include<bits/stdc++.h>
using namespace std;

const int N=20;
bool vis[N];
int n;

void dfs(int u){
    if(u>n){
        for(int i=1;i<=n;i++){
            if(vis[i]){
                cout<<i<<" ";
            }
        }
        cout<<endl;
        return;
    }
    vis[u]=true;
    dfs(u+1);
    vis[u]=false;
    dfs(u+1);
}

int main(){
    cin>>n;
    dfs(1);
}