#include<bits/stdc++.h>
using namespace std;

int a[1010][1010],f[1010][1010];
int n,ans=0;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1){
                f[i][j]=f[i-1][j]+a[i][j];
            }
            else if(j==i){
                f[i][j]=f[i-1][j-1]+a[i][j];
            }
            else{
                f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,f[n][i]);
    }
    cout<<ans;
    return 0;
}