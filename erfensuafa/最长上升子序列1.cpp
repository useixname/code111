#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N];
int n;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[n-i-1];
    }
    int len=0;
    b[len]=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>b[len]){
            b[++len]=a[i];
        }
        else{
            int pos=upper_bound(b,b+len,a[i])-b;
            b[pos]=a[i];
        }
    }
    cout<<len+1;
    return 0;
}