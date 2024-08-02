#include<bits/stdc++.h>
using namespace std;

#define N 1010
struct node{
    int u,v,w;
    bool operator<(const node &t) const{
        return w<t.w;
    }
}e[N*10];
int n,m,pre[N],ans=0,cnt=0;
int find(int x){
    if(pre[x]==x){
        return x;
    }
    return pre[x]==find(pre[x]);
}

void init(){
    for(int i=1;i<=n;i++){
        pre[i]=i;
    }
}

bool join(int x,int y){
    int px=find(x),py=find(y);
    if(px!=py){
        pre[px]=py;
        return true;
    }
    return false;
}
bool kruskal(){
    sort(e,e+m);
    for(int i=0;i<m;i++){
        if(join(e[i].u,e[i].v)){
            ans+=e[i].w;
            cnt++;
        }
    }
    return cnt==n-1;
}

int main(){
    cin>>n>>m;
    init();
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    if(!kruskal()){
        cout<<"orz";
    }
    cout<<ans;
    return 0;
}