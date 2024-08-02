/*
5
1 3 3 3 6   最小的取值中取最大的;
1 2 3 3 4
贪心：要使b数组尽可能连续.并且b数组要从1开始.
2 3
1 2
*/
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N],b[N];
int n;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    b[1]=1;
    for(int i=2;i<=n;i++){
        if(b[i-1]+1<=a[i]){
            b[i]=b[i-1]+1;
        }
        else{
            b[i]=b[i-1];
        }
    }
    cout<<b[n]+1;
}