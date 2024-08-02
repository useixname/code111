#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
int vis[N],prim[N];
int n,m,cnt=0;

void get_prim(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            prim[++cnt]=i;
        }
        for(int j=1;1ll*i*prim[j]<=n;j++){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0){
                break;
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    clock_t start,end;
    start=clock();
    cin>>n>>m;
    get_prim(n);
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        cout<<prim[k]<<'\n';
    }
    end=clock();
    cout <<endl<<"the time cost is:" << double(end - start) / CLOCKS_PER_SEC<<endl;
    return 0;
}