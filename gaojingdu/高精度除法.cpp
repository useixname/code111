#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int A[N],C[N];
int b,la,lc;


void div(int A[],int b,int C[]){
    long long r=0;
    for(int i=la-1;i>=0;i--){
        r=r*10+A[i];
        C[la-1-i]=r/b;
        int t=C[la-1-i];
        r%=b;
    }
    reverse(C,C+lc);
    while(lc&&C[lc]==0) lc--;
    for(int i=lc;i>=0;i--){
        cout<<C[i];
    }
}

int main(){
    string a;
    cin>>a>>b;
    lc=la=a.size();
    for(int i=la-1;i>=0;i--){
        A[la-i-1]=a[i]-'0';
    }
    div(A,b,C);
    return 0;
}