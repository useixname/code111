#include<bits/stdc++.h>
using namespace std;

int n,m;
int pre[100010];

struct node{
    int u,v,t;
}a[100010];

bool cmp(const node & x,const node & y){
    return x.t<y.t;
}

int find(int x)
{
	return pre[x]==x?x:(pre[x]=find(pre[x]));
}

bool join(int x,int y){
    int pa=find(x),pb=find(y);
    if(pa!=pb){
        pre[pa]=pb;
        return true;
    }
    return false;
}
void init(){
    for(int i=1;i<=n;i++){
        pre[i]=i;
    }
}
int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].t;
    }
    sort(a+1,a+1+m,cmp);
    int ans=1;
    for(int i=1;i<=m;i++){
        bool flag=join(a[i].u,a[i].v);
        if(flag){
            ans++;
        }
        if(ans==n){
            cout<<a[i].t;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}