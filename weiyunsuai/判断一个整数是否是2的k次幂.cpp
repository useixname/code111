#include<bits/stdc++.h>
using namespace std;

int n;

bool is_nk(int n){//�ж�һ�������Ƿ���2��k����
    return n>0&&n&(n-1)==0;
}

int main(){
    cin>>n;
    cout<<is_nk(n)<<'\n';
    return 0;
}