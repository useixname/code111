/*
5
1 3 3 3 6   ��С��ȡֵ��ȡ����;
1 2 3 3 4
̰�ģ�Ҫʹb���龡��������.����b����Ҫ��1��ʼ.
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