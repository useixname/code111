#include<bits/stdc++.h>
using namespace std;

int n;


bool is_power_of_two(int n){//�ж�һ�������Ƿ���2��k����
    return n>0 && (n & (n-1))==0;
}

int QuFan(int n){//-x=(~x+1)
    return ~n;
}

int add(int x,int y){//���üӷ�ʵ�ּӷ�
    return x-(~y+1);
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    cout<<is_power_of_two(n)<<'\n';
    cout<<QuFan(n)<<'\n';
}