#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
int n,m,pre[N];

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

int kruskal(){
    int cnt=0;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        int px=find(x),py=find(y);
        if(px!=py){
            pre[px]=py;
            cnt++;
        }
    }
    return n-cnt-1<=0?0:n-cnt-1;
}

int main(){
    cin>>n;
    cin>>m;
    while(1){
        init();
        cout<<kruskal()<<'\n';
        cin>>n;
        if(n==0){
            break;
        }
        cin>>m;
    }
    return 0;
}