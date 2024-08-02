#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int t;
int maxx;
int n,k;
const int N=400;
int d[N],st[N];
queue<int> q;
int bfs(){
    while(q.size()){
        int t=q.front();
        q.pop();//取出队头
        //往左右两边浇灌水
        if(t-1>=1&&!st[t-1]){
            q.push(t-1);
            d[t-1]=d[t]+1;
            st[t-1]=true;
            maxx=max(maxx,d[t-1]);
        }//时间+1} 
        if(t+1<=n&&!st[t+1]){
            q.push(t+1);
            d[t+1]=d[t]+1;
            st[t+1]=true;
            maxx=max(maxx,d[t+1]);
        }
    }
    return maxx;//取最大时间数
}
int main(){
    cin>>t;
    while(t--){
        maxx=1;//自身时间为1
        memset(d,0,sizeof d);
        memset(st,0,sizeof st);
        cin>>n>>k;
        while(k--){
            int x;cin>>x;
            q.push(x);
            d[x]=1;//先浇灌它自己
            st[x]=true;//表示已经交过
        }
        cout<<bfs()<<endl;
    //   for(int i=1;i<=n;i++) cout<<d[i]<<" ";
    //   cout<<endl;
    }
    return 0;
}