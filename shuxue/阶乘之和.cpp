#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=150;
int a[N],b[N];

void add(int a[],int b[]){
    int w=0;
    for(int i=1;i<=N;i++){
        b[i]=b[i]+a[i]+w;
        w=b[i]/10;
        b[i]%=10;
    }
}
void mul(int a[],int b){
    int w=0;
    for(int i=1;i<=N;i++){
        a[i]=a[i]*b+w;
        w=a[i]/10;
        a[i]%=10;
    }
}
int main(){
    int n;
    cin>>n;
    a[1]=1;
    for(int i=1;i<=n;i++){
        mul(a,i);
        add(a,b);
    }
    bool flag=0;
    for(int i=N;i>=1;i--){
        if(b[i]!=0) flag=1;
        if(flag) cout<<b[i];
    }
    return 0;
}