#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],b[N];
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int i=1,j=1;
    while(i<=n){
        while(a[i]!=b[j-1]){
            b[j]=a[i],j++,i++;
            if(i>=n) break;
        }
        while(a[i]==b[j-1]){
            i++;
            if(i>=n) break;
        }
    }
    cout<<j-1<<'\n';
    for(int i=1;i<=j-1;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}