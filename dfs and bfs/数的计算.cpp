#include<bits/stdc++.h>//����ͷ�ļ�
using namespace std;
int n;
int f[1001];//��ÿһλ��������
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){ //1-n�ĵ���
        for(int j=1;j<=i/2;j++){
            f[i]+=f[j]; //ÿһλ���ӣ���������
        }
        f[i]++; //���ϱ���
    }
    cout<<f[n];//���n������
    return 0;
}

// #include <cstdio>
// #include <iostream>
// using namespace std;
// long long dfs(int x) //����
// {
//  if(x==1) return 1;
//  long long tot=1; //�����������Գ�ʼ���� 1 
//  for(int i=1;i<=x/2;i++) //�о� 
//  	tot+=dfs(i);
//  return tot;
// }
// int main()
// {
//  cout<<"a[1001]={";  //����ֱ�Ӹ��� 
//  for(int i=1;i<=1000;i++) //ö�������� 
//  {
//  	cout<<dfs(i)<<",";
//  }
//  cout<<"}";
// }