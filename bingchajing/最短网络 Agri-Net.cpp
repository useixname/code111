#include<bits/stdc++.h>
using namespace std;
const int N=105;
int pre[N];
int n,m=0;

struct node{
    int u,v,w;
    bool operator<(const node & t) const{
        return w<t.w;
    }
}e[N*N];
int find(int x){
    if(pre[x]==x){
        return x;
    }
    else{
        return pre[x]=find(pre[x]);
    }
}

void init(){
    for(int i=1;i<=n;i++){
        pre[i]=i;
    }
}

void kruskal(){
    int cnt=0,sum=0;
    sort(e+1,e+m+1);
    for(int i=1;i<=m;i++){
        int px=find(e[i].u),py=find(e[i].v);
        if(px!=py){
            pre[px]=py;
            cnt++;
            sum+=e[i].w;
        }
        if(cnt==n-1){
            cout<<sum;
            break;
        }
    }
}

int main(){
    cin>>n;
    init();
    int x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            if(j>i){
                m++;
                e[m].u=i,e[m].v=j,e[m].w=x;
            }
        }
    }
    kruskal();
    return 0;
}