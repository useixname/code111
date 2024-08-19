#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int pre[N];
int n,m,k;

int find(int x){
    return pre[x]==x?x:(pre[x]=find(pre[x]));
}

void init(){
    for(int i=1;i<=N;i++){
        pre[i]=i;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    init();
    cin>>n>>m>>k;
    while(m--){
        int x,y;
        cin>>x>>y;
        int px=find(x),py=find(y);
        pre[py]=px;
    }
    while(k--){
        int x,y;
        cin>>x>>y;
        int px=find(x),py=find(y);
        if(px!=py){
            cout<<"No"<<'\n';
        }
        else{
            cout<<"Yes"<<'\n';
        }
    }
    return 0;
}