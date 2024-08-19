#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int s[N],vis[N],prim[N];
int cnt=0;
int n,m;

void get_prim(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            s[i]++;
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
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    get_prim(m);
    for(int i=1;i<=m;i++){
        s[i]+=s[i-1];
    }
    while(n--){
        int l,r;
        cin>>l>>r;
        if(r>m||l<=0) cout<<"Crossing the line"<<'\n';
        else{
            cout<<s[r]-s[l-1]<<'\n';
        }
    }
    return 0;
}