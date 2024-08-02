#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
int vis[N],prim[N];
int n,cnt=0;

void get_prim(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            cout<<i<<" ";
            prim[++cnt]=i;
        }
        for(int j=i*i;j<=n;j+=i){
            vis[j]=1;
        }
    }
}

int main(){
    clock_t start,end;
    start=clock();
    cin>>n;
    get_prim(n);
    cout<<'\n'<<cnt;
    end=clock();
    cout <<endl<<"the time cost is:" << double(end - start) / CLOCKS_PER_SEC<<endl;
    return 0;
}