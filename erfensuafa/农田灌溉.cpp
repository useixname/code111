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
        q.pop();//ȡ����ͷ
        //���������߽���ˮ
        if(t-1>=1&&!st[t-1]){
            q.push(t-1);
            d[t-1]=d[t]+1;
            st[t-1]=true;
            maxx=max(maxx,d[t-1]);
        }//ʱ��+1} 
        if(t+1<=n&&!st[t+1]){
            q.push(t+1);
            d[t+1]=d[t]+1;
            st[t+1]=true;
            maxx=max(maxx,d[t+1]);
        }
    }
    return maxx;//ȡ���ʱ����
}
int main(){
    cin>>t;
    while(t--){
        maxx=1;//����ʱ��Ϊ1
        memset(d,0,sizeof d);
        memset(st,0,sizeof st);
        cin>>n>>k;
        while(k--){
            int x;cin>>x;
            q.push(x);
            d[x]=1;//�Ƚ������Լ�
            st[x]=true;//��ʾ�Ѿ�����
        }
        cout<<bfs()<<endl;
    //   for(int i=1;i<=n;i++) cout<<d[i]<<" ";
    //   cout<<endl;
    }
    return 0;
}