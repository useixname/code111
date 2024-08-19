#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int a[N],q[N];
int n,m,ans;

int main(){
    ios_base::sync_with_stdio(0);
    memset(a,0x3f3f3f3f,sizeof(a));
    cin>>n>>m;
    for(int i=m;i<=m+n-1;i++){
        cin>>a[i];
    }
    printf("%d\n",0);
    int t=0,h=1;
    for(int i=1;i<=m+n-2;i++){
        while(t>=h&&a[q[t]]>=a[i]){ 
            t--;
        }
        q[++t]=i;
        if(q[h]<i-m+1){
            h++;
        }
        if(i>=m){
            printf("%d\n",a[q[h]]);
        }
    }
    return 0;
}