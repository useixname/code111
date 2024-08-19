#include<bits/stdc++.h>
using namespace std;
int a[13];
int s=0,t=0,flag=1;
int main(){
    ios_base::sync_with_stdio(0);
    for(int i=1;i<=12;i++){
        cin>>a[i];
    }
    for(int i=1;i<=12;i++){
        s+=300;
        s-=a[i];
        if(s<0){
            flag=0;
            cout<<-i;
            break;
        }
        int x=s/100;
        if(x>0) t+=100*x,s-=100*x;
    }
    if(flag){
        double ans=s+t*1.2;
        printf("%.0f",ans);
    }
    return 0;
}