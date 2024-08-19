#include<bits/stdc++.h>
using namespace std;
int n;
int a[210],dpmax[210][210];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int len=3;len<=n+1;len++){
        for(int l=1;l+len-1<=2*n;l++){
            int r=l+len-1;
            for(int k=l+1;k<r;k++){
                dpmax[l][r]=max(dpmax[l][k]+dpmax[k][r]+a[l]*a[k]*a[r],dpmax[l][r]);
            }
        }
    }
    int ansmax=0;
    for(int i=1;i<=n;i++){
        ansmax=max(dpmax[i][i+n],ansmax);
    }
    cout<<ansmax;
    return 0;
}