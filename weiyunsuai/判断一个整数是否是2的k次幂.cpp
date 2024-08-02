#include<bits/stdc++.h>
using namespace std;

int n;

bool is_nk(int n){//判断一个整数是否是2的k次幂
    return n>0&&n&(n-1)==0;
}

int main(){
    cin>>n;
    cout<<is_nk(n)<<'\n';
    return 0;
}