#include<cstdio>
#include<iostream>
using namespace std;

const int N=1e5+10;
int n,k,a[N],q[N]={0},h=1,t=0,q1[N],h1=1,t1=0;

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        while(t>=h&&a[q[t]]>=a[i]){
            t--;
        }
        q[++t]=i;
        if(q[h]<i-k+1){
            h++;
        }
        if(i>=k){
            printf("%d ",a[q[h]]);
        }
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        while(t1>=h1&&a[q1[t1]]<=a[i]){
            t1--;
        }
        q1[++t1]=i;
        if(q1[h1]<i-k+1){
            h1++;
        }
        if(i>=k){
            printf("%d ",a[q1[h1]]);
        }
    }
    return 0;
}