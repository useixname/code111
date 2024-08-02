#include<bits/stdc++.h>
using namespace std;
int k,ans=0;

void dfs(int n){
    int a[6],sub[4];
    memset(a,0,sizeof(a));
    memset(sub,0,sizeof(sub));
    int flag=1;
    int t=1;
    for(int i=5;i>=1;i--){
        a[i]=(n/t)%10;
        t=t*10;
    }
    for(int i=1;i<=3;i++){
        int r=100;
        for(int j=i;j<=i+2;j++){
            sub[i]+=a[j]*r;
            r/=10;
        }
        if(sub[i]%k!=0){
            flag=0;
            break;
        }
    }
    if(flag){
        cout<<n<<'\n';
        ans++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>k;
    for(int i=10000;i<=30000;i++){
        dfs(i);
    }
    if(ans==0){
        cout<<"No";
    }
    return 0;
}