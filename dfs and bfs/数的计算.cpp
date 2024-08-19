#include<bits/stdc++.h>//万能头文件
using namespace std;
int n;
int f[1001];//存每一位数的种类
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){ //1-n的递推
        for(int j=1;j<=i/2;j++){
            f[i]+=f[j]; //每一位叠加，递推走起
        }
        f[i]++; //加上本身
    }
    cout<<f[n];//输出n的种类
    return 0;
}

// #include <cstdio>
// #include <iostream>
// using namespace std;
// long long dfs(int x) //深搜
// {
//  if(x==1) return 1;
//  long long tot=1; //加上自身，所以初始化是 1 
//  for(int i=1;i<=x/2;i++) //列举 
//  	tot+=dfs(i);
//  return tot;
// }
// int main()
// {
//  cout<<"a[1001]={";  //便于直接复制 
//  for(int i=1;i<=1000;i++) //枚举所有数 
//  {
//  	cout<<dfs(i)<<",";
//  }
//  cout<<"}";
// }